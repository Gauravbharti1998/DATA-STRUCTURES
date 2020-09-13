//doubly linked list with two pointers
//One pointer HEAD  which points to the starting node and a pointer TAIL which points to the ending element of the LL;
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    node* prev;
    node* next;
    int data;
};
node* head=NULL;
node* tail=NULL;
void print(bool reverse = false)
{
 //if reverse == false then print in usual order else print reversely
    node*temp;
    if(reverse)
    {
        temp=tail;
        while(temp!=NULL)
        {
            cout<<"Reverse Data "<<temp->data<<"\n";
            temp=temp->prev;
        }
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<"Forward DAta "<<temp->data<<endl;
            temp=temp->next;
        }
    }
}
void insertAtBeg()
{
    node* newnode= new node;
    cin>>newnode->data;
    if(head==NULL && tail==NULL)
    {
        head=newnode;
        head->prev=NULL;
        tail=newnode;
        tail->next=NULL;
        tail->prev=NULL;
        head->next=NULL;
    }
    else 
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        head->prev=NULL;  //tail will be unchanged
    }
}
void insertAtEnd()
{
    node* newnode= new node;
    cin>>newnode->data;
    if(head==NULL)
    {
        head=newnode;
        head->prev=NULL;
        tail= newnode;
        tail->next=NULL;
        tail->prev=NULL;
        head->next=NULL;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=NULL;
    }
}
void deleteBeg()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL && tail->prev==NULL)
    {
        //single node
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        node* temp=head;
        head=temp->next;
        delete temp;
        head->prev=NULL;
   }
}
void deleteEnd()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL && tail->prev==NULL)
    {
        //single node
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        tail=tail->prev;
        delete tail->next;
        tail->next=NULL;
    }
}
int main()
{
    int choice,pos=0,x=0;
    while(true)
    {
        cin>>choice;
        switch(choice)
        {
            case 1: insertAtBeg();
            break;
            case 2: insertAtEnd();
            break;
            case 3: deleteBeg();
            break;
            case 4: deleteEnd();
            break;
            case 5: 
            {    
                string str;
                cout<<"Enter the order 'forward' or 'reverse'";
                cin>>str;                    
                if(str=="forward")
                    print(false);
                else
                    print(true);
                break;
            }
            case 6:
                return false;
            default: cout<<"Enter the right choice";
        }
    }
}