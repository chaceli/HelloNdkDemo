#include <jni.h>

/**
 * 这个是返回一个字符串的c代码
 */
JNIEXPORT jstring JNICALL
Java_com_wangjin_hellondkdemo_MainActivity_helloFromJni(JNIEnv *env, jobject instance) {

    char* c ="hello from c";

    return (*env)->NewStringUTF(env, c);
}

/**
 * 这个是回调java方法打印一句话的代码
 */
JNIEXPORT void JNICALL
Java_com_wangjin_hellondkdemo_MainActivity_callBackJavafromC(JNIEnv *env, jobject obj) {
    // 1.通过反射找到类
    jclass clazz = (*env) -> FindClass(env, "com/wangjin/hellondkdemo/MainActivity");
    // 2. 找到方法ID
    jmethodID methodId = (*env) -> GetMethodID(env, clazz, "logout", "()V");
    // 3.调用方法，obj就是调用的类实例，所以不用再次创建了
    (*env)->CallVoidMethod(env, obj, methodId);
}
