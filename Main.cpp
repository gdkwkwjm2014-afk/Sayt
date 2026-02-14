#include "imgui.h"
#include <jni.h>
#include <string>

bool is_logged_in = false;
char input_key[64] = "";
bool esp_active = false;

void StyleRed() {
    ImGuiStyle& s = ImGui::GetStyle();
    s.Colors[2]  = ImVec4(0.10f, 0.00f, 0.00f, 1.00f); // WindowBg
    s.Colors[21] = ImVec4(0.90f, 0.00f, 0.00f, 1.00f); // Button
    s.Colors[22] = ImVec4(1.00f, 0.10f, 0.10f, 1.00f); // ButtonHovered
    s.WindowRounding = 10.0f;
}

void DrawMenu() {
    StyleRed();
    ImGui::Begin("DARKNESS VIP - PUBG");

    if (!is_logged_in) {
        ImGui::Text("СТАТУС: НУЖЕН КЛЮЧ");
        ImGui::InputText("Вставить ключ", input_key, 64);
        
        if (ImGui::Button("ВХОД")) {
            if (std::string(input_key).length() > 2) { 
                is_logged_in = true;
            }
        }
        
        if (ImGui::Button("КУПИТЬ КЛЮЧ")) {
            // Тут потом ссылку сделаем
        }
    } else {
        ImGui::Text("DARKNESS MENU ЧИТ АКТИВЕН");
        // Убрал Separator, чтобы не было ошибки №24
        ImGui::Checkbox("ESP LINE (ВХ)", &esp_active);
        
        if (ImGui::Button("ВЫХОД")) {
            is_logged_in = false;
        }
    }

    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Success");
}
