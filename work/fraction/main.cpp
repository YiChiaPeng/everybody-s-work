#include"./fraction.hpp"
int main(){
    int a[2];
    int b[2];
    char buf;
    cout<<"請輸入第一個分數"<<endl;
    cin>>a[0];
    cin>>buf;
    cin>>a[1];
    cout<<"請輸入第二個分數"<<endl;
    cin>>b[0];
    cin>>buf;
    cin>>b[1];
    fraction f1,f2;
    cout<<a[0]<<" "<<a[1]<<endl;
    cout<<b[0]<<" "<<b[1]<<endl;
    f1.setValue(a[0],a[1]);
    f2.setValue(b[0],b[1]);
    cout<<(f1+f2)<<endl;
    
    
}