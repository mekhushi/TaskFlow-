#include <iostream>
#include "process.h"
#include "scheduler.h"
#include "memory_manager.h"

int main() {
    MemoryManager mem(64); // 64MB RAM
    Scheduler scheduler;

    Process* p1 = new Process("P1", 16, 5, 1);
    Process* p2 = new Process("P2", 24, 8, 2);

    if (mem.allocate(p1->id, p1->memoryRequired)) {
        scheduler.addProcess(p1);
    } else {
        std::cout << "Memory allocation failed for P1\n";
    }

    if (mem.allocate(p2->id, p2->memoryRequired)) {
        scheduler.addProcess(p2);
    } else {
        std::cout << "Memory allocation failed for P2\n";
    }

    std::cout << "Running Scheduler...\n";
    scheduler.runRoundRobin(3);

    mem.free("P1");
    mem.free("P2");

    std::cout << "Memory used: " << mem.getUsedMemory() << "MB\n";
    std::cout << "Memory free: " << mem.getFreeMemory() << "MB\n";

    delete p1;
    delete p2;

    return 0;
}
