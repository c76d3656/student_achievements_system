//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
#include <utility>

#include "Student.h"



#pragma once

class JS:public Student{
public:
    double english;
    double math;
    double chinese;;

    JS(information Base,double English,double Math,double Chinese){
        this->info=std::move(Base);
        this->english=English;
        this->math=Math;
        this->chinese=Chinese;
    }

    JS();


    void achievement_show() override;
    double sum() override;
    double avg() override;
    void change_info() override;
    void remove() override;
};


extern std::vector<JS*> total_js_list;
extern std::set<unsigned int> js_id_set;



#endif //STUDENT_ACHIEVEMENTS_SYSTEM_JS_H
