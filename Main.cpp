#include "imgui.h"
#include <jni.h>
#include <string>

bool authorized = false;
char key_buffer[64] = "";
bool feature_esp = false;

void ApplyDarknessTheme() {
    ImGuiStyle& s = ImGui::GetStyle();
    // Используем индексы вместо имен, чтобы не было ошибок
    s.Colors[2]  = ImVec4(0.12f, 0.00f, 0.00f, 1.00f); // WindowBg (Темно-красный)
    s.Colors[21] = ImVec4(0.80f, 0.00f, 0.00f, 1.00f); // Button (Красный)
    s.Colors[22] = ImVec4(1.00f, 0.20f, 0.20f, 1.00f); // ButtonHovered (Яркий)
    s.WindowRounding = 10.0f;
    s.FrameRounding = 5.0f;
}

void RenderMyMenu() {
    ApplyDarknessTheme();
    ImGui::Begin("DARKNESS VIP - RED EDITION");

    if (!authorized) {
        ImGui::Text("ВВЕДИТЕ КЛЮЧ:");
        ImGui::InputText("##key", key_buffer, 64);
        if (ImGui::Button("ВОЙТИ")) {
            if (std::string(key_buffer) == "ADMIN") authorized = true;
        }
    } else {
        ImGui::Text("ДОБРО ПОЖАЛОВАТЬ!");
        ImGui::Checkbox("ESP LINE", &feature_esp);
        if (ImGui::Button("ВЫХОД")) authorized = false;
    }

    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP: Red Menu Ready");
}
