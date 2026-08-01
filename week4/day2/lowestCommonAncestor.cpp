#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBst(node* root, int data){
    if(root == NULL){
        return new node(data);
    }

    if(data < root->data)
        root->left = insertIntoBst(root->left, data);
    else
        root->right = insertIntoBst(root->right, data);

    return root;
}

void createBst(node*& root){
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

// Search a node in BST
node* searchNode(node* root, int target){
    while(root != NULL){
        if(root->data == target)
            return root;

        else if(target < root->data)
            root = root->left;

        else
            root = root->right;
    }

    return NULL;
}

// Lowest Common Ancestor
node* lowestCommonAncestor(node* root, node* first, node* second){
    if(root == NULL)
        return NULL;

    if(root->data > first->data && root->data > second->data)
        return lowestCommonAncestor(root->left, first, second);

    else if(root->data < first->data && root->data < second->data)
        return lowestCommonAncestor(root->right, first, second);

    else
        return root;
}

int main(){

    node* root = NULL;

    createBst(root);

    int x, y;
    cout << "Enter first node value: ";
    cin >> x;

    cout << "Enter second node value: ";
    cin >> y;

    node* first = searchNode(root, x);
    node* second = searchNode(root, y);

    if(first == NULL || second == NULL){
        cout << "One or both nodes are not present in BST." << endl;
        return 0;
    }

    node* ans = lowestCommonAncestor(root, first, second);

    if(ans != NULL)
        cout << "Lowest Common Ancestor: " << ans->data << endl;
    else
        cout << "No LCA found." << endl;

    return 0;
}
