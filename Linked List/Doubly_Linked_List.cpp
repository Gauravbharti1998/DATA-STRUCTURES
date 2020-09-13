//Doubly linked list
//here we have to link a forward node along with a backward node 
#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
    node *next,*prev;
    int data;
};
node *head=NULL;
void print()
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<"Data "<<temp->data<<endl;
        temp=temp->next;
    }
}
void insertEnd()
{
    node*temp=new node;
    cin>>temp->data;
    if(head==NULL)
    {

        head=temp;
        temp->next=NULL;
        temp->prev=NULL;
    }
    else
    {
        node*ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        //ptr->data == 10. temp->data = 15
        ptr->next=temp;
        temp->prev=ptr;
       temp->next=NULL;
        //1->2->3->4<->5->/0
        //        ptr temp
    }
}
void insertBeg()
{
    node*temp=new node;
    cin>>temp->data;
    if(head==NULL)
    {
        //temp->next=head;
        head=temp;
        temp->next=NULL;
        temp->prev=NULL;
        
    }
    else
    {
        temp->next=head;
        //head is the second element and temp is the first
        head->prev = temp;    
        head=temp;
        //head is first here
        head->prev = NULL;
    }
}
void insertPos(int x)
{
    node*temp=new node;
    cin>>temp->data;
    node*ptr=head;
    if(x==1)
    {
        //after insertion temp = first element, head = second element
        head->prev=temp;
        temp->next=head;
        head=temp;
        return;
    }
    for(int i=1;i<x;i++)
    {
        ptr=ptr->next;
    }
    if(ptr->next!=NULL)
    {
        temp->next=ptr->next;
        temp->next->prev = temp; 
        ptr->next=temp;
        temp->prev=ptr;
    }
    else
    {
        //temp=last node and ptr will be the second last node.
        temp->next=NULL;
        temp->prev=ptr;
        ptr->next=temp;
    }

}
void deleteBeg()
{
    node*temp=head;
    if(head == NULL)            
    {
        return;
    }
    else
    {
        
        temp = temp->next;
        temp->prev=NULL;
        delete(head);
        head=temp;
        //or
        // head=head->next;
        // head->prev=NULL;
        // delete(temp);

    }
}
void deleteEnd()
{
    node*temp=head;
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        head=NULL;
    }
    else
    { 
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
   // temp->prev=NULL;
        delete(temp);
    }
}
void deletePos(int x)
{
    node*temp= head;
    if(x==1)
    {
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        return;
    }
    else
    {     
        for(int i=1;i<x;i++)
        {
            temp=temp->next;
        }
    }
    if(temp->next == NULL)
    {
        temp->prev->next=NULL;
        //temp->prev=NULL;
        delete(temp);
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete(temp);
    }
}
int main()
{
    int choice,x=0,y=0;
    
    while(true)
    {
        cout<<"Enter choice\n 1.Insert at beginning\n 2.Print\n3.exit\n4.InsertEnd\n5.Insert at Pos\n6.DeleteBeg\n7.DeleteEnd\n8.Deletefrom Pos\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                insertBeg();
                break;
            case 2:   
                print();
                break;
            case 3:
                return 0;
            case 4:
                insertEnd();
                break;
            case 5:
                cout<<"Enter position\n";
                cin>>x;
                insertPos(x);
                print();
                break;
            case 6:
                deleteBeg();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                cout<<"Enter pos\n";
                cin>>y;
                deletePos(y);
                break;
            default: 
                cout<<"Enter proper\n";
        
        }
    }
}