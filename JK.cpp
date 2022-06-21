//
// Created by Zhong on 2022/6/18.
//

#include "JK.h"

#include <utility>

std::vector<JK*> total_jk_list;
std::set<unsigned int> jk_id_set;

void JK::achievement_show() {
    printf("\t%d\t%s\t%lf\t%lf\t%lf\t%lf\t%lf\t\n",this->info.id, this->info.name.c_str() , this->chinese, this->math, this->english, this->geography, this->history);
}

double JK::sum() {
    auto _sum=this->math+ this->english+ this->chinese+ this->geography+ this->history;
    return _sum;
}

double JK::avg(){
    auto _avg = this->sum()/(5.0);
    return _avg;
}

void JK::change_info() {
    printf("Enter to jump\n");
    info_change();
    printf("change english:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->english=tmp;
        }
    }
    printf("change math:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->english=tmp;
        }
    }
    printf("change chinese:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->english=tmp;
        }
    }
    printf("change geography:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->geography=tmp;
        }
    }
    printf("change history:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->history=tmp;
        }
    }
}

void JK::remove() {
    for(auto jk =total_jk_list.begin();jk!= total_jk_list.end();++jk){
        auto tmp = *jk;
        if(tmp->info.id == this->info.id){
            total_jk_list.erase(jk);
            jk_id_set.erase(this->info.id);
            printf("\nsuccess\n");
            return;
        }
    }
    printf("\nerror\n");
}

JK::JK(information Base,double English,double Math,double Chinese,double geography,double history):JS(std::move(Base),English,Math,Chinese){
this->geography=geography;
this->history=history;
}
/*
 *
 * unsigned int how_many_js();
unsigned int how_many_jk();
unsigned int how_many_college();
unsigned int how_many_student();
double target_js_sum(unsigned int id);
double target_jk_sum(unsigned int id);
double target_college_sum(unsigned int id);
double target_js_avg(unsigned int id);
double target_jk_avg(unsigned int id);
double target_college_avg(unsigned int id);
 *
 *
 *
 *
 * */


