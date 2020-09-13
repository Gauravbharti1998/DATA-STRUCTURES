                                                                            //LEVEL ORDER TRAVERSAL
                                                                            //Breadth first traversal BST
#include<iostream>
#include<queue>
using namespace std;
class BstNode{
    public:
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int data)    //constructor to initialise objects
    {
        this->data=data;
        left=right=NULL;
    }
};
BstNode* insert(BstNode *root,int data)   //insert a newnode
{
    if(root ==NULL)
    {
        BstNode *newnode  = new BstNode(data);   //a new object of class BstNode is made and it uses the attributes of class so the constructor is there to initialise the object
        root= newnode;
    }
    else if(data < root->data)  
        root->left=insert(root->left,data);   //root->left is written so as to register the changes done in left side of tree
    else
        root->right =  insert(root->right,data);
    return root;
}
void LevelOrdertraverse(BstNode *root)  //same as print  for traversing in level order
{
    if(root==NULL)
        return;
    queue<BstNode*>q;     // a Queue is made using STL (check header file)  
    q.push(root);         //in this we are gonna push the root node first and then the respective nodes
    while(q.empty()==false)    //ending condition
    {
        BstNode *temp= q.front();     //as the queue is BstNode* it will contain *node values so to access them we made a temp *node to take the front value & process it
        cout<<temp->data<<" ";
        if(temp->left!=NULL)         //if there is a left child we will push its *node in the queue
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right); 
        q.pop();        //we will pop the front node at the end according to FIFO
    }
}
int main()
{
    BstNode *root=NULL;
    while(true)
    {
        int choice;
        cout<<"Enter the operation you wish to perform\n1.Insert into tree\n2.Print\n3.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    int data;
                    cout<<"Enter the value\n";
                    cin>>data;
                    root=insert(root,data);    //recieving the changes in root;
                    break;
                }
            case 2:
                LevelOrdertraverse(root);   //for traversing level order and printing
                break;
            case 3:
                return false;
        }
    }
}