#include <bits/stdc++.h>

using namespace std;

class LinkedListNode {
public:
    int val;
    LinkedListNode* next;
    
    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode* tail, int val) {
    if (!head) {
        head = new LinkedListNode(val);
        tail = head;
    } else {
        LinkedListNode* node = new LinkedListNode(val);
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
    LinkedListNode* next;
};

*/
LinkedListNode* reverse(LinkedListNode* node) {
    LinkedListNode*prev = NULL;
    int count = 0;
    while (node) {
        LinkedListNode*tmp = node->next;
        node->next = prev;
        prev = node;
        node = tmp;
        count++;
        //if (count > 6) break; 
    }
    
    return prev;
    
}
LinkedListNode* zip_given_linked_list(LinkedListNode* head) {
    LinkedListNode* fast = head, *slow = head;
    if ((fast == NULL) ||  (fast->next == NULL)) return head;
    
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    LinkedListNode *nd = head; 

    while(nd->next != slow) {
        nd = nd->next;
    }
    nd->next = NULL;
    
    LinkedListNode *rev = reverse(slow);
    LinkedListNode *n = rev; 
    while (n) {
        n = n->next;
    }    

    LinkedListNode *node = head;
    int count = 0;
    while(node->next != NULL) {
        LinkedListNode *tmp1 = node->next;
        LinkedListNode *tmp2 = rev->next;

        node->next = rev;
        rev->next = tmp1; 
        node = node->next;

        node = node->next;
        rev = tmp2;
        count++;
        //if (count > 3) break; 
    }

    if (rev) {
       node->next = rev;
    }
    return head;
}

int main()
{
    ostream &fout = cout;

    int head_size;
    cin >> head_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    for (int head_i = 0; head_i < head_size; head_i++) {
        int head_item;
        cin >> head_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if (!head_i) {
            head = head_tail;
        }
    }


    LinkedListNode* res = zip_given_linked_list(head);
    int count = 0;
    while (res) {
        fout << res->val;

        if (res->next) {
            fout << "\n";
            count++;
            //if (count >6) break;
        }

        res = res->next;
    }

    fout << "\n";
    
    
    return 0;
}
