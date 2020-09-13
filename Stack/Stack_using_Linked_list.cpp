//stack using linked list
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    node* next;
    int data;
};
node* top=NULL;
void push()   //We will apply the operation of insert at beginning
{ 
    node* newnode= new node;
    cin>>newnode->data;
    if(top==NULL)
    {    
        top=newnode;
        newnode->next=NULL;
        //return;
    }
    else
    {
        newnode->next=top;
        top=newnode;
        
    }
    //cout<<top->data<<" ";
}
void pop()   //We will apply the operation as same as the deletion from beginning
{
    node*temp=top;
    if(top==NULL)
    {
        cout<<"Underflow\n";
        return;
    }
    else
    {
        cout<<top->data;
        temp=temp ->next;
        delete top;
        top=temp;
    }
}
void print()
{
    node*temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";   //But this will print in reverse order
        temp=temp->next;
    }
}
int main()
{   
    int choice;
    while(true)
    {
        cout<<"\nEnter choice\n1.Push\n2.Pop\n3.Print\n4.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: print();
            break;
            case 4: return false;
            break;
            default: cout<<"Enter valid choice\n";
        }
    }
}