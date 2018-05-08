#include <vector>
# include<iostream>
#include <unordered_map>
#include <list>
#include<iterator>
#include <assert.h>
#include <limits>

using namespace	std;
/*
 * Complete the function below.
 */
 
#define GET 0
#define SET 1



vector <int> implement_LRU_cache(int capacity, vector <int> query_type, vector <int> key, vector <int> value) {
   
    unordered_map <int, pair<int, list<int>::iterator> > map;
    list<int> lst;
    int index = 0;
    int current_capacity = 0;
    vector <int> result;
    int count = query_type.size();
    for (int index = 0; index < count; index++) {
       int query = query_type[index]; 
        if (query == GET) {
            auto it = map.find(key[index]);
            if (it != map.end()) {
                //touch
                lst.erase(it->second.second);
                lst.push_front(key[index]);
                it->second.second =  lst.begin();
                //return it->second.first;
                result.push_back(it->second.first);
            } else {
                result.push_back(-1);
            }
        } else if (query == SET) {
            auto it = map.find(key[index]);
            if (it != map.end()) {
                //touch
                lst.erase(it->second.second);
                lst.push_front(key[index]);
                it->second.second =  lst.begin();
                it->second.first = value[index];
                
            }  else {
                if (current_capacity == capacity) {
                    int key =   lst.back();
                    lst.pop_back();
                    map.erase(key);
                    current_capacity--;
                } 
                current_capacity++;
                lst.push_front(key[index]); 
                map[key[index]] = {value[index], lst.begin()};
                
            } 
        } else {
            cout << "Invalid query";
            assert(0);
        }

        
    }
    return result;
}

int main()
{
    ostream &fout = cout;

    vector <int> res;
    int capacity;
    cin >> capacity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    int query_type_size = 0;
    cin >> query_type_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> query_type;
    for(int i = 0; i < query_type_size; i++) {
        int query_type_item;
        cin >> query_type_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        query_type.push_back(query_type_item);
    }

    int key_size = 0;
    cin >> key_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> key;
    for(int i = 0; i < key_size; i++) {
        int key_item;
        cin >> key_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        key.push_back(key_item);
    }

    int value_size = 0;
    cin >> value_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> value;
    for(int i = 0; i < value_size; i++) {
        int value_item;
        cin >> value_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        value.push_back(value_item);
    }

    res = implement_LRU_cache(capacity, query_type, key, value);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

