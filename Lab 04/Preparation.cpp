//Lab 04
//searching an element from linked list using binary search

#include<bits/stdc++.h>
using namespace std;

class student
{
private:
    int roll;
    string name;
public:
    student()
    {
        cout<<"Default Constructor"<<endl;
    }
    student(int r,string s)
    {
        cout<<"Parameterized Constructor"<<endl;
    }
};

int main()
{
    student s1(1907121,"Doniel Tripura"),s2,s3;
    s2(s1);
    s3=s2;
}
