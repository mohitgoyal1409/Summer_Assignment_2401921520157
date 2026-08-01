#include <iostream>
#include <vector>
#include <unordered_map>
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

node* solve(vector<int>& preorder, int& preIndex, int inStart, int inEnd,
            unordered_map<int, int>& mp) {

    // Base Case
    if (preIndex >= preorder.size() || inStart > inEnd)
        return NULL;

    // Current root
    int element = preorder[preIndex++];
    node* root = new node(element);

    // Find root position in inorder
    int position = mp[element];

    // Construct left subtree
    root->left = solve(preorder, preIndex, inStart, position - 1, mp);

    // Construct right subtree
    root->right = solve(preorder, preIndex, position + 1, inEnd, mp);

    return root;
}

node* buildTree(vector<int>& preorder, vector<int>& inorder) {

    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int preIndex = 0;

    return solve(preorder, preIndex, 0, inorder.size() - 1, mp);
}

// Inorder Traversal
void inorderTraversal(node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal
void preorderTraversal(node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    node* root = buildTree(preorder, inorder);

    cout << "Preorder : ";
    preorderTraversal(root);

    cout << endl;

    cout << "Inorder  : ";
    inorderTraversal(root);

    return 0;
}
