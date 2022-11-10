#include<iostream>      
using namespace std;
class Motor{
    protected :
    string model;
    string color;
    float price;
    
    float EMI(float P, int R, int T){ 
        float SI = P*R*T/100;
        float emi = (P + SI) / (12*T) ;
        return emi;
    }
};
class Car : public Motor{
    public :
    Car(){
        this-> model = "Desire" ;
        this->color = "black" ;
        this->price = 800000 ;
    }
    float EMI(float P ,int R ,int T){
        R = R - 0.25 ;  // offer on rate of interest on this car
        float SI = P*R*T/100;
        float emi = (P +  SI) / (12*T) ;
        return emi;
    }
    void Print (){
cout << this->model << endl << this->color << endl<<this->price ; cout<<endl ;
     }
};
int main(){
    Car c1;
    cout<<"EMI = "<<c1.EMI(300000,15,2)<<endl;
    c1.Print() ;
    return 0;
}


