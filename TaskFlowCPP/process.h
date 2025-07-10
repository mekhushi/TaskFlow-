#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
public:
    std::string id;
    int memoryRequired;
    int executionTime;
    int priority;
    int remainingTime;

    Process(std::string id, int memory, int time, int priority);
    void runOneUnit();
};

#endif
