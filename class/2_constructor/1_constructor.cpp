#include<iostream>
using namespace std;
class student
{ public:
  int rollno;
  private:
  int age;
  public:
  student()  //deafult constructor initialize all the data member to garbage value
  {          //whenever our default construct created inbuilt constructor get remov
   cout<<"constructor called "<<endl;
  }
  student(int rollno)  //here confusion create
  {                    //in class every function have inbuilt this pointer 
    this->rollno=rollno; //here using this we can differentiate b/w  both[]
  } 
  student (int a ,int r) //parameterized constructor
  { 
    cout<<"this "<<this<<endl;  //this is a pointer hold address of object which called it
                                //   
    cout<<"constructor 2 called "<<endl;
    age=a;
    rollno=r;
  }
  void display()
  {
    cout<<age<<" "<<rollno<<endl;
  }
  };

int main()
{ 
  student s1(10,1001);
  cout<<"address of s1"<<&s1<<endl;
 /*student s1;  //whenever object created internally s1.student() constructor call 
              //deafult constructor student() is automatically created in class
             
 student s2;
 student *s3=new student; //dynamically creation of object
 s3->display();
 student s4;
 s4.display();
 student s5(10,10);
 s5.display();
 student *s6=new student(20,101); 
 s6->display();*/
}