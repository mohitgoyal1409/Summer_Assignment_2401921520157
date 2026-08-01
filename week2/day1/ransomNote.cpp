#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {

    vector<int> freq(26, 0);

    // Count frequency of characters in magazine
    for (char ch : magazine) {
        freq[ch - 'a']++;
    }

    // Try to construct ransomNote
    for (char ch : ransomNote) {

        if (freq[ch - 'a'] == 0)
            return false;

        freq[ch - 'a']--;
    }

    return true;
}

int main() {

    string ransomNote = "aa";
    string magazine = "aab";

    if (canConstruct(ransomNote, magazine))
        cout << "True";
    else
        cout << "False";

    return 0;
}
