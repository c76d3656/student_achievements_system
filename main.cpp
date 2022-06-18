#include <iostream>
#include <string>
#include "Student.h"
#include "JS.h"
#include "JK.h"
#include "College.h"
#pragma once



//函数声明
//添加功能
bool new_js();
bool new_jk();
bool new_college();
//查询功能
void search_student();
//显示功能
void show_student_list();
void show_target_student();
//编辑功能
void change_information();
//删除功能
bool remove_student();
//统计功能
int how_many_student();
int target_student_sum();
int target_student_avg();
//排序功能



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
