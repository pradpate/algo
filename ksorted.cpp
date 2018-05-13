#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the mergeArrays function below.
 */
struct compare {
    bool operator()(pair<int,int> &n1, pair<int,int> &n2) {
        //cout <<"1st  " <<n1.first << " 2nd " << n2.first << endl; 
        return n1.first > n2.first;
    }
};
vector<int> mergeArrays(vector<vector<int> > arr) {
    /*
     * Write your code here.
     */
    
    priority_queue <pair<int, int>, vector<pair<int,int> >, compare>  pq;
    //cout << "Arr size : "<<arr.size() << endl; 
    for (int i = 0; i < arr.size(); i++) {
       pq.push({0, i});
    }

    int total = (arr[0].size() * (arr.size())); 
    vector<int> result;
    vector<int> index(arr.size(), 1);
    
    //total -= arr.size();
    //cout << "Remaining numbers " << total << endl; 
    int inserted = pq.size();
    for (int i = 0; i < total; i++) {
        pair<int, int> tmp = pq.top();
        pq.pop();
        //cout << "Push --> " << arr[tmp.second][index[tmp.second]] << " Second  --> "<< tmp.second  <<endl; 
        if (inserted < total) {
            //cout << "Push --> " << arr[tmp.second][index[tmp.second]] << " Second  --> "<< tmp.second  <<endl; 
            if (index[tmp.second] < (arr[0].size() )) {
                pq.push({arr[tmp.second][index[tmp.second]], tmp.second});
                //cout << "Push --> " << arr[tmp.second][index[tmp.second]] << " Second  --> "<< tmp.second  <<endl; 
                inserted++; 
             }
        }
        index[tmp.second]++;
        result.push_back(tmp.first); ;
        
    }
    return result;
}


int main()
{
    ostream &fout = cout;

    int arr_rows;
    cin >> arr_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int arr_columns;
    cin >> arr_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(arr_rows);
    for (int arr_row_itr = 0; arr_row_itr < arr_rows; arr_row_itr++) {
        arr[arr_row_itr].resize(arr_columns);

        for (int arr_column_itr = 0; arr_column_itr < arr_columns; arr_column_itr++) {
            cin >> arr[arr_row_itr][arr_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    vector<int> res = mergeArrays(arr);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "   "<< res_itr<<"\n";
        }
    }

    fout << "\n";

    

    return 0;
}


