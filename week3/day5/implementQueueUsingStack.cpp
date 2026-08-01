#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();

        return ans;
    }

    int peek() {

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {

    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl; // 1
    cout << q.pop() << endl;  // 1
    cout << q.pop() << endl;  // 2

    return 0;
}
