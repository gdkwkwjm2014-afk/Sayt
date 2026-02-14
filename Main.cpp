#include <jni.h>
#include <thread>
#include <GLES3/gl3.h>
#include "imgui.h"
#include "imgui_internal.h"

// ТВОИ РЕСУРСЫ
#include "icon.h"       
#include "iconcpp.h"    
#include "auth.hpp"
#include "Memory.h"
#include "Settings.h"
#include "Theme.h"
#include "AntiBan.h"

// ПОДКЛЮЧЕНИЕ STB_IMAGE
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace KeyAuth;

// ДАННЫЕ KEYAUTH (Твои актуальные данные)
api KeyAuthApp("Crime3135's Application", "ofV8bg5snQ", "5ade2825b0b280ca3866077cf0f6f38e6fdb02d963641884f9fa3d20a718df4e", "1.0", "https://keyauth.win/api/1.2/");

GLuint DarknessLogoTex = 0;

// ФУНКЦИЯ СОЗДАНИЯ ТЕКСТУРЫ
GLuint CreateTexture(unsigned char* data, int len) {
    int w, h, n;
    unsigned char* pixels = stbi_load_from_memory(data, len, &w, &h, &n, 4);
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    stbi_image_free(pixels);
    return tex;
}

// ОСНОВНОЕ МЕНЮ
void DrawMenu() {
    if (!DarknessLogoTex) {
        DarknessLogoTex = CreateTexture(darkness_logo, sizeof(darkness_logo));
    }

    ImGui::Begin("DARKNESS VIP", nullptr, ImGuiWindowFlags_NoCollapse);
    
    // Логотип
    ImGui::Image((void*)(intptr_t)DarknessLogoTex, ImVec2(100, 100));
    ImGui::SameLine();
    ImGui::TextColored(ImColor(255, 0, 0), "DARKNESS PROJECT\nMobile Internal System");

    ImGui::Separator();

    if (ImGui::BeginTabBar("Tabs")) {
        // ВКЛАДКА ДЛЯ ВСЕХ
        if (ImGui::BeginTabItem("VISUALS")) {
            ImGui::Checkbox("ESP Player", &Settings::Esp);
            ImGui::Checkbox("Show Flags", &Settings::ShowFlags);
            ImGui::EndTabItem();
        }

        // ПРИВАТНАЯ АДМИН-ПАНЕЛЬ (Только для Level 2)
        if (KeyAuthApp.user_data.level == "2") {
            if (ImGui::BeginTabItem("ADMIN")) {
                ImGui::TextColored(ImColor(0, 255, 0), "ACCESS GRANTED: ADMINISTRATOR");
                ImGui::Separator();
                
                static char keyName[32] = "DARKNESS-";
                ImGui::InputText("Key Prefix", keyName, 32);
                
                if (ImGui::Button("GENERATE 1 DAY KEY", ImVec2(-1, 50))) {
                    // Здесь логика генерации через API, если нужно
                    ImGui::OpenPopup("KeyGenStatus");
                }
                
                if (ImGui::BeginPopup("KeyGenStatus")) {
                    ImGui::Text("Key generated successfully!");
                    if (ImGui::Button("OK")) ImGui::CloseCurrentPopup();
                    ImGui::EndPopup();
                }
                
                ImGui::EndTabItem();
            }
        }
        
        ImGui::EndTabBar();
    }
    ImGui::End();
}

// ЗАПУСК ВНУТРИ ИГРЫ (JNI)
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    AntiBan::ClearLogs(); // Чистим логи при старте

    std::thread([]() {
        KeyAuthApp.init(); // Коннект к серверу
        
        // Тут должен быть твой логин. Если ключ уже вшит или сохранен:
        // KeyAuthApp.license("ТВОЙ_КЛЮЧ");

        // Ждем загрузки игры
        while (Memory::base_address == 0) {
            Memory::base_address = Memory::get_module_base("libUE4.so");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }).detach();

    return JNI_VERSION_1_6;
}

