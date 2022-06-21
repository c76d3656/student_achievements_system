#include "Student.h"
#include "JS.h"
#include "JK.h"
#include "College.h"
#include <direct.h>
#include <fstream>


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
bool new_js(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const double& english,const double& math,const double& chinese);
bool new_jk(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const double& english,const double& math,const double& chinese,const double& geography,const double& history);
bool new_college(unsigned int id,const std::string& name,bool gender,unsigned int age,unsigned int classroom_id,const std::string& major,double english,double program_design,double ad_math);
//查询功能
void search_js(unsigned int id);
void search_jk(unsigned int id);
void search_college(unsigned int id);
//显示功能
void show_js_list();
void show_jk_list();
void show_college_list();
void show_js_achievement_list();
void show_jk_achievement_list();
void show_college_achievement_list();
void show_all_student();
//编辑功能
void change_js_information(unsigned int id);
void change_jk_information(unsigned int id);
void change_college_information(unsigned int id);
//删除功能
bool remove_js(unsigned int id);
bool remove_jk(unsigned int id);
bool remove_college(unsigned int id);
//统计功能
unsigned int how_many_js();
unsigned int how_many_jk();
unsigned int how_many_college();
unsigned int how_many_student();
double target_js_sum(unsigned int id);
double target_jk_sum(unsigned int id);
double target_college_sum(unsigned int id);
double target_js_avg(unsigned int id);
double target_jk_avg(unsigned int id);
double target_college_avg(unsigned int id);
//排序功能
bool cmp_sum_js(JS* a,JS* b){
    return (a)->sum()>(b)->sum();
}
bool cmp_sum_jk(JK* a,JK* b){
    return a->sum()>b->sum();
}
bool cmp_sum_college(College* a,College* b){
    return a->sum()>b->sum();
}
bool cmp_eng_js(JS*& a,JS*& b){
    return (a)->english>(b)->english;
}
bool cmp_eng_jk(JK*& a,JK*& b){
    return a->english>b->english;
}
bool cmp_eng_college(College*& a,College*& b){
    return (a)->english>(b)->english;
}
bool cmp_math_js(JS*& a,JS*& b){
    return a->math>b->math;
}
bool cmp_math_jk(JK*& a,JK*& b){
    return a->math>b->math;
}
bool cmp_math_college(College*& a,College*& b){
    return a->ad_math>b->ad_math;
}
bool cmp_zh_js(JS*& a,JS*& b){
    return a->chinese>b->chinese;
}
bool cmp_zh_jk(JK*& a,JK*& b){
    return a->chinese>b->chinese;
}
bool cmp_geo_jk(JK*& a,JK*& b){
    return a->geography>b->geography;
}
bool cmp_history_jk(JK*& a, JK*& b){
    return a->history<b->history;
}
bool cmp_program_college(College*& a, College*& b){
    return a->program_design>b->program_design;
}
//保存功能

//读取功能

//函数实现
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

