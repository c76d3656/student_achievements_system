//
// Created by Zhong on 2022/6/18.
//

#ifndef STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H
#define STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H


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
    information info;
    void info_show() const{
        printf("%d\t%s\t%s\t%d\t%d\t", this->info.id, this->info.name.c_str(),(this->info.gender?"man":"girl"), this->info.age,this->info.classroom_id);
    }
    virtual void achievement_show()=0;
    virtual void change_info()=0;
    virtual void remove()=0;
    virtual double sum()=0;
    virtual double avg()=0;

};

#endif //STUDENT_ACHIEVEMENTS_SYSTEM_STUDENT_H
