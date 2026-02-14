#include "imgui.h"
#include <jni.h>
#include <string>

// Состояния меню
bool is_menu_open = false; // По умолчанию меню закрыто (только лого)
bool is_logged_in = false;
char input_key[64] = "";
bool esp_active = false;

void StyleRed() {
    ImGuiStyle& s = ImGui::GetStyle();
    s.Colors[2]  = ImVec4(0.12f, 0.00f, 0.00f, 1.00f); // WindowBg
    s.Colors[21] = ImVec4(0.85f, 0.00f, 0.00f, 1.00f); // Button
    s.Colors[22] = ImVec4(1.00f, 0.15f, 0.15f, 1.00f); // ButtonHovered
    s.WindowRounding = 12.0f;
}

void DrawMenu() {
    StyleRed();

    // 1. ЛОГОТИП (Плавающая кнопка)
    if (!is_menu_open) {
        ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
        ImGui::Begin("LOGO", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoBackground);
        if (ImGui::Button(" [ D ] ", ImVec2(50, 50))) { // Кнопка-логотип "D"
            is_menu_open = true;
        }
        ImGui::End();
    }

    // 2. ОСНОВНОЕ МЕНЮ
    if (is_menu_open) {
        ImGui::Begin("DARKNESS VIP - PUBG", NULL, ImGuiWindowFlags_AlwaysAutoResize);

        if (!is_logged_in) {
            ImGui::Text("СТАТУС: НУЖЕН КЛЮЧ");
            ImGui::InputText("Ключ", input_key, 64);
            if (ImGui::Button("ВХОД")) {
                if (std::string(input_key).length() > 2) is_logged_in = true;
            }
        } else {
            ImGui::Text("DARKNESS ACTIVE");
            ImGui::Checkbox("ESP LINE", &esp_active);
            
            // Кнопка закрытия (свернуть в лого)
            if (ImGui::Button("СВЕРНУТЬ МЕНЮ")) {
                is_menu_open = false;
            }
        }
        ImGui::End();
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Logo & Menu Ready");
}
