//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_COLLEGE_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_COLLEGE_H
#include "Student.h"
#include <string>
#include <iostream>
#pragma once

//大学生
class College:Student{
    std::string major;
    double english;
    double program_design;
    double ad_math;

    void achievement_show() override;
    double sum() override;
    double avg() override;
};

#endif //STUDENT_ACHIEVEMENTS_SYSTEM_COLLEGE_H
