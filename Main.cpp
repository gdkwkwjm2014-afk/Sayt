#include "imgui.h"
#include <jni.h>
#include <string>

// Состояние
bool is_menu_open = false; 
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

    // Простое меню без сложных флагов, которые вызывают ошибки
    if (!is_menu_open) {
        ImGui::Begin("LOGO"); 
        if (ImGui::Button("OPEN MENU")) { 
            is_menu_open = true;
        }
        ImGui::End();
    }

    if (is_menu_open) {
        ImGui::Begin("DARKNESS VIP");

        if (!is_logged_in) {
            ImGui::Text("STATUS: LOGIN NEEDED");
            ImGui::InputText("Key", input_key, 64);
            if (ImGui::Button("LOGIN")) {
                if (std::string(input_key).length() > 2) is_logged_in = true;
            }
        } else {
            ImGui::Text("DARKNESS ACTIVE");
            ImGui::Checkbox("ESP LINE", &esp_active);
            
            if (ImGui::Button("CLOSE MENU")) {
                is_menu_open = false;
            }
        }
        ImGui::End();
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Stable");
}
