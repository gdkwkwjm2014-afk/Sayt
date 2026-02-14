LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := DarknessVip

# Здесь мы убрали приставку imgui/, чтобы робот искал файлы в корне
LOCAL_SRC_FILES := Main.cpp \
                   Memory.cpp \
                   imgui.cpp \
                   imgui_draw.cpp \
                   imgui_widgets.cpp \
                   imgui_tables.cpp \
                   imgui_demo.cpp

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
