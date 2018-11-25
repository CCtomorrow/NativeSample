//
// Created by qingyong on 2018/11/3.
//

#include <assert.h>
#include "com_ai_hellosample_tools_Util.h"

jstring Java_com_ai_hellosample_tools_Util_getDeviceId(JNIEnv *env, jclass thiz) {
    return (*env).NewStringUTF("*");
}

jstring native_dynamic_key(JNIEnv *env, jclass thiz) {
    return env->NewStringUTF("->");
}

/**
 * 函数映射表
 */
static JNINativeMethod methods[] = {
        {"dynamicGenerateKey", "(Ljava/lang/String;)Ljava/lang/String;", (void *) native_dynamic_key},
        //这里可以有很多其他映射函数
};

static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods,
                                 int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static int registerNatives(JNIEnv *env) {
    const char *className = "com/ai/hellosample/tools/Util"; //指定注册的类
    return registerNativeMethods(env, className, methods, sizeof(methods) / sizeof(methods[0]));
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    //LOGI("-------------JNI_OnLoad into.--------\n");
    JNIEnv *env = NULL;
    jint result = JNI_ERR;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }
    assert(env != NULL);
    //动态注册，自定义函数
    if (!registerNatives(env)) {
        return -1;
    }
    return JNI_VERSION_1_6;
}