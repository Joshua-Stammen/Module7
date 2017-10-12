// File: Casting.cpp
// Created by Joshua Stammen on 10/12/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>
using namespace std;
// Constants,Structs, Classes
class Distance
{
private:
    float MTF; //meters to feet
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0), MTF(3.280833F) // 1. constructor with no arguments
    {};
    Distance(int meters):MTF(3.280833F) // 2. constructor with one argument
    {
        float fltfeet = MTF*meters; //convert to float feet
        //feet= static_cast<int> (fltfeet);
        feet = int(fltfeet);           // feet is the integer part
        inches = 12* (fltfeet - feet); // inches is what is left
    };
    Distance(int f,float i):MTF (3.280833F) // 3. constructor with two argument
    {
        feet = f;
        inches = i;
    };
    void getDistance() //get the length for user
    {
        cout<<"\nEnter feet: ";
        cin >>feet;
        cout<<"\nEnter inches: ";
        cin>>inches;
    }
    void showDistance() // display distance
    {
        cout<<feet << "\'-"<< inches <<"\'""";
    }
    Distance operator +(Distance) const; //add two distances
    void operator +=(Distance);
    operator float() const // convert to inches
    {
        float fractfeet = inches/12;
        fractfeet += static_cast<float>(feet);
        return fractfeet/MTF;
    }
};
//Return the sum
Distance Distance::operator+(Distance d2) const

{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if( i>= 12.0)
    {
        i-= 12.0;
        f++;
    }
    return Distance(f,i);
}
void Distance::operator+=(Distance d2) //add 1 distance to existing one
{
    feet += d2.feet;
    inches += d2.inches;
    if( inches>= 12.0)
    {
        inches-= 12.0;
        feet++;
    }

}
// Main Program Program

int main()
{
    Distance d1; //1. constructor
    Distance d2 (11,6.25); //2. constructor
    Distance d3 (5); //3. constructor
    //d1.getDistance();
    float mtrs;
    mtrs = static_cast<float>(d2); // user convertion operator
    cout<<"dist d2 = "<< mtrs<< " meters" <<endl;
    cout<<"Distance d1 = ";
    d1.showDistance();
    cout<<endl;
    cout<<"Distance d2 = ";
    d2.showDistance();
    cout<<endl;

    //Add binary operator support
    d3= d1 + d2;
    cout<<"Distance d3= ";
    d3.showDistance();
    cout<<endl;

    d2+= d3;
    cout<<"Distance d2= "; d2.showDistance(); cout<<endl;


    return 0;


}

// Function Definitions