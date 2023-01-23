#include<bits/stdc++.h>

using namespace std;

// recursive Solution
int recursiveCake(int n, int P[]){
    if(n==0){
        return 0;
    }
    int q = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        q = max(q,P[i]+recursiveCake(n-i,P));
    }
    return q;   
}


// DP Solution
void dpCake(int n, int P[]){
    int profit[n+1],solution[n+1];
    profit[0] = 0;
    solution[0] = 0;
    int maxProfit;

    for (int i = 1; i <= n; i++)
    {
        maxProfit = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            int m = P[j] + profit[i-j-1];
            if(m>maxProfit){
                maxProfit = m;
                solution[i] = j+1;
            }
        }
        profit[i] = maxProfit;
    }

    cout<<"income : "<<maxProfit<<" taka"<<endl;

    int s = solution[n];   
    while(n>0){
        cout<<solution[s]<<" pieces together "<<P[s-1]<<" taka"<<endl;
        n -= s;
        s = solution[n];
    }
}

int main(){

    int n;
    cin>>n;

    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }    

    //cout<<recursiveCake(n,price)<<endl;

    dpCake(n,price);
    
    return 0;
}