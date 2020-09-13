                                         //Queue using array and circular queue concept.
//  4   3   7   6   5      
//  0   1   2   3   4   
//          F  
//      R                                
#include<bits/stdc++.h>
using namespace std;
#define SIZE 5
void enqueue(int arr[],int x,int &rear,int &front)
{
    if(front==-1 && rear ==-1)  //queue is empty
    {
        front++;
        rear++;
        arr[rear]=x; 
    }
    else   //queue is not empty
    {
        if(rear>=front)
        {
            if(front==0 && rear==SIZE-1)
            {
                cout<<"Overflow\n";
            }
            else
            {
                if(rear!=SIZE-1)
                {
                    rear++;
                }
                else
                {
                    rear=0;
                }
                // rear = (rear + 1)%SIZE;
                arr[rear]=x;
            }
        }
        else //rear<front
        {
            if(rear==front-1)
            {
                cout<<"Overflow\n";
            }
            else
            {
                rear++;
                arr[rear]=x;
            }
        }
    }
    
}
int dequeue(int arr[],int &rear,int &front)
{
    int temp=0;
    if(front==-1 && rear== -1)
    {
        cout<<"underflow";
    }
    else
    {
        if(front == rear)  //single element
        {
            temp=rear;
            front = rear = -1;
        }
        else
        {
            if(front<rear)
            {
                temp=front;
                front++;
            }
            else //rear<front
            {
                // 9    8   7   6   5
                // R            F                
                if(front != SIZE-1)
                {
                    temp=front;
                    front++;
                }
                else
                {
                    temp=front;
                    front=0;
                }
            }
        }
    }
    return arr[temp];
}
void print(int arr[],int rear,int front)
{
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else
    {
        for(int i=front;i<SIZE;i++)
            cout<<arr[i]<<" ";
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[SIZE];
    int x;
    int rear=-1,front=-1;
    int choice;
    while(true)
    {
        cout<<"\nEnter the operation you wish to perform\n1.Enqueue\n2.Dequeue\n3.print\n4.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                cout<<"\nEnter the data\n";
                cin>>x;
                enqueue(arr,x,rear,front);
                break;
            case 2:
                cout<<"\nThe element dequeued is \n";
                cout<<dequeue(arr,rear,front);
                break;
            case 3:
                cout<<"\nthe queue is \n";
                print(arr,rear,front);
                break;
            case 4:    return false;
            default:cout<<"sdvggw";
        }
    }
}