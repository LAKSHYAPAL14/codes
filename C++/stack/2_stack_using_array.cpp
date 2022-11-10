#include<iostream>
#include<climits>  //for INT_MIN
using namespace std;
class stackusingarray
{
 int *data;
 int nextindex;                      //nextindex jha bhi use hua hai uske baad nextindex++ tabhi kr diya gya hai
 int capacity;
 public:
 stackusingarray(int totalsize)      //totalsize have scope only to this constructort that's why is use capacity
 {
    data=new int[totalsize];       //dynamic way to initialize array
    nextindex=0;                    //if i initialize nextindex=-1 then i just have to use nextindex++ before data[nextindex] 
    capacity=totalsize;
 }
 int size()                         //return no. of elements present in my stack
 {
    return nextindex;
 }  
 bool isempty()  //onty tell stack is empty or not
 { /*
    if(nextindex==0)
    return true;
    else 
    return false; */
    return nextindex==0;
 }  
 void push(int element){
    if(nextindex==capacity)
    {
        cout<<"stackfull"<<endl;
        return;
    }
    data[nextindex]=element;
    nextindex++;
 }
 int pop()
 { if(isempty())
 {  
   cout<<" stack is empty "<<endl;
   return INT_MIN;
 }
   nextindex--; //nextindex is pointing to the next index which is empty yet
   return data[nextindex];
 }
 int top()
 {  if(isempty()){
    cout<<"stack is empty"<<endl;
    return INT_MIN;
 }
    return data[nextindex-1]; //nextindex is pointing to the next index which is empty yet
 }
};
int main()
{
   stackusingarray s(4); //we have to use s() instead of s 
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50); //will no take this one
   cout<<s.top()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.pop()<<endl;
   cout<<s.size()<<endl;
   cout<<s.isempty()<<endl;


}