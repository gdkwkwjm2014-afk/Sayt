LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := DarknessVip

# Фикс ошибки TLS для новых NDK (r27/r29)
LOCAL_LDFLAGS += -Wl,-z,max-page-size=4096

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/imgui \
                    $(LOCAL_PATH)/Algorithm \
                    $(LOCAL_PATH)/Esp \
                    $(LOCAL_PATH)/Aimbot

# Прописываем файлы вручную для стабильности сборки
LOCAL_SRC_FILES := Main.cpp \
                   Memory.cpp \
                   imgui/imgui.cpp \
                   imgui/imgui_draw.cpp \
                   imgui/imgui_widgets.cpp \
                   imgui/imgui_tables.cpp

LOCAL_LDLIBS := -llog -lGLESv3 -lEGL -lz -landroid
LOCAL_CPPFLAGS := -std=c++17 -fexceptions -frtti

include $(BUILD_SHARED_LIBRARY)

