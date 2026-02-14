LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Называем файл как у донора для маскировки
LOCAL_MODULE := TDataMaster

# Указываем только те файлы, которые у нас есть
LOCAL_SRC_FILES := Main.cpp Memory.cpp

# Добавляем стандартные библиотеки логов и графики
LOCAL_LDLIBS := -llog -landroid -lGLESv2

include $(BUILD_SHARED_LIBRARY)
