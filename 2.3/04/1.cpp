#include<bits/stdc++.h>
using namespace std;

void make_set(int p[], int r[], int x){
    p[x] = x;
    r[x] = 0;
    cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x){
    if (x!=p[x])
        return find_set(p, p[x]);
    return p[x];
}

void link(int p[],int r[],int x, int y){
    if(r[x]>r[y]){
        p[y] = x;
    }else{
        p[x] = y;
        if(r[x]==r[y]){
            r[y]++;
        }
    }
}

void _union(int p[], int r[], int x, int y){
    link(p,r,find_set(p,x),find_set(p,y));
    cout << "union "<<x << " and "<<y<< endl;
}

int main(){

    int N;
    cin>>N;

    int p[N], r[N];
    for (int i=0;i<N;i++){
        make_set(p,r,i);
    }

    while(1){
        int option;
        cin>>option;

        if (option==1){
            int x;
            cin>>x;
            if(x>=0 && x<N){
                cout<<"root of "<<x<<" is "<<find_set(p,x)<<endl;
            }else{
                cout<<x<<" is not an element of the set"<<endl;
            }
        }else if (option==2){
            int x,y;
            cin>>x>>y;
            if((x>=0 && x<N)&&(y>=0 && y<N)){
                if(find_set(p,x)==find_set(p,y)){
                    cout<<x<<" and "<<y<<" are belong to the same set"<<endl;
                }else{
                    cout<<x<<" and "<<y<<" are not belong to the same set"<<endl;
                }
            }else{
                cout<<x<<" and "<<y<<" are not the element of the set"<<endl;
            }

        }else if (option==3){
            int x,y;
            cin>>x>>y;
            if((x>=0 && x<N)&&(y>=0 && y<N)){
                _union(p,r,x,y);
            }else{
                cout<<x<<" and "<<y<<" are not the element of the set"<<endl;
            }
        }else{
            return 0;
        }
    }
}