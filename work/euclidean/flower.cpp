#include"flower.hpp"
flower::flower(){
    flower(0,0,0,0,1);
}
flower::flower(double sepalLength,double sepalWidth,double petalLength, double petalWidth,int label){
    this->petalLength=petalLength;
    this->petalWidth=petalWidth;
    this->sepalLength=sepalLength;
    this->sepalWidth=sepalWidth;
    this->label=label;
}

ostream &operator<<(ostream &s,const flower flower) {
    s<<flower.sepalLength<<" ";
    s<<flower.sepalWidth<<" ";
    s<<flower.petalLength<<" ";
    s<<flower.petalWidth<<" ";
    s<<flower.label;
    s<<endl;
    return s;
}