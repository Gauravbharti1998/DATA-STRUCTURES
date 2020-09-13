//Doubly circular linked list
//insertion -beg,end,pos;
//deletion  -beg,pos,end
#include<bits/stdc++.h>
using namespace std;
class node
{
    public: 
    int data;
    node *next;
    node *prev;
};
node *head=NULL;
void insertBeg()
{
    node *temp =new node;
    cin>>temp->data;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
        temp->prev=NULL;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {   //   last <-> temp -> head
        temp->next=head;
        temp->prev = head->prev;
        head->prev=temp;
        temp->prev->next=temp;
        head=temp;
    }
        
}
void insertEnd()
{
    node *temp=new node;
    cin>>temp->data;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
        temp->prev=NULL;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        head->prev->next=temp;
        temp->prev=head->prev;
        temp->next=head;
        head->prev=temp;
    }
}
void insertPos()
{
    int pos;
    cout<<"Enter the pos\n";
    cin>>pos;   
    if(pos==1)
    {
        insertBeg();
    }
    else                                                  //ISKI GAND MARUGA
    {
        node *temp=new node;
        cin>>temp->data;
        node *ptr=head;
        int count = 0;
        do {
            count++;
            ptr = ptr->next;
        } while(ptr != head && count < pos-2);
        
        if(ptr == head && count == pos-2)
            insertEnd();
        else if(ptr != head){
            temp->next=ptr->next;
            ptr->next->prev=temp;
            temp->prev=ptr;
            ptr->next=temp;
        }
    }
}
void deleteBeg()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==head)
    {
        delete head;
        head=NULL;
    }
    else 
    {
        node *ptr=head;
        head=ptr->next;
        ptr->prev->next=head;
        head->prev=ptr->prev;
        delete ptr;
    }

}
void deleteEnd()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==head)
    {
        delete head;
        head=NULL;
    }
    else
    {
        node *ptr = head->prev;
        head->prev = ptr->prev;
        ptr->prev->next=head;
        delete ptr;
    }
}
void deletePos(){}
 //To be continued

void Print()
{
    node *temp=head;
    // while(temp->next!=head)
    // {
    //     cout<<"Data "<<temp->data;
    //     temp=temp->next;
    // }
    // cout<<temp->data;
    do{
        cout<<"Data "<<temp->data<<'\n';
        temp = temp->next;
    }while(temp != head);
}
int main()
{
    int choice=0,x=0,pos=0;
    while(1)
    {
        cout<<"Enter choice\n1.insert at beg\n2.Insert at position\n3.Insert at end\n4.Delete beg\n5.Delete from end\n6.Delete pos\n7.Print\n8.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: insertBeg();
            break;

            case 2: insertPos();
            break;

            case  3:insertEnd();
            break;
            case 4: deleteBeg();
            break;
            case 5: deleteEnd();
            break;
            case 6: deletePos();
            break;
            case 7: Print();
            break;
            case 8: exit(0);
            
            default: cout<<"enter correct choice";
        }
    }
}