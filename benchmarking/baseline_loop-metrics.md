# Benchmark Report: Baseline Loop

## Environment
- **Machine:** Intel(R) Xeon(R) Platinum 8259CL, 1 Core
- **Compiler:** gcc (GNU 89 standard)

## Methodology
Used `clock()` function to measure CPU time for a loop of 100,000,000 iterations.

## Results
- **Execution Time:** 0.702 seconds
- **CPU Usage:** 0.185 seconds (User time)

## Analysis
The benchmark shows an execution time of 0.702s (real time). The user CPU time of 0.185s indicates that the core was actively processing the loop for a fraction of the total execution time, suggesting that the remainder of the time was influenced by system scheduling or virtualization overhead in this environment. This demonstrates how runtime measurements can vary based on system load.
