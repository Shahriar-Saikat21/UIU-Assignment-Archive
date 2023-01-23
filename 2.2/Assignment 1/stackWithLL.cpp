#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{
    int value;
    Node* next;
};

Node* createNode(int data);
Node* insertHead(Node* head, Node* newNode);
Node* deleteHead(Node *head);
int listSize(Node *head);
Node* push(Node* head);
Node* pop(Node* head);
void size(Node* head);
void topElement(Node* head);
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
            head = push(head);
        }
        else if(ch == 2)
        {
            head = pop(head);
        }
        else if(ch == 3)
        {
            size(head);
        }
        else if(ch == 4)
        {
            topElement(head);
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
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. stack size\n");
    printf("4. top element\n");
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

Node* push(Node* head){
    int value;
    cout<<"enter value: ";
    cin>>value;
    head = insertHead(head,createNode(value));
    return head;
}

Node* pop(Node* head){
    if(head==NULL){
        cout<<"Nothing to delete"<<endl;
        return NULL;
    }
    cout<<head->value<<" deleted"<<endl;
    head = deleteHead(head);
    return head;
}

void size(Node* head){
    int stackSize = listSize(head);
    cout<<"Stack Size: "<<stackSize<<endl;
}

void topElement(Node* head){
    if(head==NULL){
        cout<<"Stack Empty"<<endl;
    }else{
        int element = head->value;
        cout<<"Stack size: "<<element<<endl;
    }
}