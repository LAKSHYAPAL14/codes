#include<iostream>
using namespace std;
class student //template or blueprint
{ public:
 int rollno;
 int age;
};
class product  //template or blueprint
{ public:
  int id;
  int weight;
  char name[100];
};
int main()
{
  student s1; //create objects statically
  student s2;
  student s3,s4,s5;
  s1.age=24;
  s1.rollno=101;
  cout<< s1.age <<endl;
  cout<< s1.rollno <<endl;
  s2.age=20;

  student *s6=new student; //create object dynamically
  (*s6).age=24;  //initializing dynamic object value
  (*s6).rollno=104;
  s6 -> age=24;   //another way of initializing dynamic object value
  s6 ->rollno=104;
  cout<<s6->age<<endl;
  cout<<s6->rollno<<endl;
}