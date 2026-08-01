#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top() - i;
        }

        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temperatures);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
