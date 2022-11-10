#include<iostream>
using namespace std;
class vehicle
{
    public:
    string color;
    void print()
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
    v2=&c; //through v2 we can access only those properties which are in base class.
          //base class pointer can point to child class object but vice versa is not allowed
    v1->print(); //vehicle class print get print
    v2->print(); //vehicle class print get print
}
