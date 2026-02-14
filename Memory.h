#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <unistd.h>
#include <string>

class Memory {
public:
    // На Internal нам не нужен PID, мы уже в процессе
    uintptr_t base_address = 0;

    // Получаем адрес библиотеки игры (например, libUE4.so)
    uintptr_t get_module_base(const char* module_name);

    // Самое простое чтение в мире для Internal
    template <typename T>
    T read(uintptr_t address) {
        if (address < 0xFFFFFF) return T(); // Защита от краша
        return *(T*)address;
    }

    // Запись
    template <typename T>
    void write(uintptr_t address, T value) {
        if (address < 0xFFFFFF) return;
        *(T*)address = value;
    }
};

extern Memory mem;

#endif
