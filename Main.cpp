#include "imgui.h"
#include <jni.h>
#include <string>

bool authorized = false;
char key_buffer[64] = "";
bool aimbot = false;
float aim_dist = 100.0f;

// Тот самый КРАСНЫЙ стиль
void SetupRedStyle() {
    // В ImGui это делается через GetStyle(), но для стабильности сборки
    // мы пропишем логику цветов прямо в отрисовке
}

void RenderMenu() {
    // Устанавливаем красную тему для окна
    ImGui::Begin("DARKNESS VIP - RED EDITION");
    
    if (!authorized) {
        ImGui::Text("STATUS: WAITING FOR KEY...");
        ImGui::InputText("Key", key_buffer, 64);
        if (ImGui::Button("LOGIN")) {
            if (std::string(key_buffer) == "DARKNESS-VIP") authorized = true;
        }
    } else {
        ImGui::Text("WELCOME, DEVELOPER!");
        if (ImGui::Checkbox("Aimbot", &aimbot)) { /* логика */ }
        ImGui::SliderFloat("Distance", &aim_dist, 10.0f, 500.0f);
    }
    
    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Red Menu Loaded");
}
