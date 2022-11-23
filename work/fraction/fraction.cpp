#include"fraction.hpp"
//這是實作檔，我定義的函示真的做什麼
//是這個class的 void setValue
int gcd(int a,int b){
    while( a!=0 and b!=0 )
        {
            if( a >= b )
            {
                a = a%b;
            }
            else if( b > a )
            {
                b = b%a;
            }
        }

        if( a >= b )
        {
            return a;
        }
        else
        {
            return b;
        }
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
fraction::fraction(){
    fraction(0,0);
}
fraction ::fraction(int numerator,int denominator){
    this->numerator=numerator;
    this->denominator=denominator;
}
void fraction :: setValue(int numerator,int denominator){
    if(denominator==0){
        cout<<"分母不為零"<<endl;
        exit(0);
    }
    this->denominator=denominator;
    this->numerator=numerator;
}

double  fraction :: frac_into_decimal(fraction a){
    double tempA=a.numerator;
    double tempB=a.denominator;
    return tempA/tempB;
}
bool fraction ::operator>(const fraction &f){
    if (frac_into_decimal(*this)>frac_into_decimal(f))
    {
        return true;
    }
    else
        return false;
}
bool fraction ::operator<(const fraction &f){
    if (frac_into_decimal(*this)<frac_into_decimal(f))
    {
        return true;
    }
    else
        return false;
}
bool fraction ::operator>=(const fraction &f){
    if (frac_into_decimal(*this)>=frac_into_decimal(f))
    {
        return true;
    }
    else
        return false;
}
bool fraction ::operator<=(const fraction &f){
    if (frac_into_decimal(*this)<=frac_into_decimal(f))
    {
        return true;
    }
    else
        return false;
}

void fraction ::operator+(const fraction f){
    //分母通分
    this->denominator=this->denominator*f.denominator;
    this->numerator=this->numerator*f.denominator+f.numerator*this->denominator;
}
void fraction ::operator-(const fraction f){
    //分母通分
    this->denominator=this->denominator*f.denominator;
    this->numerator=this->numerator*f.denominator-f.numerator*this->denominator;
}

void fraction ::operator*(const fraction f){
    this->denominator=this->denominator*f.denominator;
    this->numerator=this->numerator*f.numerator;
}
void fraction ::operator/(const fraction f){
    
    this->denominator=this->denominator*f.numerator;
    this->numerator=this->numerator*f.denominator;
}

void fraction ::operator=(const fraction f){
    this->denominator=f.denominator;
    this->numerator=f.numerator;
}
ostream &operator<<(ostream &s ,fraction f) {
    if(f.numerator==0)
        //是零輸出零
        s<<0;
    else if(f.numerator%f.denominator==0)
        //整除輸出整數
        s<<int(f.numerator/f.denominator);
    else if(f.numerator/f.denominator>=1){
        //輸出帶分數
        s<<f.numerator/f.denominator;
        s<<"and";
        f.numerator=f.numerator-f.denominator;
        int gc=gcd(f.numerator,f.denominator);
        f.numerator=f.numerator/gc;
        f.denominator=f.denominator/gc;
        s<<f.numerator<<"/"<<f.denominator;
    }else{
        //普通分數
        int gc=gcd(f.numerator,f.denominator);
        f.numerator=f.numerator/gc;
        f.denominator=f.denominator/gc;
        s<<f.numerator<<"/"<<f.denominator;
    }
    return s;
}