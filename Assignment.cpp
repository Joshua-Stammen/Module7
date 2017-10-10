// File: Assignment.cpp
// Created by Joshua Stammen on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>
using namespace std;
// Constants,Structs, Classes
// Prototypes
class Counter
{
private:
    unsigned int count; //count

public:
    Counter():count(0)  //constructor
    {};

    unsigned int get_count() //returns count
    {
        return count;
    }
    //The operator keyword is used to overload
    Counter operator ++() //increment prefix
    {
        ++count;
        Counter temp;
        temp.count = count;
        return temp;
    }
};
// Main Program Program
int main()
{
    Counter c1,c2,c3;
    cout<< "c1 = "<< c1.get_count()<<endl;
    cout<< "c2 = "<< c2.get_count()<<endl;
    ++c1;
    ++c2;
    cout<< "c1 = "<< c1.get_count()<<endl;
    cout<< "c2 = "<< c2.get_count()<<endl;

    c3 = ++c1;
    cout<< "c3 = "<< c3.get_count()<<endl;



    return 0;

}
// Function Definitions