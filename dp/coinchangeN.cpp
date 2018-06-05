#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the function below.
 */
void makeChange(int C, vector < int > intDenominations) {

    vector <vector<int>> dp(C + 1, INT_MAX);
    
   
    cout << endl;
    dp[0] = 0;
    
    for (int i = 1; i <= C; i++) {
        for (int j = 0; j < intDenominations.size(); j++) {
            if (i >=  intDenominations[j]) {
               // cout << "i " << i <<" intDenominations[j] " << intDenominations[j]<<endl;
                int tmp =  dp[i - intDenominations[j]];
                //cout << "tmp :"<< tmp << endl;
                if (tmp != INT_MAX && (tmp + 1) < dp[i])
                     dp[i] = 1 +  tmp;
                cout << dp[i] << " : "<< i<< " Deno "<< intDenominations[j]<< endl;
            }    
        }    
    }
    for (int i = 1; i <= C; i++) {
        cout << "i " << i << " "<<dp[i] << " ";    
    }    
    cout << dp[C];
    return ;
}



int main() {
    int _C;
    cin >> _C;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _intDenominations_size;
    cin >> _intDenominations_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intDenominations;
    int _intDenominations_item;
    for(int _intDenominations_i=0; _intDenominations_i<_intDenominations_size; _intDenominations_i++) {
        cin >> _intDenominations_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intDenominations.push_back(_intDenominations_item);
    }
    
    makeChange(_C, _intDenominations);
    
    return 0;
}
