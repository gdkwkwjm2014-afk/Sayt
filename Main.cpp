#include "imgui.h"
#include <jni.h>

bool auth = false;
char license[64] = "";
bool wallhack = false;

void ApplyRedTheme() {
    ImGuiStyle& s = ImGui::GetStyle();
    s.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.00f, 0.00f, 1.00f);
    s.Colors[ImGuiCol_Button] = ImVec4(0.80f, 0.00f, 0.00f, 1.00f);
    s.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.20f, 0.20f, 1.00f);
    s.WindowRounding = 12.0f;
}

void DrawUI() {
    ApplyRedTheme();
    ImGui::Begin("DARKNESS VIP");
    if (!auth) {
        ImGui::InputText("License Key", license, 64);
        if (ImGui::Button("LOGIN")) { auth = true; }
    } else {
        ImGui::Checkbox("Wallhack", &wallhack);
        if (ImGui::Button("EXIT")) { auth = false; }
    }
    ImGui::End();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Darkness VIP Loaded");
}
