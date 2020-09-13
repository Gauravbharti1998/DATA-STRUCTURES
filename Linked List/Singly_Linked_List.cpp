//program to insert at beg, insert at end find the mid and delete an node from given position and  print a LL
//and ask the user to enter his choice
#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};
Node *HEAD = NULL;
// Head 

//   HEAD->  1 -> NULL   
//          NEW(2)     
void insertBeg()
{
    Node *NEW = new Node;
    cin >> NEW->data;
    
    if(HEAD == NULL){
        HEAD = NEW; 
        NEW->next = NULL;
    }
    else{
        NEW->next = HEAD;
        HEAD = NEW;
    }
}
// HEAD = 0
void insertAtEnd()
{
    Node*NEW= new Node;
    cin >> NEW->data;
    if(HEAD==NULL)
    {
        HEAD=NEW;
        NEW->next=NULL;
    }
    else{
        //for(Node *PTR = HEAD;PTR->next != NULL; PTR = PTR->next);
        Node *PTR = HEAD;
        while(PTR->next != NULL)
            PTR = PTR->next;
        PTR->next = NEW;
        NEW -> next = NULL;
    }
}
Node* mid() // function to find the mid node
{
    if(HEAD==NULL)   //For empty linked list
    {
        return NULL;
    }
    else if(HEAD->next==NULL)  // for linked list with one node.
    {
        return HEAD;
    }                       
    else
    {
        int count=0;
        for(Node *temp=HEAD;temp !=NULL;temp=temp->next)
        {
            count++;
        }
        int midNode=count/2;
        if(count%2!=0)
            midNode++;
        Node*temp=HEAD;
        while(midNode!=1)
        {
            temp=temp->next;
            midNode--;
        }
        return temp;
    }
}

void print()
{
    Node*temp=HEAD;
    while(temp!=NULL)
    {
        cout<<"DATA "<<temp->data<<endl;
        temp=temp->next;
    }
}
void deletenode(int pos) // delete from a given position
{
    Node*temp1=HEAD;
    if(pos==1)
    {
       HEAD=temp1->next;
        delete(temp1);
        //return;
    }
    else
    {
        for(int i=1;i<pos-1;i++) // beginning from frst and going till the prevoius node
        {
            temp1=temp1->next;
        }
        Node*temp2=temp1->next;
        temp1->next=temp2->next;
        delete(temp2);
    }
}
void deleteFromBeg()
{
    Node*temp= HEAD;
    if(HEAD!=NULL){
        HEAD=temp->next;
        //delete(temp);
        return;
    }
    else
        return;        //deletenode(1);
}

void deleteFromEnd()
{
    Node*temp=HEAD;
    if(HEAD!=NULL){
    while(temp->next!=NULL)
        temp=temp->next;
    Node*temp1=HEAD;
    while(temp1->next!=temp)
        temp1=temp1->next;
    temp1->next=NULL;
    delete(temp);
    return;
    }
    else
        return;
}

int main()
{
    Node*temp1;
    while(true)
    {
        int choice,pos;
        cout<<"SELECT OPERATION:\n1.PRINT\n2.INSERT_BEG\n3.INSERT_END\n4.QUIT\n5.MidNode\n6.Delete a node\n7.Delete from Beg\n8.Delete from end\n";
        cin >> choice;
     
       switch(choice)
        {
            case 1:
                print();
                break;
            case 2:
                insertBeg();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                return 0;
            case 5:
                temp1=mid();
                if(temp1==NULL)
                    cout<<"Error"<<endl;
                else{
                    cout<<"Mid- "<<temp1->data<<endl;
                }
                break;
            case 6:
                //print();
                cout<<"Enter the position\n";
                cin>>pos;
                deletenode(pos);
                cout<<"After deletion \n";
                print();
                break;
            case 7:
               // print();
                deleteFromBeg();
                print();
                break;
            case 8:
                //print();
                deleteFromEnd();
                print();
                break;
            default:
                cout<<"Enter right choice\n";
        }

    }
}