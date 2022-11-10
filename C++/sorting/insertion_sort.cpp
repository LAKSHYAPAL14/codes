#include<iostream>
using namespace std;
int main()
{ 
 int n ,arr[100];
 cout<<"enter size of an array\n";
 cin>>n;
 cout<<"enter elements\n";
for(int i=0 ;i<n ;i++)
{
    cin>>arr[i];     //taking array input
}
    for(int i=1 ;i<n ;i++)        //first element is always sorted thatwhy we start with i
    {   int curr_element=arr[i];   
        int j=i-1;
    while(j>=0 && arr[j]>curr_element) //here we are running loop from j=i-1 to 0 ...and compare arr[i] with all element having index j=i-1 to 0
        {   int temp=curr_element;         //if arr[j]>currentelement we do swapping
            arr[j+1]=arr[j];
            arr[j]=curr_element;
            j--;
        }      
    }
    for(int i=0 ;i<n ;i++)
{
    cout<<""<<arr[i];
}
}