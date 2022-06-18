#include <iostream>
#include <string>



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
//小学生
class JS:public Student{
public:
    double english;
    double math;
    double chinese;

    void achievement_show() override;
    double sum() override;
    double avg() override;
};


void JS::achievement_show() {
    printf("%lf\t%lf\t%lf\t\n", this->chinese, this->math, this->english);
}

double JS::sum() {
    auto _sum=this->math+ this->english+ this->chinese;
    return _sum;
}

double JS::avg() {
    auto _avg = (this->sum()/(3.0));
    return _avg;
}


//中学生
class JK:JS{
    double geography;
    double history;


    void achievement_show() override;
    double sum() override;
    double avg() override;
};

void JK::achievement_show() {
    printf("%lf\t%lf\t%lf\t%lf\t%lf\t\n", this->chinese, this->math, this->english, this->geography, this->history);
}

double JK::sum() {
    auto _sum=this->math+ this->english+ this->chinese+ this->geography+ this->history;
    return _sum;
}

double JK::avg() {
    auto _avg = this->sum()/(5.0);
    return _avg;
}

//大学生
class College:Student{
    std::string major;
    double english;
    double program_design;
    double ad_math;
};

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
