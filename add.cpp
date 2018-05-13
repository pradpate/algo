
#include <bits/stdc++.h>

#include<iostream>
#include<list>
#include<stack>
#include<iterator>
#include<unordered_map>


using namespace std;

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* addNumbers(LinkedListNode* l1, LinkedListNode* l2) {


}

int main() {
    ostream &fout = cout;
    LinkedListNode* res;
    
    int _l1_size = 0;
    int _l1_item;
    LinkedListNode* _l1 = NULL;
    LinkedListNode* _l1_tail = NULL;
    cin >> _l1_size;
    int _l1_i;
    for(_l1_i = 0; _l1_i < _l1_size; _l1_i++) { 
        cin >> _l1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        if(_l1_i == 0) {
        _l1 = _insert_node_into_singlylinkedlist(_l1, _l1_tail, _l1_item);
        _l1_tail = _l1;
        }
        else {
            _l1_tail = _insert_node_into_singlylinkedlist(_l1, _l1_tail, _l1_item);
        }
    }
    
    
    int _l2_size = 0;
    int _l2_item;
    LinkedListNode* _l2 = NULL;
    LinkedListNode* _l2_tail = NULL;
    cin >> _l2_size;
    int _l2_i;
    for(_l2_i = 0; _l2_i < _l2_size; _l2_i++) { 
        cin >> _l2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        if(_l2_i == 0) {
        _l2 = _insert_node_into_singlylinkedlist(_l2, _l2_tail, _l2_item);
        _l2_tail = _l2;
        }
        else {
            _l2_tail = _insert_node_into_singlylinkedlist(_l2, _l2_tail, _l2_item);
        }
    }
    
    res = addNumbers(_l1, _l2);
    while (res != NULL) {
        fout << res->val << endl;
        
        res = res->next;
    }
    
    
    return 0;
}

