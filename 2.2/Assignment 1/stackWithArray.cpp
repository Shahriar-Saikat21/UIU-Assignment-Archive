#include<bits/stdc++.h>

using namespace std;

void menu();
void push(int stack[],int *top,int stackSize);
void pop(int stack[],int *top);
void stkSize(int *top);
void topElement(int stack[],int *top);


int main()
{
    int stack[100],ch, stackSize, top=0;
    cout<<"enter stack size: ";
    cin>>stackSize;

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            push(stack,&top, stackSize);
            
        }
        else if(ch == 2)
        {
            pop(stack,&top);
        }
        else if(ch == 3)
        {
            stkSize(&top);
        }
        else if(ch == 4)
        {
            topElement(stack,&top);
        }
        else
        {
            printf("Invalid Choice\n\n");
        }
        menu();
        printf("Enter Choice: ");
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

void push(int stack[],int *top,int stackSize){
    if(stackSize == *top)
        cout<<"stack full"<<endl<<endl;
    else
    {
        cout<<"enter value: ";
        cin>>stack[*top];
        (*top)++;
    }
}

void pop(int stack[],int *top){
    if(*top == 0)
        cout<<"stack empty"<<endl<<endl;
    else
    {
        (*top)--;
        cout<<stack[*top]<<" deleted"<<endl<<endl;
    }
}

void stkSize(int *top){
    cout<<"Stack Size: "<<*top<<endl<<endl;
}

void topElement(int stack[],int *top){
    if(*top==0){
        cout<<"Stack Empty"<<endl;
    }else{
        cout<<"Top Element: "<<stack[*top-1]<<endl;
    }
}