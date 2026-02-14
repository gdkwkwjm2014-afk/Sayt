LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := DarknessVip
# Оставляем только два твоих файла, чтобы билд прошел мгновенно
LOCAL_SRC_FILES := Main.cpp Memory.cpp
LOCAL_LDLIBS := -llog -landroid
include $(BUILD_SHARED_LIBRARY)
