#pragma once
#include <stdint.h>
#include <stddef.h>

#define IMGUI_API
typedef unsigned int ImGuiID;
typedef unsigned long long ImU64;
typedef char ImWchar;

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

namespace ImGui {
    IMGUI_API bool Begin(const char* name, bool* p_open = NULL, int flags = 0);
    IMGUI_API void End();
    IMGUI_API bool Button(const char* label, const ImVec2& size = ImVec2(0, 0));
    IMGUI_API void Text(const char* fmt, ...);
}
