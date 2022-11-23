//.hpp通常是定義一個類別
//只需告我定義了什麼
//實作檔放.cpp
#include<iostream>
#include<string>
using namespace ::std;
class fraction
{
private:
    //分子
    int numerator;
    //分母
    int denominator;

    //算a b
    int gcd(int a,int b);
    int icm(int a,int b);
public:
    //建構子
    fraction();
    fraction(int numerator,int denominator);
    //設定分子分母
    void setValue(int numerator,int denominator);
    static double frac_into_decimal(fraction a);
    void display(string a);

    //運算子覆載
    bool operator>(const fraction&);
    bool operator<(const fraction&);
    bool operator>=(const fraction&);
    bool operator<=(const fraction&);

    friend void operator+(const fraction);
    friend void operator-(const fraction);
    friend void operator*(const fraction);
    friend void operator/(const fraction);

    void operator=(const fraction);
    friend ostream &operator<<(ostream &s,const fraction f);


};


 