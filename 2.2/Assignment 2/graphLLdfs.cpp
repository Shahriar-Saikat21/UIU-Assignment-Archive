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

int Stack[100];
int top=0,element = 0;

void push(int data){
   
    Stack[top] = data;
    top++; 
    element++;    

}

void pop(){
    if(element==0){
        cout<<"Queue is empty\n";
    }else{
          top--; 
          element--; 
    }
}

bool isEmpty(){
    if(element==0) return true;
    else return false;
}

void dfs(graphNode* graphAdjacent[], int numVertice){

    int visit[100];
    for (int i = 0; i < 100; i++)
    {
        visit[i] = 0;
    }

    push(0);
    int count = 0;
    while(!isEmpty()){
        graphNode* temp = graphAdjacent[count];
        if(visit[top]==0){
            while(temp!=NULL){
                push(temp->value);
                temp = temp->next;
            }
            visit[top] = 1;
            cout<<Stack[top]<<" ";
            count++;
            pop();
        }
    }
  
}


int main(){

    int numVertice;
    cout<<"Number of vertice: ";
    cin>>numVertice;

    graphNode* graphAdjacent[numVertice];

    graphList(graphAdjacent,numVertice);

    dfs(graphAdjacent,numVertice);

    return 0;
}