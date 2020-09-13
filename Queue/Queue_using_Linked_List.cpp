//Queue using linked list 

//      1   2   3   4   5   
//  -1  0   1   2   3   4
//  F     
//  R
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    node* next;
    node* prev;
    int data;// node (){}
    node(){
        next = prev = NULL;
        cin >> data;
    }
};

node*front=NULL;
node*rear=NULL;
void enqueue(node *newnode)
{
    if(front == NULL && rear == NULL)   //0 element
    {
        front=newnode;
        rear=newnode;
        front->prev=NULL;
        rear->next=NULL;
    }
    else if(front==rear)        //single element
    {
        front->next=newnode;
        newnode->prev=front;
        rear=newnode;
        rear->prev=front;
        front->prev=NULL;
        rear->next=NULL;
    } 
    else                //more than one element
    {
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
        rear->next=NULL;
    }
}
node* dequeue()
{
    if(front==NULL && rear==NULL)  //0 element
    {
        return NULL;
    }
    else if(front == rear)      // single element
    {
        node *temp = front;
        front=NULL;
        rear=NULL;
        return temp;
    }
    else    //more than one element
    {
        node*temp=front->next;
        swap(temp,front);
        return temp;
    }

}
void print()
{   
    if(front==NULL && rear==NULL)
        cout<<"\nQueue is empty\n";
    else
    {
        node*temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
int main()
{
    int choice;
    node *delNode=NULL;
    while(true)
    {
        cout<<"\nEnter your choice\n1. Enqueue\n2. dequeue\n3. Print\n4. quit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: enqueue(new node);
            break;
            case 2:
                delNode = dequeue();
                //cout<<dequeue()->data<<'\n';
                if(delNode!=NULL)
                    cout<<delNode->data<<" ";
                else
                    cout<<"UnderFlow";
                break;
            case 3: print();
            break;
            case 4: return false;
            default: cout<<"gggsg";
        }
    }
}