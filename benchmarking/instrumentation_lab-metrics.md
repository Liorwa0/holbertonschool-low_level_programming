# Instrumentation Report: Multi-phase Program

## Results
- TOTAL seconds: 0.000945
- BUILD_DATA seconds: 0.000349
- PROCESS seconds: 0.000444
- REDUCE seconds: 0.000152

## Analysis
- The measurements show that the `PROCESS` phase is the most time-consuming, taking approximately 47% of the total execution time.
- This is expected as `process_dataset` performs complex arithmetic operations (multiplication, division, modulo) on every element of the 50,000-sized array.
