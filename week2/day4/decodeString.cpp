#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {

    stack<int> countStack;
    stack<string> stringStack;

    string currentString = "";
    int currentNumber = 0;

    for (char ch : s) {

        // Build multi-digit number
        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
        }

        // Opening bracket
        else if (ch == '[') {
            countStack.push(currentNumber);
            stringStack.push(currentString);

            currentNumber = 0;
            currentString = "";
        }

        // Closing bracket
        else if (ch == ']') {

            int repeat = countStack.top();
            countStack.pop();

            string prevString = stringStack.top();
            stringStack.pop();

            while (repeat--) {
                prevString += currentString;
            }

            currentString = prevString;
        }

        // Normal character
        else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {

    string s = "3[a2[c]]";

    cout << decodeString(s);

    return 0;
}
