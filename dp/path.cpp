#include <bits/stdc++.h>

using namespace std;


int numberOfPaths(vector<vector<int>> a) {
    
    vector<vector< int>> ways(a.size(), vector< int>(a[0].size(),0));
    int rows  = a.size();
    int cols = a[0].size();
    for (int i = 0; i < rows; i++) {
        if (a[i][0] == 0) break;
        ways[i][0] = 1;
    }
    for (int i = 0; i < cols; i++) {
        if (a[0][i] == 0) break;

        ways[0][i] = 1;
    }    
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int top = a[i][j] == 1 ? ways[i][j-1] : 0;
            int left = a[i][j] == 1 ? ways[i-1][j] : 0;
            ways[i][j] = top + left;
            if (ways[i][j] < 0) {
                printf("Top %d left %d", top, left);
                exit(0);
            } 
       }
    }
    return ways[rows-1][cols-1];
}
#ifdef FIXME
// Complete the numberOfPaths function below.
int numberOfPathsR(vector<vector<int>> &a, int row, int col, int rows, int cols) {
    if (row > rows) return 0;
    if (col > cols) return 0;
    if (row < 0) return 0;
    if (col < 0) return 0;
    
    if (a[row][col] == 0) return 0;
    
    if (row + 1 == rows && col +1 == cols) return 1;
    return numberOfPaths(a, row + 1, col, rows, cols) + numberOfPaths(a, row, col + 1, rows, cols);
}

int numberOfPaths(vector<vector<int>> a) {
    return numberOfPaths(a, 0, 0 , a.size(), a[0].size()); 

}
#endif
int main()
{
    ostream &fout = cout;

    int a_rows;
    cin >> a_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int a_columns;
    cin >> a_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(a_rows);
    for (int i = 0; i < a_rows; i++) {
        a[i].resize(a_columns);

        for (int j = 0; j < a_columns; j++) {
            cin >> a[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = numberOfPaths(a);

    fout << res << "\n";

    

    return 0;
}
