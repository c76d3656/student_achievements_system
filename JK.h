//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
#include "JS.h"
#include <iostream>
#pragma once

//中学生
class JK:public JS{
public:

    double geography;
    double history;

    JK(information Base, double English, double Math, double Chinese, double geography, double history);


    void achievement_show() override;
    double sum()override;
    double avg() override;
    void change_info() override;
    void remove() override;
};

extern std::vector<JK*> total_jk_list;
extern std::set<unsigned int> jk_id_set;


#endif //STUDENT_ACHIEVEMENTS_SYSTEM_JK_H
