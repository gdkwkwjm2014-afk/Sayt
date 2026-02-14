#pragma once

// Вырезали Windows.h, чтобы не было ошибки
#include <stdint.h>
#include <stddef.h>

// Базовые настройки ImGui для мобилок
#define IMGUI_VERSION "1.89"
#define IMGUI_CHECKVERSION() (void)0

namespace ImGui {
    // Минимум функций для проверки сборки
    bool Begin(const char* name, bool* p_open = NULL);
    void End();
    bool Button(const char* label);
    void Text(const char* fmt, ...);
}

// Если в твоем проекте есть папка imgui, 
// убедись что этот файл лежит именно там или в корне
