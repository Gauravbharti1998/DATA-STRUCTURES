//There are two methods of making stack one is using linked list and other way is using  array(static) /vector(dynamic)
#include<bits/stdc++.h>
using namespace std;
// Top -> 1 -> 2 -> 3 -> NULL
// {1,2,3}
//  T
#define SIZE 100
void push(int arr[],int a,int &top) //arr, 10 ,-1
{
    if(top==SIZE-1)
    {
        cout<<"Overflow";
        return;
    }
    else
    {
        top++;
        arr[top]=a;  //arr[top++]=a;
    }
}
int pop(int arr[],int &top)
{
    
    if(top==-1)
    {
        cout<<"Underflow\n";
        return INT32_MAX;
    }
    else
    {
        top--;
        return arr[top+1];
    }
}
void print(int arr[],int top)
{
    int i=0;
    while(i<=top)
    {
        cout<<arr[i]<<" ";
        i++;
    }
}
int main()
{
    int arr[SIZE],a=0,choice=0;
    int top=-1;
    while(true)
    {
        cout<<"\nEnter choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"enter the element to Push \n";
                cin>>a;
                push(arr,a,top);
                break;
            }
            case 2:
                cout<<"the element popped is \n";
                cout<<pop(arr,top);
                break;
            case 3: print(arr,top);
            break;
            case 4: return false;
            default: cout<<" enter rght";
        }
    }
}