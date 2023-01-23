#include<bits/stdc++.h>

using namespace std;

void gasFilling(int gasStation[],int n,int distance,int mileage){
    int m = mileage;
    for (int i = 0; i < n-1; i++)
    {
        int d = gasStation[i+1]-gasStation[i];
        m-= d;
        if(m<=d){
            cout<<"stop at gas station "<<i+1<<" ("<<gasStation[i]<<" miles)"<<endl;
            m=mileage;
        }
    }
    if((distance-gasStation[n-1])>mileage){
        cout<<"Car can not be reached at destination!!!"<<endl;
    }else{
        cout<<"Car can be reached at destination...."<<endl;
    }
}

int main(){

    int distance, mileage,n;

    cin>>distance>>mileage>>n;

    int gasStation[n];

    for (int i = 0; i < n; i++)
    {
        cin>>gasStation[i];
    }

    gasFilling(gasStation,n,distance,mileage);
    
    return 0;
}