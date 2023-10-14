//Q 3 lab quiz

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    string name;
    double salary;
    int catagory;
};
void increase(node *employee,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(employee[i].catagory==3) continue;
        else
        {
            employee[i].salary+=employee[i].salary*0.05;
        }
    }
}
void display(node *employee,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<employee[i].name<<" "<<employee[i].salary<<" "<<employee[i].catagory<<endl;
    }
}

int main()
{
    int i,n;cin>>n;
    node employee[n];
    for(i=0;i<n;i++) cin>>employee[i].name>>employee[i].salary>>employee[i].catagory;
    increase(employee,n);
    display(employee,n);
}
