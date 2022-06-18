//
// Created by Zhong on 2022/6/18.
//

#include "JK.h"

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