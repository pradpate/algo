#include<iostream>
#include<algorithm>
using namespace std;
long long int max_product_from_cut_pieces(int n) {
    /*
     * Write your code here.
     */
    vector<long long int> result(n+1, 0);
    result[0] = 0;
    result[1] = 0;
    for (int i = 1; i <= n; i++) {
        long long int  maxV = 0;
        for (int j = 1; j <= i/2; j++) {
           long long int tmp = 0;
           //tmp = j*result[i-j] > (i-j)*j ?  j*result[i-j]: (i-j)*j;
           //maxV = maxV > tmp ? maxV: tmp;
           maxV = max(maxV, j*result[i-j], (i-j)*j);
        }       
        result[i] = maxV;
        cout << "result[" << i<<"] :" << result[i] << endl; 
    }
    return result[n];

}

int main()
{
    ostream &fout = cout;

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long int res = max_product_from_cut_pieces(n);

    fout << res << "\n";

    

    return 0;
}
