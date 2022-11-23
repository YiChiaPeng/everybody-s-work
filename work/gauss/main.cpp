#include<iostream>
#include"myNormal.hpp"
#include<vector>
#include <fstream>
#include<string.h>
using namespace std;
/*------------------------------------
three type of nomal distribution
---------------------------------------*/
myNormal *A=new myNormal(-2,sqrt(0.5));
myNormal *B=new myNormal(0.0,sqrt(0.2));
myNormal *C=new myNormal(5,1);

/*-----------------------------------
datas is come from txt file 
labels is the correspond label of each datd
-------------------------------------*/
vector<double> datas;
vector<int> labels;
/*-------------------------------
return label 1->A,2->b,3->C
---------------------------------*/
int classify(double x){
    // its High pdf to the A
    if (A->getpdf(x)>B->getpdf(x)&&A->getpdf(x)>C->getpdf(x))
    {

        return 1;

    }
    // its High pdf to the B
    else if (B->getpdf(x)>A->getpdf(x)&&B->getpdf(x)>C->getpdf(x))
    {

        return 2;
    }
    // its High pdf to the C
    else if (C->getpdf(x)>A->getpdf(x)&&C->getpdf(x)>B->getpdf(x))
    {

        return 3;

    }
    //error
    else
        return -1;
}
/*--------------------------------
counting the number of ABC type
and cout the result
---------------------------------*/
void frequency(){
    int times[4]={0};
    for (int i = 0; i <labels.size(); i++)
    {
        if (labels[i]==-1)
        {
            times[0]++;
        }else
            times[labels[i]]++;
        
    }
    cout<<"A : "<<times[1]<<" times "<<endl;
    cout<<"B : "<<times[2]<<" times "<<endl;
    cout<<"C : "<<times[3]<<" times "<<endl;
}
int main(){
    //read file "normaldata3.txt"
    ifstream ifs;
    //a double ocuupied 8 byte
    
    char buffer[256] = {0};
    double temp;

    ifs.open("normaldata3.txt");
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    } else {
        while (!ifs.eof())
        {
            ifs>>temp;
            datas.push_back(temp);
            //the default label is -1
            labels.push_back(-1);
            
        }
    }
    
    for (int i = 0; i <datas.size(); i++)
    {
        labels[i]=classify(datas[i]);

    }
    
    frequency();

    return 0;
}