//Infix to postfix

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
    //int data;
    //cin>>data;
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
    if(isempty()) cout<<"Stack is empty."<<endl;
    else head=head->link;
}
int top()
{
    if(isempty()) return 0;
    else return head->info;
}
bool IsOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) return 1;
    else return 0;
}
bool IsOperand(char c)
{
    if(( c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else return 0;
}
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}
bool prec(char op1, char op2)
{
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if(p1>=p2) return 1;
    else return 0;
}
string IntoPost(string in)
{
    string post;
    char c;
    for(int i = 0; i<in.length(); i++)
    {
        c = in[i];

        if(c == ' ')
            continue;
        else if(c == '(' || c=='{' || c=='[')
            push(c);
        else if(IsOperand(c))
            post += c;
        else if(IsOperator(c))
        {
            while(prec(top(), c))
            {
                post += top();
                pop();
            }
            push(c);
        }
        else if((c==')' || c=='}' || c==']'))
        {
            while(top() != '(' && top()!='{' && top()!='[')
            {
                post += top();
                pop();
            }
            pop();
        }
    }
    return post;
}
int main()
{
    string in="(X*Y+Z/(A+B-C)*D+E*F/G)";
    //cout << " Enter Expression: ";
    //cin >> in;
    string post=IntoPost(in);
    cout<<post<<endl;;
    return 0;
}
