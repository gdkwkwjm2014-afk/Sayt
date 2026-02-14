LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := DarknessVip

# Добавляем файлы движка, чтобы ушли ошибки "undefined reference"
LOCAL_SRC_FILES := Main.cpp \
                   Memory.cpp \
                   imgui.cpp \
                   imgui_draw.cpp \
                   imgui_widgets.cpp \
                   imgui_tables.cpp

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
