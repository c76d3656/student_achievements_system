//
// Created by Zhong on 2022/6/18.
//

#include "College.h"

void College::achievement_show() {
    printf("major in %\ts", this->major.c_str());
    printf("%lf\t%lf\t%lf\t\n", this->english, this->program_design, this->ad_math);
}

double College::sum() {
    auto _sum = this->english+this->program_design+this->ad_math;
    return _sum;
}

double College::avg() {
    auto _avg = this->sum()/(3,0);
    return _avg;
}
