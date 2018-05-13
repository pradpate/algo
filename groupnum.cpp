#include <bits/stdc++.h>

using namespace std;


vector <int> solve(vector <int> arr) {
   int sz = arr.size();

   int even_index = 0;
   for (int i = 0; i < sz; i++) {
       if (arr[i]%2 == 0) {
           swap(arr[even_index], arr[i]);
           cout << "arr[even_index  "  << arr[even_index] <<" arr[i] " << arr[i] << " i " << endl;
           even_index++;
       }
   }
   return arr;
}



int main()
{
    ostream &fout = cout;

    vector <int> res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> arr;
    for(int i = 0; i < arr_size; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    res = solve(arr);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

