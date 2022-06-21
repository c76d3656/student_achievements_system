#include "Student.h"
#include "JS.h"
#include "JK.h"
#include "College.h"



//函数声明
//辅助功能
bool js_id_is_exist(unsigned int id){
    auto is = js_id_set.find(id);
    if(is != js_id_set.end()){
        return true;
    }
    return false;
}
bool jk_id_is_exist(unsigned int id){
    auto is = jk_id_set.find(id);
    if(is != jk_id_set.end()){
        return true;
    }
    return false;
}
bool college_id_is_exist(unsigned int id){
    auto is = college_id_set.find(id);
    if(is != college_id_set.end()){
        return true;
    }
    return false;
}

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


//保存功能

//读取功能

bool new_js(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const double& english,const double& math,const double& chinese){
    if(js_id_is_exist(id)){
        return false;
    }
    information base = {id,name,gender,age,classroom_id};
    auto *tmp_js = new JS(base,english,math,chinese);
    js_id_set.insert(id);
    total_js_list.push_back(tmp_js);
    return true;
}
bool new_jk(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const double& english,const double& math,const double& chinese,const double& geography,const double& history){
    if(jk_id_is_exist(id)){
        return false;
    }
    information base = {id,name,gender,age,classroom_id};
    auto *tmp_jk = new JK(base,english,math,chinese,geography,history);
    jk_id_set.insert(id);
    total_jk_list.push_back(tmp_jk);
    return true;
}
bool new_college(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const std::string& major,double english,double program_design,double ad_math){
    if(college_id_is_exist(id)){
        return false;
    }
    information base = {id,name,gender,age,classroom_id};
    auto *tmp_college = new College(base,major,english,program_design,ad_math);
    college_id_set.insert(id);
    total_college_list.push_back(tmp_college);
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
