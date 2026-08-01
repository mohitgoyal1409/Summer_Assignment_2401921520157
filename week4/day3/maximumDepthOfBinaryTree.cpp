
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node*createBinaryTree(node*root){

    int data;
    cout << "Enter data : " << endl;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new node(data);
    
    cout << "Enter data for left child : " << endl;
    root->left = createBinaryTree(root->left);

    cout << "Enter data for right child : " << endl;
    root->right = createBinaryTree(root->right);

    return root;
}

int maximumDepth(node*root){
    if(root == NULL)
        return 0;
    
    int left = maximumDepth(root->left);
    int right = maximumDepth(root->right);

    int ans = max(left,right) + 1;
    return ans;
}
int main(){
    node*root = NULL;
    root = createBinaryTree(root);

    int ans = maximumDepth(root);
    cout << ans << endl;
    return 0;
}
