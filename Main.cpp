#include "imgui.h"
#include <jni.h>
#include <string>

// Состояние меню
bool is_logged_in = false;
char input_key[64] = "";
bool esp_active = false;

// Красная тема "Darkness VIP"
void ApplyRedTheme() {
    ImGuiStyle& s = ImGui::GetStyle();
    s.Colors[2]  = ImVec4(0.12f, 0.00f, 0.00f, 1.00f); // WindowBg
    s.Colors[21] = ImVec4(0.85f, 0.00f, 0.00f, 1.00f); // Button
    s.Colors[22] = ImVec4(1.00f, 0.15f, 0.15f, 1.00f); // ButtonHovered
    s.WindowRounding = 12.0f;
    s.FrameRounding = 6.0f;
}

void DrawUI() {
    ApplyRedTheme();
    ImGui::Begin("DARKNESS VIP - PUBG MOBILE");

    if (!is_logged_in) {
        ImGui::Text("STATUS: WAITING FOR LICENSE");
        ImGui::InputText("License Key", input_key, 64);
        
        if (ImGui::Button("LOGIN")) {
            if (std::string(input_key).length() > 3) { 
                is_logged_in = true;
            }
        }
        
        if (ImGui::Button("BUY KEY (TG: @ADMIN)")) {
            // Кнопка покупки
        }
    } else {
        ImGui::Text("WELCOME TO DARKNESS");
        ImGui::Separator(); // Теперь заработает без ошибок
        
        ImGui::Checkbox("ACTIVATE ESP (WH)", &esp_active);
        
        if (ImGui::Button("LOGOUT")) {
            is_logged_in = false;
        }
    }

    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Active");
}
