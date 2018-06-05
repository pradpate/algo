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
vector <vector<int>> path(vector <vector<int> > &dp, int row, int col, int &found, vector < int > &coins, int num) {
   vector <vector<int>> result; 
   if (col == 0)  { found = 1; return result ; }
   if (col < 0)  return result;
   if (row < 0) return result;
   if ( row > 0 && dp[row - 1][col] == num) {
             
        vector <vector<int> > fromtop = path(dp, row -1, col, found, coins, num);
        for (auto each: fromtop) {
             result.push_back(each);
        }
   }
   if (col- coins[row] >= 0) {
       vector <vector<int> > fromleft = path(dp, row, col - coins[row],  found, coins, num -1); 
       for (auto each: fromleft) {
             each.push_back(coins[row]);
             result.push_back(each);
        }
       if ( found == 1 && fromleft.size() == 0)  {
          vector<int> single;
          single.push_back(coins[row]);
          result.push_back(single); 
       }
       found = 0; 
   }
   return result;
}
void makeChange(int C, vector < int > intDenominations) {

    vector <vector<int> > dp(intDenominations.size(), vector<int>(C + 1, INT_MAX));
    
   

    for (int j = 0; j < intDenominations.size(); j++) { 
        dp[j][0] = 0;
    }

    for (int j = 0; j < intDenominations.size(); j++) {
        for (int i = 1; i <= C; i++) {
             if (i >= intDenominations[j]) {
                 if (j > 0) {
                     int numC = dp[j][i - intDenominations[j]] == INT_MAX ? INT_MAX: 1 + dp[j][i - intDenominations[j]]; 
                     dp[j][i] =  min(numC,  dp[j-1][i]);  
                 } else  {
                     int numC = dp[j][i - intDenominations[j]] == INT_MAX ? INT_MAX : 1 + dp[j][i - intDenominations[j]];
                     dp[j][i] =  min(numC, INT_MAX); 
                 }
             } else {
                 if (j > 0)
                    dp[j][i] = dp[j-1][i]; 
             }
        }    
    }
    int row = intDenominations.size() - 1;
    int col = C;
    int found = 0;
    vector <vector<int>> result = path(dp, row,  col, found, intDenominations, dp[row][col]);
    reverse(result.begin(), result.end());
    for (auto each: result ) {
        int i = 0; 
        for (auto val: each) {
             cout << val;i++;
             if (i < each.size() ) cout << ",";
        }
        cout <<endl;
    }
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
