//To traverse the tree
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define null INT32_MIN
// void preOrder(vector<int> &tree, int root)  //using recursion
// {
//     if(root>=tree.size() || tree[root]==null)
//         return;
//     else
//     {
//         cout<<tree[root]<<" ";  //ROOT
//         preOrder(tree,root*2 +1); //LEFT
//         preOrder(tree,root*2 +2); //RIGHT
        
//     }

// }
// 0P -> 1P -> 3P ->
void preOrderIt(vector<int> &tree){   //using array
    stack<int> STK;
    if(tree[0] != null)
        STK.push(0);
    while(!STK.empty()){
        int root = STK.top();
    
        int left = root * 2 + 1;
        int right = left + 1;
        if(left < tree.size() && tree[left] != null) {
            //left is valid
            STK.push(left);
            continue;
        }
        int prevInd = null;
        while(!STK.empty()){
            right = STK.top() * 2 + 2;
            if(prevInd == null || right != prevInd)
                cout<<tree[STK.top()]<<' ';
            
            if(right < tree.size() && tree[right] != null && right != prevInd){
                STK.push(right);
                break;
            }
            else{
                prevInd = STK.top();
                STK.pop();
            }
        }
    }
}
//  (0,8) => (1,3)
int main(){
    int size;
    cin>>size;
    vector<int> tree(size,null);  //initialising all elements to null 
    int root=0;
    while(true){ 
        int index,val;
        cin >> index >> val;
        if(index == -1)
            break;
        tree[index] = val;
    }
    preOrderIt(tree);//,root);
}