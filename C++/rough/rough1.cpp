/*#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int size;
    cout<<"enter the size of array";
    cin>>size;
    for(int i=0 ; i<size ;i++)
    {
        cin>>arr[i];
    }
    int max;
    max=arr[0];
    int index;
    for( int i=0 ; i<size ;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            index=i;
        }
    }
    cout<<" highest value at index at "<<index;
}*/
#include<iostream>
using namespace std;
int main()
{
    int A[10];
    cout<<"Enter the 10 elements of the array "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>A[i];
    }
    int min=A[0];
    int i;
    int index;
    for(i=0;i<10;i++)
    {
        if(min>A[i])
        {
            min=A[i];
            index=i;
         
        }
    }
    cout<<"The smallest element of the array is at the index: "<<index<<endl;
}