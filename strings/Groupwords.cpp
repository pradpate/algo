/*
https://www.geeksforgeeks.org/print-words-together-set-characters/
*/



// C++ program to count number of strings
// of n characters with
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string genKey(string s) {
    string result;
    int num = 26;
    int c[num] = {0};
    for (int i = 0; i < s.size(); i++) {
        c[s[i] -'a']++;
    }
    for (int i = 0; i < num; i++) {
        if (c[i] != 0) {
            result.push_back('a' + i );
        }    
    }

    return result;
}

void wordsWithSameCharSet(string* words, int n) {
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < n; i++) {
        string s =  genKey(words[i]);
        map[s].push_back(words[i]);
    }
    for (auto it = begin(map); it != end(map); it++) {
        for (auto str = (*it).second.begin(); str != (*it).second.end(); str++) {
            cout << *str << " ";
        }
        cout << endl;
    }
}
int main()
{
   
    string words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle"};

    int n = sizeof(words)/sizeof(words[0]);
    wordsWithSameCharSet(words, n);
    return 0;
}

