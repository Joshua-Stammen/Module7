// File: BinaryOperator.cpp
// Created by Joshua Stammen on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>
using namespace std;
// Constants,Structs, Classes
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) // constructor with no arguments
    {};
    Distance(int f,float i) //constructor with two argument
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
// Prototypes


// Main Program Program

int main()
{
    Distance d1;
    Distance d2 (11,6.25);
    Distance d3;
    d1.getDistance();
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


    return 0;


}
// Function Definitions