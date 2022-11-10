// virtual function is an example of runtime polymorphism
#include<iostream>
using namespace std;
class vehicle
{
    public:
    string color;
    virtual void print() //normal virtual function let v2 class pointer to print print() of class car. 
    {
      cout<<"vehicle"<<endl;
    }
};
class car : public vehicle
{
  public:
  int numgears;
 void print()  //vehicle print get override
  {         
    cout<<"car"<<endl;
  }
};
int main()
{
    vehicle v;
    car c; 
    v.print();
    c.print(); //car class function get print because we are making decision at compile time whoseever the function related to that class get print
    vehicle *v1 =new vehicle;
    vehicle *v2; //base class pointer
    //v2=&v;
    v2=&c;  // or vehicle *v2=new car;    //through v2 we can access only those properties which are in base class.
            //base class pointer can point to child class object but vice versa is not allowed
    v1->print(); //vehicle class print get print
    v2->print(); //car class print get print because we check that at runtime which class v2 point to.
                 //if car class print() is not there then vehicle class print function get print
                 //if vehicle class print() is not there and car class print() is there or not ,then error come.
}