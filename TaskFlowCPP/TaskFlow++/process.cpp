#include "process.h"
#include <iostream>

Process::Process(std::string id, int memory, int time, int priority)
    : id(id), memoryRequired(memory), executionTime(time),
      priority(priority), remainingTime(time) {}

void Process::runOneUnit() {
    if (remainingTime > 0) remainingTime--;
}
