#include<bits/stdc++.h>

using namespace std;

struct Item{
    string itemName;
    int v,w;
    double unitPrice;
};

bool comp(Item i1,Item i2){
    if (i1.unitPrice > i2.unitPrice)
        return true;
    else
        return false;
}

void fracKanpsack(Item items[], int n, int totalItemWeight,int numTheif,int theifKnapsack[]){
    sort(items,items+n,comp);

    int i = 0, weightLeft = totalItemWeight;
    while(i<numTheif){
        double profit = 0;
        int capacity = theifKnapsack[i], j = 0;
        while(capacity>0 && j<n){
            double vi = items[j].v;
            double wi = items[j].w;
            if(wi<=capacity && wi>0){
                profit += wi*items[j].unitPrice;
                capacity -= wi;
                weightLeft -=wi;
                items[j].w -=wi;
                cout<<"Taking "<<items[j].itemName
                    <<" : "<<wi<<" kg "<<wi*items[j].unitPrice
                    <<" taka"<<endl;
            }else if(wi>capacity && wi>0){
                profit += (capacity*items[j].unitPrice);
                cout<<"Taking "<<items[j].itemName
                    <<": "<<capacity<<" kg "<<capacity*items[j].unitPrice
                    <<" taka"<<endl;
                weightLeft -=capacity;
                items[j].w -=capacity;
                capacity = 0;
            }
            j++;
        }
        cout<<"Theif "<<i+1<<" profit : "<<profit<<" taka"<<endl<<endl;
        i++;
    }
    cout<<"Total "<< numTheif<<" thieves stole from the warehouse."<<endl;
    if(weightLeft!=0){
        cout<<"Still following items are left"<<endl;
        for (int i = 0; i < n; i++)
        {
            if(items[i].w!=0){
                cout<<items[i].itemName<<" "<<items[i].w<<" kg "
                <<items[i].w*items[i].unitPrice<<" taka"<<endl;
            }
        }        
    } 
}

int main(){

    int n;
    cin>>n;

    Item items[n];

    int totalItemWeight = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>items[i].itemName;
        cin>>items[i].v>>items[i].w;
        totalItemWeight+=items[i].w;
        items[i].unitPrice = (double)items[i].v/items[i].w;
    }

    int numTheif;
    cin>>numTheif;
    int theifKnapsack[numTheif];
    for (int i = 0; i < numTheif; i++)
    {
        cin>>theifKnapsack[i];
    }
    
    cout<<endl;
    fracKanpsack(items,n,totalItemWeight,numTheif,theifKnapsack);

    return 0;
}