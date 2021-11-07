#include "memory.h"

int main() {
        Memory myMemory;
        initMemory(&myMemory, 100);
        allocateMemory(&myMemory, 10, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 20, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 0, 10);
        printMemory(&myMemory);
        allocateMemory(&myMemory, 30, 70);
        printMemory(&myMemory);
        printMemory(&myMemory);
        freeMemory(&myMemory, 40, 20);
        printMemory(&myMemory);
        freeMemory(&myMemory, 80, 10);
        printMemory(&myMemory);
        freeMemory(&myMemory, 10, 10);
        printMemory(&myMemory);
        freeMemory(&myMemory, 0, 10);
        printMemory(&myMemory);
        freeMemory(&myMemory, 20, 20);
        printMemory(&myMemory);
        freeMemory(&myMemory, 90, 10);
        printMemory(&myMemory);
        freeMemory(&myMemory, 60, 20);
        printMemory(&myMemory);
        return 0;
}

