//Post to in by me

#include<bits/stdc++.h>
using namespace std;

#define max 10

long long stackarr[max];
int top=-1;

int isempty()
{
    if(top== -1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if(top==max-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        top+=1;
        stackarr[top]=data;
    }

}

long long pop()
{
    if(isempty())
    {
        cout<<"Underflow"<<endl;
    }
    else
    {

        long long r=stackarr[top];
        top=top-1;
        return r;

    }
}
void Top()
{
    cout<<"Top is: "<<stackarr[top]<<endl;
}
void display()
{
    cout<<"Stack is: "<<endl;
    for(int i=top; i>=0; i--)
    {
        cout<<stackarr[i]<<endl;
    }
}
long long postfix_evaluation(string s)
{

    for(int i=0 ; i<s.size() ; i++)
    {
        if(s[i]==' ' || s[i]==',')
            continue;
        else if(s[i]>='0' && s[i]<='9')
        {
            int count=1;
            int j=i+1;

            while(s[j]>='0' && s[j]<='9')
            {
                j++;
                count++;
            }
            long long num=0;
            for(int k=0 ; k<count ; k++)
            {
                int a=s[i]-'0';
                num=num*10+a;
                i++;
            }
            push(num);

        }
        else if(s[i]=='+' || s[i]== '-' || s[i]==  '*' || s[i]=='/' || s[i]=='^')
        {
            long long A,B,R;
            A=pop();
            B=pop();
            if(s[i]=='+')
            {
                R=B+A;
            }

            else if(s[i]=='-')
            {
                R= B-A;
            }


            else if(s[i]=='*')
            {
                R=B*A;
            }

            else if(s[i]=='/')
            {
                R=B/A;
            }

            else if(s[i]=='^')
            {
                R= pow(B,A);
            }

            push(R);

        }

    }
    return stackarr[top];
}

int main()
{
    string s;
    long long ans;
    cout<<"Enter postfix equation: "<<endl;
    getline(cin,s);
    ans=postfix_evaluation(s);
    cout<<"Evaluated Value is: "<<ans<<endl;

    return 0;
}
