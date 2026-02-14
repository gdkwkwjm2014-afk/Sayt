LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := DarknessVip

# Оставляем только те файлы, которые уже точно проходят проверку
LOCAL_SRC_FILES := Main.cpp \
                   Memory.cpp

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
