                                                        //DFS traversal of BST

#include<iostream>
using namespace std;
class Bst
{
    public:
    Bst* left;
    Bst* right;
    int data;
    Bst(int data)
    {
        this->data=data;
        left= NULL;
        right=NULL;
    }
};
Bst *insert(Bst *root,int data)
{
    if(root==NULL)
    {
        Bst* newnode = new Bst(data);
        root = newnode;
    }
    else if(data < root->data)
    {
        root->left = insert(root->left,data); //means the inserted newnode which will come after return will be reflected in root ->left 
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;
}
Bst* minRight(Bst *root)
{
    while(root->left!= NULL)
    {
       root = root->left;
    }
    return root;
}
Bst *deleteNode(Bst *root,int node)
{
    if(root==NULL)
        return NULL;
    else if(root->data > node)
        root->left = deleteNode(root->left,node);
    else if(root->data < node)
        root->right= deleteNode(root->right,node);
    else 
    {
        if(root->right==NULL && root->left==NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left ==NULL)
        {
            Bst *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Bst *temp = root;
            root=root->left;
            delete temp;
        }
        else
        {
            Bst *temp = minRight(root->right);
            root->data=temp->data;
            root->right= deleteNode(root->right,temp->data);   
        }
    }
    return root;
}
bool search(Bst *root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data < root->data)
        return search(root->left,data);
    else 
        return search(root->right,data);
}
void print(Bst *root)
{
    if(root==NULL)
        return;
    else 
    {
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}
int main()
{
    Bst *root=NULL;
    while(true)
    {
        int choice;
        cout<<"Enter the operation you wish to perform\n1.Insert a node\n2.Delete a Node\n3.Search a node in BST\n4.Print the BST\n5.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int data;
                cout<<"Enter the data you wish to insert\n";
                cin>>data;
                root = insert(root,data);
                break;
            }
            case 2:
            {
                int node;
                cout<<"Enter the node you want to delete\n";
                cin>>node;
                root = deleteNode(root,node);
                break;
            }
            case 3:
            {
                int data;
                cout<<"Enter the data you wish to search in the BST\n";
                cin>>data;
                search(root,data)?cout<<"Node Present\n":cout<<"No such node\n";
                break;
            }
            case 4:
            {
                cout<<"The B.S.T in preorder is as follows-\n";
                print(root);
                break;
            }
            case 5: 
                return false;
        }
    }
}