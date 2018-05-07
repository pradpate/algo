/*
   Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
   unordered_map  find O(1)
   list --> erase O(1)
            pop_back O(1)
            push_front O(1)
            back O(1)
            front O(1) 
*/

#include<iostream>
#include<list>
#include<stack>
#include<iterator>
#include<unordered_map>

using namespace	std;


class lru{
   int _capacity;
   unordered_map <int, pair<int, list<int>::iterator> > map;
   list <int> q;
public:
    int get (int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        touch(it);
        return it->second.first;
   }

   void set(int key, int val) {
       auto it = map.find(key);
       if (it == map.end()) {
          if (_capacity == map.size()) {
              map.erase(q.back());
              q.pop_back(); 
          }
          q.push_front(key);
       } else {
          touch(it);
       }
       map[key] = { val, q.begin() };
   }
   void touch(unordered_map<int, pair <int, list <int>::iterator> >::iterator it) {
       q.erase(it->second.second);
       q.push_front(it->first);  
       it->second.second = q.begin();
   }

};

int main() {


}
