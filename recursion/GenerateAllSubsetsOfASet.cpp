#include <bits/stdc++.h>

using namespace std;

void generate_all_subsets(vector<string> &result, string &s, int i, string tmp) {
     if (i == s.size()) {
         result.push_back(tmp);
         return;  
     }
     generate_all_subsets(result, s, i + 1, tmp);
     tmp.push_back(s[i]);
     generate_all_subsets(result, s, i + 1, tmp);
 }
 
vector <string> generate_all_subsets(string s) {
    vector <string> result;
    string tmp;
    generate_all_subsets(result, s, 0, tmp);
    return result;
     
}


int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    res = generate_all_subsets(s);
    for(int res_i = 0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }

    
    return 0;
}

