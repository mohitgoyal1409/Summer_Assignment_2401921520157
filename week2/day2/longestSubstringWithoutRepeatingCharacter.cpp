#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {

    unordered_map<char, int> mp;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        // If character already exists in current window
        if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
            left = mp[s[right]] + 1;
        }

        mp[s[right]] = right;

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {

    string s;
    cout << "Enter string : " << endl;
    getline(cin >> ws,s);

    cout << lengthOfLongestSubstring(s);

    return 0;
}
