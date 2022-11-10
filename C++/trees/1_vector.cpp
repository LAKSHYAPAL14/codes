#include<iostream>
#include<vector>
using namespace std;
int main()
{  // vector<int> *vp=new vector<int>();//dynamic allocation      
    vector<int> v;                    //statically  
    v.push_back(10);   //it will check either size is full or not. if full it doubled the size and insert element from last
    v.push_back(20);   
    v.push_back(30);
    v[1]=100; 
    v[3]=1002;    //v[3] and v[4] get changed by the value 23 and 234 because according to stack memory is only up to 2 index.pushing more element from back insert just after 2
    v[4]=1234;    //[] bracket used for getting and update value not used for inserting value
    v.push_back(23);
    v.push_back(234);
    v.pop_back();
    for(int i=0 ; i<v.size() ; i++)
    {
        cout<< v[i] <<endl;
    }
    cout<<v.capacity()<<endl;  //it tells the capacity
   /* cout<<v[0]<<endl; 
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<" size "<<v.size()<<endl;
    cout<< v.at(2)<<endl;
    //cout<<v.at(6)<<endl;  //out of range*/

   
}