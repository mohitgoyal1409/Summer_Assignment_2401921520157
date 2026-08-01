#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

// function for seralize 
string serialize(node* root) {

    if (root == NULL)
        return "";

    queue<node*> q;
    q.push(root);

    string ans = "";

    while (!q.empty()) {

        node* front = q.front();
        q.pop();

        if (front == NULL) {
            ans += "N ";
        }
        else {
            ans += to_string(front->data) + " ";

            q.push(front->left);
            q.push(front->right);
        }
    }

    return ans;
}

// function for deserailze 
node* deserialize(string data) {

    if (data.size() == 0)
        return NULL;

    stringstream ss(data);

    string value;
    ss >> value;

    node* root = new node(stoi(value));

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        node* parent = q.front();
        q.pop();

        // Left Child
        if (!(ss >> value))
            break;

        if (value != "N") {
            parent->left = new node(stoi(value));
            q.push(parent->left);
        }

        // Right Child
        if (!(ss >> value))
            break;

        if (value != "N") {
            parent->right = new node(stoi(value));
            q.push(parent->right);
        }
    }

    return root;
}

// level order traversal of tree
void levelOrder(node* root) {

    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        node* front = q.front();
        q.pop();

        cout << front->data << " ";

        if (front->left)
            q.push(front->left);

        if (front->right)
            q.push(front->right);
    }
}

int main() {


    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    string str = serialize(root);

    cout << "Serialized Tree:\n";
    cout << str << endl;

    node* newRoot = deserialize(str);

    cout << "\nLevel Order after Deserialization:\n";
    levelOrder(newRoot);

    return 0;
}
