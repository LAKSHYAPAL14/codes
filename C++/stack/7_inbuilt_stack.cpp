#include<iostream>
using namespace std;
#include"1_stack.h"
#include<stack> //inbuilt headerfile
/*some differences
 * inbuilt header file does return any value in pop function so its return type is void   void pop()
 * isempty() function in builtin stack named as empty() 
  */
 int main()
 {   //in below function we are using inbuit  stack
    stack<int> s;  //in inbuilt works as templates
    s.push(10); 
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<< s.top() <<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;;
    cout<<s.empty()<<endl;
 }