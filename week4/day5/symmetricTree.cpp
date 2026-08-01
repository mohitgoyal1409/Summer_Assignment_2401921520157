#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to check if two trees are mirror images
bool symmetricTree(node* r1, node* r2) {

    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    if (r1->data != r2->data)
        return false;

    bool left = symmetricTree(r1->left, r2->right);
    bool right = symmetricTree(r1->right, r2->left);

    return left && right;
}

// Wrapper function
bool isSymmetric(node* root) {

    if (root == NULL)
        return true;

    return symmetricTree(root->left, root->right);
}

int main() {


    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(2);

    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right->left = new node(4);
    root->right->right = new node(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric";
    else
        cout << "Tree is Not Symmetric";

    return 0;
}
