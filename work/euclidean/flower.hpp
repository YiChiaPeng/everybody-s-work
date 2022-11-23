#include<iostream>
using namespace std;
class flower
{
public:
    // define a structure
    double sepalLength;
    double sepalWidth;
    double petalLength;
    double petalWidth;
    int label;


    flower();
    flower(double sepalLength,double sepalWidth,double petalLength, double petallWidth,int label);
    friend ostream &operator<<(ostream &s,const flower flower);
};