//查询功能
void search_js(unsigned int id){
    if(js_id_is_exist(id)){
        printf("this js_is isn't exits");
        return;
    }
    for(auto js : total_js_list){
        if(js->info.id==id){
            js->info_show();
            js->achievement_show();
            return;
        }
    }
}
void search_jk(unsigned int id){
    if(jk_id_is_exist(id)){
        printf("this jk_is isn't exits");
        return;
    }
    for(auto jk : total_jk_list){
        if(jk->info.id==id){
            jk->info_show();
            jk->achievement_show();
            return;
        }
    }
}
void search_college(unsigned int id){
    if(college_id_is_exist(id)){
        printf("this college_is isn't exits");
        return;
    }
    for(auto college : total_college_list){
        if(college->info.id == id){
            college->info_show();
            college->achievement_show();
            return;
        }
    }
}
//显示功能
void show_js_list(){
    for(auto js:total_js_list){
        js->info_show();
    }
    printf("---------------------------\n");
}
void show_jk_list(){
    for(auto jk:total_jk_list){
        jk->info_show();
    }
    printf("---------------------------\n");
}
void show_college_list(){
    for(auto college:total_js_list){
        college->info_show();
    }
    printf("---------------------------\n");
}
void show_js_achievement_list(){
    for(auto js:total_js_list){
        js->achievement_show();
    }
    printf("---------------------------\n");
}
void show_jk_achievement_list(){
    for(auto jk:total_jk_list){
        jk->achievement_show();
    }
    printf("---------------------------\n");
}
void show_college_achievement_list(){
    for(auto college:total_js_list){
        college->achievement_show();
    }
    printf("---------------------------\n");
}
void show_all_student(){
    show_js_list();
    show_jk_list();
    show_college_list();
}
//编辑功能
void change_js_information(unsigned int id){
    if(js_id_is_exist(id)){
        printf("this js_is isn't exits");
        return;
    }
    for(auto js : total_js_list){
        if(js->info.id==id){
            js->change_info();
            return;
        }
    }
}
void change_jk_information(unsigned int id){
    if(jk_id_is_exist(id)){
        printf("this jk_is isn't exits");
        return;
    }
    for(auto jk : total_jk_list){
        if(jk->info.id==id){
            jk->change_info();
            return;
        }
    }
}
void change_college_information(unsigned int id){
    if(college_id_is_exist(id)){
        printf("this college_is isn't exits");
        return;
    }
    for(auto college : total_college_list){
        if(college->info.id == id){
            college->change_info();
            return;
        }
    }
}
//删除功能
bool remove_js(unsigned int id){
    if(js_id_is_exist(id)){
        printf("this js_is isn't exits");
        return false;
    }
    for(auto js : total_js_list){
        if(js->info.id==id){
            js->remove();
            return true;
        }
    }
    return true;
}
bool remove_jk(unsigned int id){
    if(jk_id_is_exist(id)){
        printf("this jk_is isn't exits");
        return false;
    }
    for(auto jk : total_jk_list){
        if(jk->info.id==id){
            jk->remove();
            return true;
        }
    }
    return true;
}
bool remove_college(unsigned int id){
    if(college_id_is_exist(id)){
        printf("this college_is isn't exits");
        return false;
    }
    for(auto college : total_college_list){
        if(college->info.id == id){
            college->remove();
            return true;
        }
    }
    return true;
}
//统计功能
unsigned int how_many_js(){
    unsigned int num = total_js_list.size();
    printf("there are %d js\n",num);
    return num;
}
unsigned int how_many_jk(){
    unsigned int num = total_jk_list.size();
    printf("there are %d jk\n",num);
    return num;
}
unsigned int how_many_college(){
    unsigned int num = total_college_list.size();
    printf("there are %d college\n",num);
    return num;
}
unsigned int how_many_student(){
    unsigned int num = how_many_js()+how_many_jk()+how_many_college();
    printf("there are %d student\n",num);
    return num;
}
double target_js_sum(unsigned int id){
    double num=-1;
    if(js_id_is_exist(id)){
        printf("this js_is isn't exits");
        return false;
    }
    for(auto js : total_js_list){
        if(js->info.id==id){
            num =js->sum();
            return num;
        }
    }
    return num;
}
double target_jk_sum(unsigned int id){
    double num=-1;
    if(jk_id_is_exist(id)){
        printf("this jk_is isn't exits");
        return false;
    }
    for(auto jk : total_jk_list){
        if(jk->info.id==id){
            num = jk->sum();
            return true;
        }
    }
    return num;
}
double target_college_sum(unsigned int id){
    double num=-1;
    if(college_id_is_exist(id)){
        printf("this college_is isn't exits");
        return false;
    }
    for(auto college : total_college_list){
        if(college->info.id == id){
            num = college->sum();
            return true;
        }
    }
    return num;
}
double target_js_avg(unsigned int id){
    double num=-1;
    if(js_id_is_exist(id)){
        printf("this js_is isn't exits");
        return false;
    }
    for(auto js : total_js_list){
        if(js->info.id==id){
            num =js->avg();
            return num;
        }
    }
    return num;
}
double target_jk_avg(unsigned int id){
    double num=-1;
    if(jk_id_is_exist(id)){
        printf("this jk_is isn't exits");
        return false;
    }
    for(auto jk : total_jk_list){
        if(jk->info.id==id){
            num = jk->avg();
            return true;
        }
    }
    return num;
}
double target_college_avg(unsigned int id){
    double num=-1;
    if(college_id_is_exist(id)){
        printf("this college_is isn't exits");
        return false;
    }
    for(auto college : total_college_list){
        if(college->info.id == id){
            num = college->avg();
            return true;
        }
    }
    return num;
}
//排序功能
void sort_js_sum(){
    std::sort(total_js_list.begin(),total_js_list.end(), cmp_sum_js);
    printf("\nsort success\n");
}
void sort_jk_sum(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_sum_jk);
    printf("\nsort success\n");
}
void sort_college_sum(){
    std::sort(total_college_list.begin(),total_college_list.end(), cmp_sum_college);
    printf("\nsort success\n");
}
void sort_js_eng(){
    std::sort(total_js_list.begin(),total_js_list.end(), cmp_eng_js);
    printf("\nsort success\n");
}
void sort_jk_eng(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_eng_jk);
    printf("\nsort success\n");
}
void sort_college_eng(){
    std::sort(total_college_list.begin(),total_college_list.end(), cmp_eng_college);
    printf("\nsort success\n");
}
void sort_js_math(){
    std::sort(total_js_list.begin(),total_js_list.end(), cmp_math_js);
    printf("\nsort success\n");
}
void sort_jk_math(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_math_jk);
    printf("\nsort success\n");
}
void sort_college_math(){
    std::sort(total_college_list.begin(),total_college_list.end(), cmp_math_college);
    printf("\nsort success\n");
}
void sort_js_zh(){
    std::sort(total_js_list.begin(),total_js_list.end(), cmp_zh_js);
    printf("\nsort success\n");
}
void sort_jk_zh(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_zh_jk);
    printf("\nsort success\n");
}
void sort_jk_geo(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_geo_jk);
    printf("\nsort success\n");
}
void sort_jk_his(){
    std::sort(total_jk_list.begin(),total_jk_list.end(), cmp_history_jk);
    printf("\nsort success\n");
}
void sort_college_pro(){
    std::sort(total_college_list.begin(),total_college_list.end(), cmp_program_college);
    printf("\nsort success\n");
}
//保存与初始化功能
std::string get_dir(){
    char _tmp[256];
    getcwd(_tmp,256);
    for(auto &c:_tmp){
        if(c=='\\')
            c='/';
    }
    std::string tmp(_tmp);
    auto tmp_dir = tmp+"/data/";
    if(0 != access(tmp_dir.c_str(),0)){
        mkdir(tmp_dir.c_str());
    }
    return tmp_dir;
}
void save(){
    std::string dir = get_dir();
    std::ofstream out1(dir+"js_data");
    if(out1.is_open()){
        for(const auto &js:total_js_list){
            out1<<js->info.id<<" ";
            out1<<js->info.name<<" ";
            out1<<js->info.gender<<" ";
            out1<<js->info.age<<" ";
            out1<<js->info.classroom_id<<" ";
            out1<<js->english<<" ";
            out1<<js->math<<" ";
            out1<<js->chinese<<"\n";
        }
    }
    out1.close();
    std::ofstream out2(dir+"jk_data");
    if(out2.is_open()){
        for(const auto &jk :total_jk_list){
            out2<<jk->info.id<<" ";
            out2<<jk->info.name<<" ";
            out2<<jk->info.gender<<" ";
            out2<<jk->info.age<<" ";
            out2<<jk->info.classroom_id<<" ";
            out2<<jk->english<<" ";
            out2<<jk->math<<" ";
            out2<<jk->chinese<<" ";
            out2<<jk->geography<<" ";
            out2<<jk->history<<"\n";
        }
    }
    out2.close();
    std::ofstream out3(dir+"college_data");
    if(out3.is_open()) {
        for(const auto &college : total_college_list){
            out3<<college->info.id<<" ";
            out3<<college->info.name<<" ";
            out3<<college->info.gender<<" ";
            out3<<college->info.age<<" ";
            out3<<college->info.classroom_id<<" ";
            out3<<college->major<<" ";
            out3<<college->english<<" ";
            out3<<college->program_design<<" ";
            out3<<college->ad_math<<"\n";
        }
    }
    out3.close();
}
void init(){
    std::string dir = get_dir();
    std::ifstream in1(dir+"js_data.txt");
    if(in1.is_open()){
        unsigned int id;
        std::string name;
        bool gender;
        unsigned int age;
        unsigned int classroom_id;
        double english;
        double math;
        double chinese;
        while (!in1.eof()){
            in1>>id>>name>>gender>>age>>classroom_id>>english>>math>>chinese;
            new_js(id,name,gender,age,classroom_id,english,math,chinese);
        }
    }
    in1.close();
    std::ifstream in2(dir+"jk_data.txt");
    if(in2.is_open()){
        unsigned int id;
        std::string name;
        bool gender;
        unsigned int age;
        unsigned int classroom_id;
        double english;
        double math;
        double chinese;
        double geography;
        double history;
        while (!in2.eof()){
            in1>>id>>name>>gender>>age>>classroom_id>>english>>math>>chinese>>geography>>history;
            new_jk(id,name,gender,age,classroom_id,english,math,chinese,geography,history);
        }
    }
    in2.close();
    std::ifstream in3(dir+"college_data.txt");
    if(in3.is_open()){
        unsigned int id;
        std::string name;
        bool gender;
        unsigned int age;
        unsigned int classroom_id;
        std::string major;
        double english;
        double program_design;
        double ad_math;
        while (!in3.eof()){
            in1>>id>>name>>gender>>age>>classroom_id>>major>>english>>program_design>>ad_math;
            new_college(id,name,gender,age,classroom_id,major,english,program_design,ad_math);
        }
    }
    in3.close();
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
