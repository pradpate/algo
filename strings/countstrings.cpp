/*
https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/
-std=c++11
g++ -std=c++11 countstrings.cpp
*/

// C++ program to count number of strings
// of n characters with
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// n is total number of characters.
// bCount and cCount are counts of 'b'
// and 'c' respectively.
void countStr(string s, int n, int index, unordered_map<int, int> map, 
     string tmp, vector<string> &result, int count) {
    if (n == 0) {cout << tmp<< endl;result.push_back(tmp); return;}
    if (index != -1)
        map[index]--;
    for (int i = 0; i < count; i++) {
        if (map[i] == 0) continue;
        
        countStr(s, n-1, i, map, tmp + s[i], result, count);
    }
    return;
}
int countStr(int n, int bCount, int cCount)
{   unordered_map<int, int> map;
    vector<string> result;
    string s = "abc";
    map[0] = n;
    map[1] = bCount;
    map[2] = cCount;
    string tmp;
    countStr(s, n, -1,map,tmp,result, n);
    
    return result.size();
}

// Driver code
int main()
{
    int n = 3; // Total number of characters
    cout << countStr(n, 1, 2);
    return 0;
}

