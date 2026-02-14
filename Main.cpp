#include <jni.h>

// Мы убрали всё лишнее, чтобы робот не ругался на Windows
extern "C" JNIEXPORT jstring JNICALL
Java_com_darkness_vip_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz) {
    return env->NewStringUTF("Build Success - Admin Ready");
}
