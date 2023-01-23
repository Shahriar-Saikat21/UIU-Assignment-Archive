#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n==1 || n==0) return false;
    for (int i = 2; i <= n/2; i++)
    {
        if(n%i==0) return false;
    }
    return true;   
}

int countPrime(int array[], int n){
    if(n==0){
        if(isPrime(array[n])){
            cout<<array[n]<<" ";
            return 1;
        }else return 0;
    }else{
        if(isPrime(array[n])){
            cout<<array[n]<<" ";
            return 1 + countPrime(array,n-1);
        } 
        else return countPrime(array,n-1);
    }
}

int main(){

    int n;
    cin>>n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }

    cout<<endl<<"#primes="<<countPrime(array,n-1)<<endl;

    return 0;
}