//
// Created by qingyong on 2018/11/3.
//

#include "com_ai_hellosample_tools_Util.h"

jstring Java_com_ai_hellosample_tools_Util_getDeviceId(JNIEnv *env, jclass thiz) {
    return (*env).NewStringUTF("id");
}