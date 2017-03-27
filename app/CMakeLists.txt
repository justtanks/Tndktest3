# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

add_library( # 这是注释  下面是添加的包
             native-lib

             # Sets the library as a shared library.
             SHARED

             # 添加包的路径  再添加一个需要重新写一个add_library
             src/main/cpp/native-lib.c )
 add_library(
                    native-test
                    SHARED
                    src/main/cpp/native-test.c
                 )


    find_library( # 添加本地库
                           # location of the NDK library.
                           log-lib

                           # Specifies the name of the NDK library that
                           # CMake needs to locate.
                           log )
   target_link_libraries( # Specifies the target library. 添加的本地库和自己库需要添加进来以供本地编程调用（c 和c++）
                          native-lib
                          # Links the target library to the log library
                          # included in the NDK.
                          ${log-lib} )