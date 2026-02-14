#ifndef OFFSETS_H
#define OFFSETS_H

#include <string>
#include <vector>
#include <stdint.h>

// Заменяем Windows DWORD на универсальный тип для адресов
typedef uintptr_t ADDRESS;

namespace Offset {
    namespace Data {
        // Эти значения нужно будет обновить под текущую версию игры на Android
        const ADDRESS GWorld = 0x0; // На телефоне часто ищут GWorld
        const ADDRESS EntityList = 0x70;
        const ADDRESS AcknowledgedPawn = 0x360;
    }

    struct Vector3 {
        float x, y, z;
    };

    struct Vector2 {
        float x, y;
    };

    struct playerData {
        ADDRESS Address;
        Vector3 Position;
        int TeamID;
        int Health;
        float Distance;
        std::string Name;
        bool IsBot;
    };
}

#endif
