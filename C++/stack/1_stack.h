//in .h file is used as header file and it doesn't include main function
#include<iostream>
#include<climits>  //for INT_MIN
using namespace std;
class stackusingarray
{
 int *data;
 int nextindex; //nextindex jha bhi use hua hai uske baad nextindex++ tabhi kr diya gya hai
 int capacity;
 public:
 stackusingarray() 
 {
    data=new int[4];
    nextindex=0;
    capacity=4;
 }
 int size() //return no. of elements present in my stack
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
       int*newdata =new int [2*capacity];
       for(int i=0 ;i<capacity ;i++) //copying data array in newdata array
       {
         newdata[i]=data[i];
       }
       capacity*=2; //increasing capacity
       delete[] data; //deleting previously data array
       data=newdata;
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