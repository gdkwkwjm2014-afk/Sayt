#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <unistd.h>

class Memory {
public:
    int pid; // Добавили переменную, на которую ругается робот
    int get_pid(const char* package_name);
    bool read(long address, void* buffer, size_t size);
};

#endif
