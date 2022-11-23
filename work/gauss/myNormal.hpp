//this file is the header 
//declare the myNormal class
#include<cmath>
#define pi 3.1415926535897
#define e 2.71828182846
class myNormal
{
private:
    double mean;
    double sigma;
public:
    myNormal(double x,double y);
    double getpdf(double x);
};