#pragma once
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#define IMGUI_API
#define IM_ASSERT(_EXPR)  assert(_EXPR)

typedef unsigned int ImU32;
typedef unsigned int ImGuiID;
typedef unsigned long long ImU64;
typedef unsigned char ImU8;
typedef short ImWchar16;
typedef char ImWchar;
typedef int ImGuiCol;

struct ImVec2 { 
    float x, y; 
    ImVec2() { x = y = 0.0f; } 
    ImVec2(float _x, float _y) { x = _x; y = _y; } 
};

struct ImVec4 { 
    float x, y, z, w; 
    ImVec4() { x = y = z = w = 0.0f; } 
    ImVec4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; } 
};

// Добавляем ImVector, который он так просит
template<typename T>
struct ImVector {
    int Size; int Capacity; T* Data;
    ImVector() { Size = Capacity = 0; Data = NULL; }
};

namespace ImGui {
    IMGUI_API bool Begin(const char* name, bool* p_open = NULL, int flags = 0);
    IMGUI_API void End();
    IMGUI_API bool Button(const char* label, const ImVec2& size = ImVec2(0, 0));
    IMGUI_API void Text(const char* fmt, ...);
}
