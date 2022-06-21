//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H


#include <string>
#include <iostream>
#include <vector>
#include <set>



//学生信息结构体
struct information
{
    unsigned int id;
    std::string name;
    bool gender;
    unsigned int age;
    unsigned int classroom_id;
};
//学生基类
class Student{
public:
    void info_change(){
        printf("change name:");
        {
            std::string tmp;
            std::cin>>tmp;
            if(!tmp.empty()){
                this->info.name=tmp;
            }
        }
        printf("change gender:");
        {
            int tmp=-1;
            std::cin>>tmp;
            if(tmp == 1){
                this->info.gender= true;
            } else if (tmp==0){
                this->info.gender= false;
            }
        }
        printf("change age:");
        {
            int tmp = -1;
            std::cin>>tmp;
            if(tmp>0){
                this->info.age=tmp;
            }
        }
        printf("change classroom_id:");
        {
            int tmp = -1;
            std::cin>>tmp;
            if(tmp>0){
                this->info.classroom_id=tmp;
            }
        }
    }

    virtual void achievement_show()=0;
    virtual void change_info()=0;
    virtual void remove()=0;
    virtual double sum()=0;
    virtual double avg()=0;


    information info;

    void info_show() const{
        printf("%d\t%s\t%s\t%d\t%d\t\n", this->info.id, this->info.name.c_str(),(this->info.gender?"man":"girl"), this->info.age,this->info.classroom_id);
    }
};

#endif //STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H
