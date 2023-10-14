//Stack With Array
#include<bits/stdc++.h>
using namespace std;

int top=-1;
int A[100005];

void push()
{
    int data;
    cin>>data;
    if(top<=100005) top++,A[top]=data;
    else cout<<"Overflow"<<endl;
}
bool isempty()
{
    if(top==-1) return 1;
    else return 0;
}
void pop()
{
    if(isempty()) cout<<"Empty"<<endl;
    else top--;
}
void Top()
{
    if(isempty()) cout<<"Stack is empty"<<endl;
    else cout<<"Top of the stack is: "<<A[top]<<endl;
}
void show()
{
    int i;
    for(i=top;i>=0;i--) cout<<A[i]<<" ";
    cout<<endl;
}
void invalid()
{
    cout<<"Invalid"<<endl;
}
int main()
{
    while(1)
    {
        system("cls");
        show();
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. Isempty"<<endl;
        cout<<"4. top"<<endl;
        int option;
        cin>>option;
        switch(option)
        {
        case 0:
            exit(0);
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            isempty();
            break;
        case 4:
            Top();
            break;
        default:
            invalid();
            break;
        }
        system("pause");
    }
}
