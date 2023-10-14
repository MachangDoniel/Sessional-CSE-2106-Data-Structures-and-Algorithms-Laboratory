#include<bits/stdc++.h>
using namespace std;

#define n 100

int num;
void insertion(int *a)
{
    int i,j,index,new_number;
    num++;
    cout<<"Enter index number where you want to enter value"<<endl;
    cin>>index;
    cout<<"Enter the value"<<endl;
    cin>>new_number;

    for(i=num-1;i!=index;i--)
    {
        a[i]=a[i-1];
    }
    a[index]=new_number;
}

void deletion(int *a)
{
    int i,j,index,new_number;
    num--;
    cout<<"Enter index number from where you want to delete value"<<endl;
    cin>>index;

    for(i=index;i!=num;i++)
    {
        a[i]=a[i+1];
    }
}

int main()
{
    int i,j;
    cout<<"Enter the size of array:"<<endl;
    cin>>num;
    int a[n],index;
    cout<<"Enter elements"<<endl;
    for(i=0;i<num;i++)
    {
        cin>>a[i];
    }
    while(1)
    {
        system("cls");
        cout<<"Array stands..."<<endl;
        for(i=0;i<num;i++) cout<<a[i]<<" ";
        cout<<endl;
        cout<<"Type which option you want to choose"<<endl<<"0"<<endl<<"1"<<endl<<"2"<<endl;
        cout<<"Choose 0 to terminate the program"<<endl;
        cout<<"Choose 1 to add value at any index"<<endl;
        cout<<"Choose 2 to delete value from any index"<<endl;
        int option;
        cin>>option;
        if(option==0) break;
        else if(option==1) insertion(a);
        else if (option==2) deletion(a);
        else continue;
    }
}
