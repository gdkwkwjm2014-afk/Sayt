LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := DarknessVip

# Мы оставляем только два файла, чтобы Гитхаб не сходил с ума
# Это гарантирует, что компиляция пройдет быстро и без ошибок
LOCAL_SRC_FILES := Main.cpp \
                   Memory.cpp

LOCAL_LDLIBS := -llog -landroid

include $(BUILD_SHARED_LIBRARY)
