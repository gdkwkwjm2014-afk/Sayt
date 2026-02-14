#include "Memory.h"
#include <dirent.h>
#include <sys/uio.h>
#include <unistd.h>

// Поиск PID игры по имени пакета
int Memory::get_pid(const char* package_name) {
    int pid = -1;
    DIR* dir = opendir("/proc");
    if (dir) {
        struct dirent* ptr;
        while ((ptr = readdir(dir)) != NULL) {
            if (ptr->d_type != DT_DIR) continue;
            if (atoi(ptr->d_name) == 0) continue;
            
            char path[512], line[512];
            sprintf(path, "/proc/%s/cmdline", ptr->d_name);
            FILE* f = fopen(path, "r");
            if (f) {
                fgets(line, sizeof(line), f);
                if (strcmp(line, package_name) == 0) {
                    pid = atoi(ptr->d_name);
                    fclose(f);
                    break;
                }
                fclose(f);
            }
        }
        closedir(dir);
    }
    this->pid = pid;
    return pid;
}

// Чтение памяти (замена функциям драйвера)
bool Memory::read(long address, void* buffer, size_t size) {
    struct iovec local[1];
    struct iovec remote[1];
    local[0].iov_base = buffer;
    local[0].iov_len = size;
    remote[0].iov_base = (void*)address;
    remote[0].iov_len = size;
    
    return process_vm_readv(this->pid, local, 1, remote, 1, 0) == size;
}
