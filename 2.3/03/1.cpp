#include<bits/stdc++.h>

using namespace std;

// recursive call
bool subSetSumRecur(int numbers[], int n, int sum)
{
    if (sum == 0){
        return true;
    }        
    if (n == 0){
        return false;
    }
         
    if (numbers[n - 1] > sum){
        return subSetSumRecur(numbers, n - 1, sum);
    }
  
    return subSetSumRecur(numbers, n - 1, sum) 
            || subSetSumRecur(numbers, n - 1, sum - numbers[n - 1]);
}

// DP Method
void isSubSetSum(int n, int num[], int sum){
    if(sum==0){
        cout<<sum<<" is the subset sum of no number !!"<<endl;
        return;
    }

    int arr[n+1][sum+1];
    for (int i = 0; i <=n; i++)
    {
        arr[i][0] = true;
    }
    for (int i = 1; i <=sum; i++)
    {
        arr[0][i] = false;
    }

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(j<num[i-1]){
                    arr[i][j] = arr[i - 1][j];
            }else{
                arr[i][j] = arr[i - 1][j - num[i - 1]];
            }
        }        
    }
    
    vector<int>v;
    if(arr[n][sum]){
        int i = n, j=sum;
        while(i>0 && j>0){
            if(arr[i][j]!=arr[i-1][j]){
                v.push_back(num[i]);
                i--;
                j -= num[i];
            }else{
                i--;
            }
        }
        cout<<sum<<" is the subset sum of ";
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"There is no subset sum!!!"<<endl;
    }  
}

int main(){

    int n,S;
    cin>>n;
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    cin>>S;


    // Recursive Call
    // bool result = subSetSumRecur(num,n,S);
    // if(result==1){
    //     cout<<"True"<<endl;
    // }else{
    //     cout<<"False"<<endl;
    // }

    isSubSetSum(n,num,S);
    
    return 0;
}