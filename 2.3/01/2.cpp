#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string str,int start, int end){
    if (str[start] != str[end])
        return false;
    else if (str[start] == str[end])
    {
        if (start <= end)return isPalindrome(str,start+1, end-1);
        else return true;
    }
}

int sumPalindrome(int x,int y){
    if(x==y){
        char s[100];
        sprintf(s, "%d", x);
        if(isPalindrome(s, 0, strlen(s)-1)){
            cout<<x<<" ";
            return x;
        }else return 0;
    }else{
        char s[100];
        sprintf(s, "%d", x);
        if(isPalindrome(s, 0, strlen(s)-1)){
            cout<<x<<" ";
            return x+sumPalindrome(x+1,y);
        }else return sumPalindrome(x+1,y);
    }
}

int main(){

    int x,y;
    cin>>x>>y;

    cout<<endl<<"sum "<<sumPalindrome(x,y)<<endl;

    return 0;
}