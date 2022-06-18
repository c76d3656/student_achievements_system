//
// Created by Zhong on 2022/6/18.
//

#include "JS.h"
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

