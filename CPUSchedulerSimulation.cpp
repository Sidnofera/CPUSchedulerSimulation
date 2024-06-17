#include <iostream>
#include <queue>
#include <vector>

class Process {
public:
    int id;
    int burstTime;
    int waitingTime;

    Process(int pid, int bt) : id(pid), burstTime(bt), waitingTime(0) {}
};

class Scheduler {
private:
    std::queue<Process> processQueue;
    int timeQuantum;

public:
    Scheduler(int tq) : timeQuantum(tq) {}

    void addProcess(Process p) {
        processQueue.push(p);
    }

    void run() {
        int currentTime = 0;

        while (!processQueue.empty()) {
            Process currentProcess = processQueue.front();
            processQueue.pop();

            if (currentProcess.burstTime > timeQuantum) {
                currentTime += timeQuantum;
                currentProcess.burstTime -= timeQuantum;
                processQueue.push(currentProcess);
            } else {
                currentTime += currentProcess.burstTime;
                currentProcess.waitingTime = currentTime;
                std::cout << "Process " << currentProcess.id << " finished at time " << currentTime << std::endl;
            }
        }
    }
};

int main() {
    Scheduler scheduler(4); 

    std::vector<Process> processes = {
        Process(1, 10),
        Process(2, 4),
        Process(3, 6),
        Process(4, 8)
    };
   


    for (auto &process : processes) {
        scheduler.addProcess(process);
    }

    scheduler.run();

    return 0;
}
