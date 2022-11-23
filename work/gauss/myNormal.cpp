//the implement of myNormal class
#include"myNormal.hpp"
//construction
myNormal::myNormal(double x,double y){
    this->mean=x;
    this->sigma=y;
}
//I guess this mean Probability density function
double myNormal::getpdf(double x){
    double lefttemp=1/(sqrt(this->sigma)*sqrt(2*pi));
    double righttemp=pow(e,-1*((pow(x-this->mean,2))/(2*this->sigma)));
    return lefttemp*righttemp;
}
