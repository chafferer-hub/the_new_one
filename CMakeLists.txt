cmake_minimum_required(VERSION 3.16)
project(library C)
set(CMAKE_C_STANDARD 99)

include_directories(C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\include)#include文件位置
link_directories(C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\lib)#lib文件夹位置
link_libraries(libmysql)#lib下dll文件名
add_executable(library main.c)
target_link_libraries(library libmysql)
