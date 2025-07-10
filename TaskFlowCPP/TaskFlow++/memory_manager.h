#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <unordered_map>
#include <string>

class MemoryManager {
private:
    int totalMemory;
    int usedMemory;
    std::unordered_map<std::string, int> allocations;

public:
    MemoryManager(int memorySize);
    bool allocate(std::string processID, int size);
    void free(std::string processID);
    int getUsedMemory();
    int getFreeMemory();
};

#endif
