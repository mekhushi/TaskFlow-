#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"
#include <queue>
#include <vector>

class Scheduler {
private:
    std::queue<Process*> readyQueue;

public:
    void addProcess(Process* p);
    void runRoundRobin(int timeSlice);
    bool isEmpty();
};

#endif
