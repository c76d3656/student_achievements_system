//
// Created by Zhong on 2022/6/18.
//

#include "JS.h"

std::vector<JS*> total_js_list;
std::set<unsigned int> js_id_set;



void JS::achievement_show() {
    printf("\t%d\t%s\t%lf\t%lf\t%lf\t\n", this->info.id, this->info.name.c_str() ,this->chinese, this->math, this->english);
}

double JS::sum() {
    auto _sum=this->math+ this->english+ this->chinese;
    return _sum;
}

double JS::avg() {
    auto _avg = (this->sum()/(3.0));
    return _avg;
}

void JS::change_info() {
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
}

void JS::remove() {
    for(auto js = total_js_list.begin(); js != total_js_list.end(); ++js){
        auto tmp =  *js;
        if(tmp->info.id == this->info.id){
            total_js_list.erase(js);
            js_id_set.erase(this->info.id);
            printf("\nsuccess\n");
            return;
        }
    }
    printf("\nerror\n");
}

JS::JS() {}



