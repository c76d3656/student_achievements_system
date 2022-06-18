//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
#include "JS.h"
#include <iostream>
#pragma once

//中学生
class JK:JS{
    double geography;
    double history;


    void achievement_show() override;
    double sum() override;
    double avg() override;
};


#endif //STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
