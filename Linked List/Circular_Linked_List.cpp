//Singly Circular linked list
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
Node *head=NULL;
void print()
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        Node*temp=head;
        cout<<temp->data<<"\n";
        temp=temp->next;
        while(temp!=head)
        {
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
    }
}
void insertBeg()
{
    Node *temp=new Node;
    cin>>temp->data;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
    }
    else
    {
        Node *ptr=head;
        temp->next=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        head=temp;
        ptr->next=head;
    }
}
void insertEnd()
{
    Node *temp=new Node;
    cin>>temp->data;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
    }
    else
    {
        Node *ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        //ptr->next=head;
        temp->next=head;
    }
}
// void insertPos(int x)
// {
//     cin>>x;
//     for(int i=0;i<x;i++)
//     {
        
//     }
// }
void deletebeg()
{
    Node*ptr=head;
    if(head==NULL)  //empty
    {
        return;
    }
    else if(head->next==head)   //for one element ll
    {
        delete(head);
        head=NULL;
        return;
    }
    else            //for more then  one 
    {
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=head->next;
        delete(head);
        head=ptr->next;    
    }
}
void deleteEnd()
{
    if(head=NULL)
    {
        return;
    }
    else if(head->next=head)
    {
        delete(head);
        head=NULL;
    }
    else
    {
        Node *ptr=head;
        while(ptr->next->next!=head)
        {
            ptr=ptr->next;
        }
        delete ptr->next;
        ptr->next=head;
        
    }
}
// void insertPos(int x)
// {
//     if(x==1)
//     {
        
//     }
// }
int main()
{
    int choice=0,x=0,pos=0;
    while(1)
    {
        cout<<"Enter choice\n1.insert at beg\n2.Insert at position\n3.Insert at end\n4.Delete beg\n5.Delete from end\n6.exit\n7.Print\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                insertBeg();
                cout<<"Data \n";
                print();
                break;
            }
            // case 2:
            // {
            //     cout<<"Enter the position ";
            //     cin>>x;
            //     insertPos(x);
            //     cout<<"After insertion \n";
            //     print();
            //     break;
            // }
            case 3:
            {
                insertEnd();
                cout<<"After insertion\n";
                print();
                break;
            }
            case 4:
            {
                deletebeg();
                cout<<"After deletion \n";
                print();
                break;
            }
            case 5:
            {
                deleteEnd();
                cout<<"After deletion \n";
                print();
                break;
            }
            case 6:
                exit(0);
            case 7:
            {
                print();
                break;
            }
            // case 8:
            // {
            //     cout<<"Enter the position you wish to delete\n";
            //     cin>>pos;
            //     deletePos(pos);
            //     break;
            // }
            default:
                cout<<"Enter proper one\n";
        }
    }
}