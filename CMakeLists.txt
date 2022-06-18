cmake_minimum_required(VERSION 3.22)
project(student_achievements_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(student_achievements_system main.cpp Student.cpp Student.h JS.cpp JS.h JK.cpp JK.h College.cpp College.h)
