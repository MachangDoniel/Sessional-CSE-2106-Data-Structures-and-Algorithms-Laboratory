//Linear Search on Linked List
//1907121
//12 May, 2022
#include<bits/stdc++.h>
using namespace std;

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
int Linear_Search(int item)
{
    int pos=1;
    node *ptr;
    for(ptr=head;;ptr=ptr->link,pos++)
    {
        if(ptr==NULL) return -1;
        else if(ptr->info==item) return pos;
    }
}

int main()
{
    int n,i,data,item,pos;
    cin>>n;
    for(i=0;i<n;i++) cin>>data,creation(data);
    traverse();
    while(1){
    cin>>item;
    pos=Linear_Search(item);
    if(pos==-1) cout<<"Item Misssing"<<endl;
    else cout<<"Position: "<<pos<<endl;
    }
}
