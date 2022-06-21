//
// Created by Zhong on 2022/6/18.
//

#include "College.h"

#include <utility>

std::vector<College*> total_college_list;
std::set<unsigned int> college_id_set;

void College::achievement_show() {
    printf("major in %\ts", this->major.c_str());
    printf("%lf\t%lf\t%lf\t\n", this->english, this->program_design, this->ad_math);
}

double College::sum() {
    auto _sum = this->english+this->program_design+this->ad_math;
    return _sum;
}

double College::avg() {
    auto _avg = this->sum()/(3.0);
    return _avg;
}

void College::change_info() {
    printf("Enter to jump\n");
    info_change();
    printf("change major:");
    {
        std::string tmp;
        std::cin>>tmp;
        if(!tmp.empty()){
            this->major=tmp;
        }
    }
    printf("change english:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->english=tmp;
        }
    }
    printf("change program_design:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->program_design=tmp;
        }
    }
    printf("change ad_math:");
    {
        double tmp = -1;
        std::cin>>tmp;
        if(tmp>0){
            this->ad_math=tmp;
        }
    }
}

void College::remove() {
    for(auto college = total_college_list.begin(); college!= total_college_list.end();++college){
        auto tmp = *college;
        if(tmp->info.id == this->info.id){
            total_college_list.erase(college);
            college_id_set.erase(this->info.id);
            printf("\nsuccess\n");
            return;
        }
    }
    printf("\nerror\n");
}

College::College(information Base, std::string Major, double English, double Program_design, double Ad_math) {
    this->info=std::move(Base);
    this->major=std::move(Major);
    this->english=English;
    this->program_design=Program_design;
    this->ad_math=Ad_math;
}


