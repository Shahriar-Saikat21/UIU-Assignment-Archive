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


struct Edge{
    int u, v, w;
};

bool compare(Edge e1, Edge e2){
    return e1.w<e2.w;
}

void mst(vector<Edge> edges, int V, int E){
    int p[V],r[V];
    for (int i = 0; i < V; i++)
    {
        make_set(p,r,i);
    }
    sort(edges.begin(), edges.end(), compare);

    vector<Edge> T;
    for (int i=0;i<E;i++){
        Edge e = edges[i];
        if(find_set(p,e.u)!=find_set(p,e.v)){
            T.push_back(e);
            _union(p,r,e.u,e.v);
        }
    }
    int weight = 0;
    string s = "";
    cout<<"MST"<<endl;
    for (Edge e: T){
        cout << e.u<<" - "<<e.v<<endl;
        weight+=e.w;
        s+=to_string(e.w)+",";
    }
    cout<<"Weight: "<<s<<" = "<<weight<<endl;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for (int i=0;i<E;i++){
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    mst(edges, V, E);

    return 0;
}