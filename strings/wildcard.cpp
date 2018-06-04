
// operations on Trie
#include <stddef.h>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
#include <stack>
#include <assert.h>
using namespace std;
class Solution {
public:
    bool isMatchR(string s, string p) {
       if (p.empty()) return s.empty();
 
       if (p[0] == '*') {
            if (s.empty()) {
                return isMatch(s, p.substr(1));
            } else {
                return isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(1)) || isMatch(s, p.substr(1)) ;
            }    
        } else if (p[0] == '?' || p[0] == s[0]) {
            return !s.empty() && isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }

    bool isMatch(string s, string p) {
       if (p.empty()) return s.empty();
        vector <vector<bool>>  dp(s.size() + 1, vector<bool>(p.size() +1, false));

        dp[0][0] = true;
                                  
        for (int i = 1; i <= p.size(); i++) {
            if (p[i-1] == '*')
                dp[0][i] = dp[0][i-1];    
        }
        int row = 0, col = 0;
        for (row = 1; row <= s.size(); row++) {
            for (col = 1; col <= p.size(); col++) {
                if ((p[col-1] == '?') || (p[col-1] == s[row-1])) {
                    dp[row][col] = dp[row-1][col-1]; 
                } else if (p[col-1] == '*') {
                    dp[row][col] = dp[row][col-1] || dp[row-1][col] || dp[row-1][col-1];
                }
            }
          
        }
        
        return dp[s.size()][p.size()];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
