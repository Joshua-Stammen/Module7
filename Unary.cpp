#include <iostream>
using namespace std;

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
    void operator ++() //increment prefix
    {
        ++count;
    }
};

//Main
int main()
{
    Counter c1,c2;
    cout<< "c1 = "<< c1.get_count()<<endl;
    cout<< "c2 = "<< c2.get_count()<<endl;
    //TODO ++c1
    ++c1;
    ++c2;
    cout<< "c1 = "<< c1.get_count()<<endl;
    cout<< "c2 = "<< c2.get_count()<<endl;
    //c1 = ++c2


    return 0;
}