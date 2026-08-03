# Memory Map Analysis

This document details the low-level memory layout, lifetime behaviors, and pointer aliasing analysis for the target C programs as part of Task 0.

---

## Program 1: Stack Memory & Lifetime Analysis (`stack_example.c`)

### Execution Trace & Memory Layout

#### 1. Frame Entry (`main`)
* **Stack State**: `main()` stack frame created.
* **Local Variables**: `int x = 10`, `int *ptr = NULL`.

#### 2. Function Call (`get_dangling_pointer`)
* **Stack State**: A new stack frame for `get_dangling_pointer()` is pushed above `main()`.
* **Local Allocation**: `int temp = 42;` is allocated within `get_dangling_pointer`'s stack frame.
* **Return State**: The function returns `&temp` (the memory address of `temp`).

#### 3. Frame Destruction & Dangling Pointer Access
* **Frame Pop**: `get_dangling_pointer()` stack frame is popped off the call stack. The space occupied by `temp` is marked as unallocated/deallocated.
* **Aliasing/Assignment**: In `main()`, `ptr` holds the address where `temp` previously resided.
* **Undefined Behavior**: Dereferencing `*ptr` attempts to read an invalidated stack frame area.

### Memory Map Representation

---

## Program 2: Pointer Aliasing & Ownership Tracking (`aliasing_example.c`)

### Execution Trace & Memory Layout

#### 1. Heap Allocation
* A memory block of size `sizeof(int)` (4 bytes) is allocated on the **Heap** via `malloc()`.
* Memory address returned: `0x5555555592a0`.

#### 2. Alias Creation
* Pointer `p1` is assigned to point to `0x5555555592a0`.
* `p2` is assigned to `p1` (`int *p2 = p1;`).
* Both `p1` and `p2` share identical address values and alias the exact same heap memory location.

#### 3. Deallocation & Double Free Hazard
* `free(p1);` is executed. The heap block at `0x5555555592a0` is deallocated.
* `p1` and `p2` both remain holding `0x5555555592a0` (dangling heap references).
* Calling `free(p2)` results in a **Double Free** critical bug, as `p2` attempts to deallocate memory that was already returned to the OS memory manager.

### Ownership Matrix

| Pointer | Location | Points To | Value at Address | Lifetime / Ownership |
| :--- | :--- | :--- | :--- | :--- |
| `p1` | Stack | `0x5555555592a0` (Heap) | Undefined (Post-free) | Owner (Responsible for freeing) |
| `p2` | Stack | `0x5555555592a0` (Heap) | Undefined (Post-free) | Alias (Must NOT free after `p1`) |

---

## Critical AI Explanation Audit & Correction

### AI Initial Hypothesis (Incorrect)
> *"The function `get_dangling_pointer` returns a pointer to `temp`. Since C passes values by reference when using pointers, `*ptr` in `main()` will always retain the value `42` safely until the program terminates because `temp` lives in local stack memory."*

### Reasoning & Correction

1. **Incorrect Assumption about Lifetime**:
   * The AI assumed that memory allocated on the stack remains persistent after function exit. Stack allocation is scoped strictly to the function's execution lifetime. 
2. **Failure to Recognize Undefined Behavior (UB)**:
   * When `get_dangling_pointer()` returns, its stack frame is invalidated. Accessing `*ptr` triggers undefined behavior. While the value `42` might physically remain in RAM temporarily until overwritten by a subsequent stack frame, referencing it is non-deterministic and unsafe.
3. **Corrected Model**:
   * Automatic local variables on the stack are deallocated upon stack frame collapse. Returning an address of a local variable creates a **dangling pointer**. To safely return memory from a sub-function, dynamic allocation via `malloc()` on the **Heap** must be used, passing ownership back to the caller
