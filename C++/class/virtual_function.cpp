#include<iostream>
using namespace std;
class vehicle // vehicle class is abstract class because any class containing pure virtual function is called abstract class
{             // here abstarct means incompleteness
 public:      //we cannot create object of abstract class because when object created copy of datamember and function created but print function is incomplete here
 string color;
 virtual void print()=0; //pure virtual function -> pure virtual function is an incomplete function.because it doesnot contain defination
};
class car :public vehicle
{
    public:
    int numgears;
    void print() //here print function get implemented
    {
        cout<<"car"<<endl;
    }
};
int main()
{

}