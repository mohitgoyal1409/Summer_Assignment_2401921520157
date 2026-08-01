#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int index = 0;
    int i = 0;

    while (i < chars.size()) {
        char curr = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == curr) {
            count++;
            i++;
        }

        chars[index++] = curr;

        if (count > 1) {
            string cnt = to_string(count);

            for (char ch : cnt) {
                chars[index++] = ch;
            }
        }
    }

    return index;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int len = compress(chars);

    cout << "Compressed Length: " << len << endl;
    cout << "Compressed Array: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}
