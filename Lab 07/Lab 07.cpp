//check balancing

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    char info;
    node *link;
};
node *head=NULL;
void push(char data)
{
    //cout<<"push"<<endl;
    //int data;
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
    //cout<<"pop"<<endl;
    if(isempty()) cout<<"Empty"<<endl;
    else head=head->link;
}
char Top()
{
    if(isempty()) cout<<"Stack is empty"<<endl;
    else /*cout<<"Top of the stack is: "<<head->info<<endl,*/return head->info;
}
void show()
{
    node *ptr;
    cout<<"Stack: ";
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}
void invalid()
{
    cout<<"Invalid"<<endl;
}
bool iscompare(char s,char t)
{
    if(s==')' && t=='(') return 1;
    else if(s=='}' && t=='{') return 1;
    else if(s==']' && t=='[') return 1;
    else return 0;
}
bool check_bp(string s)
{
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') push(s[i]);
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            char top=Top();
            if(isempty())
                return false;
            else if(iscompare(s[i],top))
                pop();
            else
                return false;
        }
    }
    if(isempty())return true;
    else return false;
}
void user()
{
    string s;
    //getline(cin,s);
    cin>>s;
    if(check_bp(s)) cout<<"Stack is balanced."<<endl;
    else cout<<"Stack is not balanced."<<endl;
}
int main()
{
    user();
}
