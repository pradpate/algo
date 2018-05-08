/* Longest Valid Parentheses*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int find_max_length_of_matching_parentheses(string brackets) {
    stack<int> stk;
    int result = 0;
    if (brackets.size() == 0) return result;
    stk.push(-1);
    for (int i = 0; i < brackets.size(); i++) {
        int top = stk.top();
        if ((top != -1) && (brackets[top] == '(') && (brackets[i] == ')')) {
            stk.pop();
            result = max(result, i - stk.top());
        } else {
            stk.push(i);
        }
        
    }
    return result;
}


int main()
{
    ostream &fout = cout;

    int res;
    string brackets;
    getline(cin, brackets);

    res = find_max_length_of_matching_parentheses(brackets);
    fout << res << endl;

    
    return 0;
}

