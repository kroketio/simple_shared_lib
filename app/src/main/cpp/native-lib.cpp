#include <jni.h>
#include <string>
#include "cool_lib.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_simplesharedlib_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    // call the c++ function
    int value = 5;
    int result = cool_library::whatsup(value);

    // format the result to a C sting

    std::string message = "factorial" + std::to_string(result);
    return env->NewStringUTF(message.c_str());
}