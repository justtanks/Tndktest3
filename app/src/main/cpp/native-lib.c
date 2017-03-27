//
// Created by Administrator on 2017/3/20.
//
#define APPNAME "MyApp"
#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include <stdlib.h>
/**
 * 命名规则 ： 从java包下开始 通过包名+类名+方法名进行命名
 *             分割包名的‘，’通过 “_”代替
 */
JNIEXPORT jstring JNICALL
Java_com_andriod_tndktest3_MainActivity_getString(JNIEnv *env, jobject instance) {

    return (*env)->NewStringUTF(env, "hello to add native method");
}

JNIEXPORT jint JNICALL
Java_com_andriod_tndktest3_MainActivity_getMyInt(JNIEnv *env, jobject instance) {

    // TODO
    int i;
    int a=0;
    for( i=0;i<1000;i++){
        a+=i;
    }
  // qsort()  这里调用的是类库头文件的方法 关于头文件和h文件的配合
    //void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
    return a;


}

//将两个字符串进行拼接
JNIEXPORT jstring JNICALL
Java_com_andriod_tndktest3_MainActivity_appendString(JNIEnv *env, jobject instance, jstring str1_,
                                                     jstring str2_) {
    const char *str1 = (*env)->GetStringUTFChars(env, str1_, 0);
    const char *str2 = (*env)->GetStringUTFChars(env, str2_, 0);

    // TODO
    char * string=strcat(str1,str2);
    char ss[60]="";
    jstring  result;
     strcat(ss,string);

    (*env)->ReleaseStringUTFChars(env, str1_, str1);
    (*env)->ReleaseStringUTFChars(env, str2_, str2);
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "%s",ss);  //打日志
    puts(ss);
    result = (*env)->NewStringUTF(env,ss);
    return result;
}