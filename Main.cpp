#include <jni.h>
#include <string>
#include "imgui.h"
#include "auth.hpp"
#include "Memory.h"

// Здесь будет твой код меню и логика чита
// Главное, что мы убрали Windows.h, из-за которого была ошибка

extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */) {
    std::string hello = "Darkness VIP Loaded";
    return env->NewStringUTF(hello.c_str());
}

// Пример функции проверки уровня для Админки
void DrawMenu() {
    ImGui::Begin("Darkness VIP");
    
    if (ImGui::Button("Обычный функционал")) {
        // Логика для всех
    }

    // Тот самый фейсконтроль, про который я говорил
    if (KeyAuthApp.user_data.subscriptions[0].level == "2") {
        ImGui::Spacing();
        ImGui::Text("--- ADMIN PANEL ---");
        if (ImGui::Button("УЛЬТРА ФУНКЦИИ")) {
            // Это увидит только Level 2
        }
    }
    
    ImGui::End();
}
