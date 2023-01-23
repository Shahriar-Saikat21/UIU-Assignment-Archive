#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{
    int value;
    Node* next;
};


Node* createNode(int data);
Node* insertHead(Node* head, Node* newNode);
Node* insertTail(Node *head, Node *newNode);
Node* deleteHead(Node *head);
int listSize(Node *head);
Node* enqueue(Node* head);
Node* dequeue(Node* head);
void size(Node* head);
void frontElement(Node* head);
void menu();

int main(){
   
    Node* head = NULL;
    int ch;
    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            head = enqueue(head);
        }
        else if(ch == 2)
        {
            head = dequeue(head);
        }
        else if(ch == 3)
        {
            size(head);
        }
        else if(ch == 4)
        {
            frontElement(head);
        }
        else
        {
            printf("invalid choice\n\n");
        }
        menu();
        printf("enter choice: ");
        scanf("%d",&ch);
    }


    return 0;
}

void menu()
{
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. queue size\n");
    printf("4. front element\n");
    printf("0. exit\n");
}

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertHead(Node* head, Node* newNode){
    if(head != NULL){
        newNode->next = head;
    }
    head = newNode;
    return head;
}

Node* insertTail(Node *head, Node *newNode)
{
    if(head == NULL)
    {
        head = insertHead(head, newNode);
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* deleteHead(Node *head)
{
    if(head == NULL)
    {
        printf("nothing to delete\n\n");
    }
    else
    {
        Node *temp;
        temp = head;

        head = head->next;
        delete(temp);
    }

    return head;
}

int listSize(Node *head)
{
    Node *temp;
    temp = head;
    int counter = 0;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

Node* enqueue(Node* head){
    int value;
    cout<<"enter value: ";
    cin>>value;
    head = insertTail(head,createNode(value));
    return head;
}

Node* dequeue(Node* head){
    if(head==NULL){
        cout<<"Nothing to delete"<<endl;
        return NULL;
    }
    cout<<head->value<<" deleted"<<endl;
    head = deleteHead(head);
    return head;
}

void size(Node* head){
    int queueSize = listSize(head);
    cout<<"Queue size: "<<queueSize<<endl;
}

void frontElement(Node* head){
    if(head==NULL){
        cout<<"Queue empty"<<endl;;
    }else{
        int element = head->value;
        cout<<"Front element: "<<element<<endl;
    }
}