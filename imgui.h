#pragma once
#include <stdint.h>
#include <stddef.h>
#include <string.h> // Для memset
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
typedef int ImGuiStyleVar;
typedef int ImDrawListFlags;
typedef int ImGuiInputTextFlags;

struct ImVec2 { float x, y; ImVec2() { x = y = 0.0f; } ImVec2(float _x, float _y) { x = _x; y = _y; } };
struct ImVec4 { float x, y, z, w; ImVec4() { x = y = z = w = 0.0f; } ImVec4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; } };

template<typename T>
struct ImVector {
    int Size; int Capacity; T* Data;
    ImVector() { Size = Capacity = 0; Data = NULL; }
    void clear() { Size = 0; }
    void resize(int new_size) { Size = new_size; }
    void reserve(int new_cap) { Capacity = new_cap; } // Нужно для imgui_internal
    T* begin() { return Data; }
    T* end() { return Data + Size; }
};

struct ImGuiStorage {
    struct ImGuiStoragePair { ImGuiID key; union { int val_i; float val_f; void* val_p; }; };
    ImVector<ImGuiStoragePair> Data;
    void Clear() { Data.clear(); }
    int GetInt(ImGuiID key, int default_val = 0) const { return default_val; }
    void SetInt(ImGuiID key, int val) {} // Исправляем ошибку со скрина
};

struct ImFont {}; 
struct ImGuiStyle { ImVec2 WindowPadding; float WindowRounding; ImVec4 Colors[55]; };

namespace ImGui {
    IMGUI_API bool Begin(const char* name, bool* p_open = NULL, int flags = 0);
    IMGUI_API void End();
    IMGUI_API bool Button(const char* label, const ImVec2& size = ImVec2(0, 0));
    IMGUI_API void Text(const char* fmt, ...);
    IMGUI_API bool InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0);
    IMGUI_API bool Checkbox(const char* label, bool* v);
    IMGUI_API bool SliderFloat(const char* label, float* v, float v_min, float v_max);
    IMGUI_API ImGuiStyle& GetStyle();
}
