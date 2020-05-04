/*
 * @Author: Haiming Zhang
 * @Email: zhanghm_1995@qq.com
 * @Date: 2020-04-26 22:59:58
 * @References: 
 * @Description:  Some math related calculation
 */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double rad2deg(double rad) {
    return rad * 180.0 / M_PI;
}

/**
 * @brief Determine two angle direction by calculate the cross product
 */ 
bool Inverse(double theta1, double theta2) {
    double temp = cos(theta1) * sin(theta2) - sin(theta1) * cos(theta2);
    return temp < 0;
}

double SortTheta() {
    double x = 10, y = -10;
    double angle = std::atan2(y, x);
    double angle_deg = rad2deg(angle);

    double x2 = 10, y2 = 10;
    double angle2 = std::atan2(y2, x2);
    double angle2_deg = rad2deg(angle2);

    // Whether the same directioin from minimum angle to maximum angle
    if (Inverse(std::min(angle, angle2), std::max(angle, angle2))) {
        cout<<"Inverse"<<endl;
    } else {
        cout<<"Not Inverse"<<endl;
    }
}

int main() {
    SortTheta();
}