
#include"flower.hpp"

#include<vector>
#include <fstream>
#include<string.h>
#include<cmath>
#include <algorithm>
#include<set>
#define maxdouble 1000


/*-----------------------------------
datas is come from txt file 
labels is the correspond label of each datd
-------------------------------------*/
vector<flower> datas;
vector<double>distances;
vector<double>temp;
int acc1=0;
int acc2=0;
int acc3=0;


//to count the distance of each data
double euclidean(flower a,flower b){
    return sqrt(pow((a.sepalLength-b.sepalLength),2)+pow((a.sepalWidth-b.sepalWidth),2)+pow((a.petalLength-b.petalLength),2)+pow((a.petalWidth-b.petalWidth),2));
}
/*--------------------------------------------------------------------
return the min element ' s index
---------------------------------------------------------------------*/



void count_distance(int j){
    for (int i = 0; i < datas.size(); i++)
    {   //do not need compare with its self  
        //when the distance j to j is zero  
        distances.push_back(euclidean(datas[j],datas[i]));
        temp.push_back(euclidean(datas[j],datas[i]));
    }
    //the distance of itself must 0
    //so let it become largest 
    distances[j]=maxdouble;
    temp[j]=maxdouble;

}
int find_min(vector<double>temp){

    double min=temp[0];
    int index=0;
    for (int i = 1; i < temp.size(); i++)
    {   
        if (min>temp[i])
        {
            min=temp[i];
            index=i;
        }
        
    }

    return index;
    
}
int find_max(vector<int>temp){
    double max=temp[0];
    int index=0;
    for (int i = 0; i < temp.size(); i++)
    {   
        if (max<temp[i])
        {
            max=temp[i];
            index=i;
        }
        
    }
    return index;
    
}

int vote(vector<int> indexs){
    vector<int> vote(4);
    for (int i = 0; i < indexs.size(); i++)
    {
        if (datas[indexs[i]].label==1)
        {
            vote[1]++;
        }
        else if (datas[indexs[i]].label==2)
        {
            vote[2]++;
        }
        else if (datas[indexs[i]].label==3)
        {
            vote[3]++;
        }
    }
    return find_max(vote);
}
/*--------------------------------------------------------------------
i mean the unkonw datas[j] is process comparing with ohter 149 data
---------------------------------------------------------------------*/
void classify(int j){
    
    
    

    
    //build the distance table
    count_distance(j);
    
    vector<int>indexs;
    //K=1
    
    indexs.push_back(find_min(temp));
    temp[find_min(temp)]=maxdouble;
    //mean its right
    if(datas[indexs[0]].label==datas[j].label)
        acc1++;

    //K=3
    indexs.push_back(find_min(temp));
    temp[find_min(temp)]=maxdouble;
    indexs.push_back(find_min(temp));
    temp[find_min(temp)]=maxdouble;
    //now there most three smallest distance index inside
    //vote deside which type is j

    if(vote(indexs)==datas[j].label)
        acc2++;

    //K=5
    indexs.push_back(find_min(temp));
    temp[find_min(temp)]=maxdouble;
    indexs.push_back(find_min(temp));
    temp[find_min(temp)]=maxdouble;
    if(vote(indexs)==datas[j].label)
        acc3++;

}

int main(){
    //read file "irisdataset.txt"
    ifstream ifs;
    //a double ocuupied 8 byte
    int intTemp;
    double doubleTemp;
    flower tempBuf;

    ifs.open("irisdataset.txt");
    if (!ifs.is_open()) {
        cout << "Failed to open file.\n";
    } else {
        while (!ifs.eof())
        {
            ifs>>tempBuf.sepalLength;
            ifs>>tempBuf.sepalWidth;
            ifs>>tempBuf.petalLength;
            ifs>>tempBuf.petalWidth;
            ifs>>tempBuf.label;
            
            //put data into array
            datas.push_back(tempBuf);
            
        }
    }

    for (int i = 0; i < datas.size(); i++)
    {
        distances.clear();
        temp.clear();
        classify(i);
    }
    
    cout<<"When K=1 , correct"<<acc1<<" times ,and the acc1 : "<<acc1*100/datas.size()<<"%"<<endl;
    cout<<"When K=3 , correct"<<acc2<<" times ,and the acc2 : "<<acc2*100/datas.size()<<"%"<<endl;
    cout<<"When K=5 , correct"<<acc3<<" times ,and the acc3 : "<<acc3*100/datas.size()<<"%"<<endl;


    return 0;
}