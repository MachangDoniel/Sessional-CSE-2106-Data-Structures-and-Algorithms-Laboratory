//Binary Search on Linked List
//1907121
//12 May, 2022
#include<bits/stdc++.h>
using namespace std;

int mx=INT_MIN,mn=INT_MAX;
class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*temp;
void creation(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    mx=max(ptr->info,mx);
    mn=min(ptr->info,mn);
    ptr->link=NULL;
    if(head==NULL) temp=head=ptr;
    else temp->link=ptr,temp=ptr;
}
void traverse()
{
    node *ptr;
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}
node *middle(node *start,node *last)
{
    node *fast,*slow;
    slow=start;
    fast=start->link;
    while(fast!=last)
    {
        fast=fast->link;
        if(fast!=last)
        {
            slow=slow->link;
            fast=fast->link;
        }
    }
    return slow;
}
bool Binary_Search(node *head,int item)
{
    node *start=head,*last=NULL,*mid;
    do
    {
        mid=middle(start,last);
        if(mid==NULL) return 0;
        else if(mid->info==item) return 1;
        if(mid->info<item) start=mid->link;
        else last=mid;
    }while(last==NULL || last!=start);
    return 0;
}

int main()
{
    int n,i,data,item,pos;
    cin>>n;
    for(i=0;i<n;i++) cin>>data,creation(data);
    traverse();
    while(1){
    cin>>item;
    if(item>mx || item<mn) cout<<"Not Found"<<endl;
    else if(Binary_Search(head,item)) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    }
}
