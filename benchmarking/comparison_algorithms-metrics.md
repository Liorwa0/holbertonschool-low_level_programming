# Comparison Report: Algorithmic Efficiency

## Methodology
- Compared `count_even_naive` vs `count_even_single_pass`.
- Both processed an array of 50,000 elements.
- Each implementation was measured 3 times to calculate the average.

## Results
| Metric | Naive (Average) | Single-Pass (Average) |
| :--- | :--- | :--- |
| Execution Time | 2.769863 seconds | 0.000106 seconds |

## Efficiency Calculation
- **Relative Difference:** The naive implementation is approximately 26,131 times slower than the single-pass implementation.

## Analysis
- **Naive Algorithm:** Complexity is O(n²). The nested loops cause the number of operations to grow quadratically with the array size.
- **Single-pass Algorithm:** Complexity is O(n). By eliminating the nested loop, we process each element exactly once.
- **Conclusion:** Algorithmic choice is the single most significant factor in energy efficiency. Reducing complexity from O(n²) to O(n) saves thousands of CPU cycles, directly reducing the energy footprint of the application.
