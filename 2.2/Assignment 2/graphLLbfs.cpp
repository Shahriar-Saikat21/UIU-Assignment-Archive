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

int Queue[100],qSize, front = 0, back = 0,elementCount=0;
int dElement = -99999;
void enqueue(int data){
    if(elementCount == qSize)
        cout<<"queue full"<<endl<<endl;
    else
    {
        Queue[back]=data;
        back = (back+1)%qSize;
        elementCount++;
    }
}
void dequeue(){
    if(elementCount == 0)
        cout<<"Queue empty"<<endl<<endl;
    else
    {
        dElement = Queue[front];
        front = (front+1)%qSize;
        elementCount--;
    }
}

bool isEmpty(){
    if(elementCount==0) return true;
    return false;
}


void bfs(graphNode* graphAdjacent[], int numVertice){
    int visit[100];
    for (int i = 0; i < 100; i++)
    {
        visit[i] = 0;
    }

    int countS = 0;
    enqueue(graphAdjacent[countS]->value);

    while(!isEmpty()){
        if(visit[Queue[front]]==0){
            graphNode* temp = graphAdjacent[countS]->next;
            while(temp!=NULL){
                enqueue(temp->value);
                temp = temp->next;
            }
            cout<<Queue[front]<<" ";
        }
        dequeue();
    }   
}


int main(){

    int numVertice;
    cout<<"Number of vertice: ";
    cin>>numVertice;

    graphNode* graphAdjacent[numVertice];

    graphList(graphAdjacent,numVertice);

    bfs(graphAdjacent,numVertice);

    return 0;
}