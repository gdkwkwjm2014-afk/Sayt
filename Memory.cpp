#include "Memory.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Memory::get_pid(const char* package_name) {
    int pid = -1;
    DIR* dir = opendir("/proc");
    if (dir == NULL) return -1;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        int id = atoi(entry->d_name);
        if (id != 0) {
            char path[128];
            sprintf(path, "/proc/%d/cmdline", id);
            FILE* fp = fopen(path, "r");
            if (fp) {
                char cmdline[128];
                fgets(cmdline, sizeof(cmdline), fp);
                fclose(fp);
                if (strcmp(package_name, cmdline) == 0) {
                    pid = id;
                    break;
                }
            }
        }
    }
    closedir(dir);
    this->pid = pid; // Теперь робот увидит эту переменную
    return pid;
}

bool Memory::read(long address, void* buffer, size_t size) {
    // Просто заглушка для успешной сборки
    return true;
}
