//Stack With Linked List
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int info;
    node *link;
};
node *head=NULL,*temp;
void push()
{
    int data;
    cin>>data;
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=head;
    head=ptr;
}
bool isempty()
{
    if(head==NULL) return 1;
    else return 0;
}
void pop()
{
    if(isempty()) cout<<"Empty"<<endl;
    else head=head->link;
}
void Top()
{
    if(isempty()) cout<<"Stack is empty"<<endl;
    else cout<<"Top of the stack is: "<<head->info<<endl;
}
void show()
{
    node *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
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
