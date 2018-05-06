/*
   Stack operations 
   push O(1)
   pop  O(0) 

*/


#include<iostream>
#include<list>
#include<stack>
#include<iterator>
#include<unordered_map>

using namespace	std;

class MinStack{
    stack<int> data_stack, min_stack;
public:
   void push(int val) {
      if (min_stack.top() >= val) {
           min_stack.push(val);
      }
      data_stack.push(val);
   }

   void pop() {
      if (data_stack.top() == min_stack.top()) {
         min_stack.pop(); 
      }
      data_stack.pop(); 
   }
};

int main() {


}
