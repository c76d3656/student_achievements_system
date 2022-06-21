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
class College:public Student{
public:
    std::string major;
    double english;
    double program_design;
    double ad_math;

    College(information Base,std::string major,double English,double Program_design,double Ad_math );

    void achievement_show() override;
    double sum() override;
    double avg() override;
    void change_info() override;
    void remove() override;
};

extern std::vector<College*> total_college_list;
extern std::set<unsigned int> college_id_set;


#endif //STUDENT_ACHIEVEMENTS_SYSTEM_COLLEGE_H
