#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <queue>
using namespace std;

vector <int> topK(vector <int> arr, int k) {
    priority_queue<int, std::vector<int>, std::greater<int> > q;
    unordered_map <int, int> map;
    for (int i = 0; i < arr.size(); i++) {
        if (q.size() < k) {
            if (map.find(arr[i]) == map.end()) {
                q.push(arr[i]);
                map[arr[i]] = 1; 
                //cout << " 1 Push " << arr[i] <<endl;
            }
        } else {
            if (map.find(arr[i]) != map.end()) {
               continue; 
            } else if (arr[i] <= q.top()) {
               //cout << "Arr  "<< arr[i] <<" Top " <<q.top() << endl; 
            } else {
                //cout << "Popping " << q.top() << endl;
                map.erase(q.top());
                q.pop();
                q.push(arr[i]);
                map[arr[i]] = 1; 
                //cout << "Push " << arr[i] <<endl;
            }
        } 
    }
    //unordered_set<int> s;
    vector<int> result;
    //cout << "K is "<< k << endl;
    while (!q.empty()) {
        //cout << "top is "<< q.top() << endl;
        result.push_back(q.top()); q.pop();
    }
    //cout << "End K is "<< k << endl;
    //vector<int> result(s.begin(), s.end()); 
    sort(result.begin(), result.end()); 
    return result; 
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

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = topK(arr, k);
    for(int res_i = 0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }

    
    return 0;
}


