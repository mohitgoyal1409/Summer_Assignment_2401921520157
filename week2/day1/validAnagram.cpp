#include<iostream>
#include<string>
using namespace std;

bool validAnagram(string s,string t){
    if(s.size() != t.size())
        return false;

    int n = s.size();
    int freq[26] = {0};

    for(int i=0;i<n;i++)
        freq[s[i]-'a']++;

    for(int i=0;i<n;i++)
        freq[t[i]-'a']--;

    for(int i=0;i<26;i++){
        if(freq[i] != 0)
            return false;
    }
    return true;
}
int main(){
    string s,t;
    cout << "Enter two string : " << endl;
    getline(cin >> ws,s);
    getline(cin >> ws,t);

    bool ans = validAnagram(s,t);
    cout << ans << endl;

    return 0;
}
