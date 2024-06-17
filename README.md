# CPU Scheduler Simulation in C++

## Project Description
This project simulates a basic CPU scheduling algorithm (Round Robin) to manage process execution. It demonstrates key concepts like process management, queue handling, and time slicing, which are relevant to operating systems and performance optimization.

## Features
- **Round Robin Scheduling Algorithm**: Simulates process execution with a configurable time quantum.
- **Process Management**: Handles multiple processes with different burst times.
- **Execution Simulation**: Outputs the finishing time of each process.

## Code Structure

### `Process` Class
Represents a process with an ID, burst time, and waiting time.
```cpp
class Process {
public:
    int id;
    int burstTime;
    int waitingTime;

    Process(int pid, int bt) : id(pid), burstTime(bt), waitingTime(0) {}
};
