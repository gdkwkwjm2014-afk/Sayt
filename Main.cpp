#include "imgui.h"
#include <jni.h>
#include <string>

// Глобальные переменные
bool is_logged_in = false;
char input_key[64] = "";
bool esp_active = false;

// Красная тема (на цифрах, чтобы не было ошибок)
void StyleRed() {
    ImGuiStyle& s = ImGui::GetStyle();
    s.Colors[2]  = ImVec4(0.10f, 0.00f, 0.00f, 1.00f); // WindowBg
    s.Colors[21] = ImVec4(0.90f, 0.00f, 0.00f, 1.00f); // Button
    s.Colors[22] = ImVec4(1.00f, 0.10f, 0.10f, 1.00f); // ButtonHovered
    s.WindowRounding = 10.0f;
}

void DrawMenu() {
    StyleRed();
    ImGui::Begin("DARKNESS VIP - AUTH");

    if (!is_logged_in) {
        // ЭКРАН ВВОДА КЛЮЧА
        ImGui::Text("СТАТУС: ТРЕБУЕТСЯ КЛЮЧ");
        ImGui::InputText("Вставить ключ", input_key, 64);
        
        if (ImGui::Button("ВХОД")) {
            if (std::string(input_key).length() > 5) { // Простая проверка длины
                is_logged_in = true;
            }
        }
        
        if (ImGui::Button("КУПИТЬ КЛЮЧ")) {
            // Пока просто текст, так как ссылка требует доп. кода
            ImGui::Text("Свяжитесь с админом для покупки!");
        }
    } else {
        // ГЛАВНОЕ МЕНЮ (ВХ)
        ImGui::Text("ДОБРО ПОЖАЛОВАТЬ В DARKNESS");
        ImGui::Separator();
        
        ImGui::Checkbox("АКТИВИРОВАТЬ ВХ (ESP)", &esp_active);
        
        if (ImGui::Button("ВЫЙТИ ИЗ КАССЫ")) {
            is_logged_in = false;
        }
    }

    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Red Menu Loaded");
}
