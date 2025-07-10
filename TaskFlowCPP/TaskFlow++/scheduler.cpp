#include "scheduler.h"
#include <iostream>

void Scheduler::addProcess(Process* p) {
    readyQueue.push(p);
    std::cout << "Added Process: " << p->id 
              << " | Memory: " << p->memoryRequired << "MB"
              << " | Execution Time: " << p->executionTime << "s"
              << " | Priority: " << p->priority << "\n";
}

bool Scheduler::isEmpty() {
    return readyQueue.empty();
}

void Scheduler::runRoundRobin(int timeSlice) {
    while (!readyQueue.empty()) {
        Process* current = readyQueue.front();
        readyQueue.pop();
        std::cout << "\nRunning Process: " << current->id << "\n";

        int runTime = std::min(timeSlice, current->remainingTime);
        for (int i = 0; i < runTime; ++i) {
            current->runOneUnit();
            std::cout << "Tick " << (i + 1) << ": " 
                      << current->id << " has " << current->remainingTime << "s left\n";
        }

        if (current->remainingTime > 0) {
            std::cout << current->id << " paused. " 
                      << current->remainingTime << "s remaining. Returning to queue.\n";
            readyQueue.push(current);
        } else {
            std::cout << current->id << " finished execution.\n";
        }
    }
}
