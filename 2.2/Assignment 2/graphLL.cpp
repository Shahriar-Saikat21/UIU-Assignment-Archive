#include<bits/stdc++.h>

using namespace std;

struct graphNode{
    int value;
    graphNode* next;
};
typedef struct graphNode graphNode;

graphNode* createNode(int data){
    graphNode* temp = new graphNode();
    temp->value = data;
    temp->next= NULL;
    return temp;
}

graphNode* add(graphNode* head,int data){
    if(head ==NULL){
        head = createNode(data);
    }else{
        graphNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
    return head;
}

void printNode(graphNode* head){
    graphNode* temp = head;
    while(temp!=NULL){
        cout<< temp->value<<" ";
        temp = temp->next;
    }
}

void graphList(graphNode* graphAdjacent[],int numVertice){
    for (int i = 0; i < numVertice; i++)
    {
        graphNode* head=NULL;
        int connection;
        cout<<"Number of egdes of vertice "<<i<<" :";
        cin>>connection;
        for (int j = 0; j < connection; j++)
        {
            int data;
            cout<<"Edges of vertice "<<i<<" : ";
            cin>>data;
            head = add(head,data);
        }
        graphAdjacent[i] = head;        
    }   
}

void printGraphAd(graphNode* graphAdjacent[],int numVertice){
    cout<<"Adjacency List of given graph: "<<endl;
    for (int i = 0; i < numVertice; i++)
    {
        cout << i << "---> ";
        
        printNode(graphAdjacent[i]);

        cout << endl;
    }
    
}

int main(){

    int numVertice;
    cout<<"Number of vertice: ";
    cin>>numVertice;

    graphNode* graphAdjacent[numVertice];

    graphList(graphAdjacent,numVertice);

    printGraphAd(graphAdjacent,numVertice);

    return 0;
}