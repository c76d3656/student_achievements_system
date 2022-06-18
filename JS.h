//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
#include "Student.h"
#include "iostream"
#pragma once

class JS:public Student{
public:
    double english;
    double math;
    double chinese;

    void achievement_show() override;
    double sum() override;
    double avg() override;
};




#endif //STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
