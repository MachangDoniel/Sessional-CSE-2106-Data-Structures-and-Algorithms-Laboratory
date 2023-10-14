//Postfix to Prefix
//Input Given as String
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head=NULL;
void push(int data)
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
void show()
{
    node *ptr;
    cout<<"Stack: ";
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}
int convert(string s)
{
    int i,num=0,mul=1;
    for(i=s.size()-1;i>=0;i--)
    {
        int n=s[i]-'0';
        num+=mul*n;
        mul*=10;
    }
    return num;
}
void user()
{
    string s,t;
    getline(cin,s);
    int i,j;
    for(i=0;i<=s.size();i++)
    {
        if(s[i]==' ' || s[i]=='\0')
        {
            if(t.size()==1 && (t[0]=='*' || t[0]=='/' || t[0]=='+' || t[0]=='-' || t[0]=='^'))
            {
                int ob1,ob2,ans;
                ob1=top();
                if(!isempty()) pop();
                ob2=top();
                if(!isempty()) pop();
                if(t[0]=='*') ans=ob1*ob2;
                else if(t[0]=='/') ans=ob1/ob2;
                else if(t[0]=='+') ans=ob1+ob2;
                else if(t[0]=='-') ans=ob1-ob2;
                else if(t[0]=='^') ans=pow(ob1,ob2);
                push(ans);
                cout<<"Operation: "<<ob1<<t[0]<<ob2<<"="<<ans<<endl;
                show();
            }
            else
            {
                int num=convert(t);
                push(num);
                show();
            }
            t.clear();
        }
        else t+=s[i];
    }
}
int main()
{
    user();
}
