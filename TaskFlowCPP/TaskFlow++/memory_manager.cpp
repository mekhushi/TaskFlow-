#include "memory_manager.h"

MemoryManager::MemoryManager(int memorySize) : totalMemory(memorySize), usedMemory(0) {}

bool MemoryManager::allocate(std::string processID, int size) {
    if (usedMemory + size > totalMemory) return false;
    allocations[processID] = size;
    usedMemory += size;
    return true;
}

void MemoryManager::free(std::string processID) {
    if (allocations.count(processID)) {
        usedMemory -= allocations[processID];
        allocations.erase(processID);
    }
}

int MemoryManager::getUsedMemory() {
    return usedMemory;
}

int MemoryManager::getFreeMemory() {
    return totalMemory - usedMemory;
}
