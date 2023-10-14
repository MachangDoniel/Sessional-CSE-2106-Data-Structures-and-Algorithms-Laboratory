//Insertion at Two way Linked List

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    node *prev;
    int info;
    node *link;
};

node *head=NULL,*temp,*tail=NULL;
void creat(int data)
{
    node *ptr;
    ptr=new node();
    ptr->prev=NULL;
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL) head=temp=ptr;
    else ptr->prev=temp,temp->link=ptr,temp=ptr;
    tail=ptr;
}

void traverse()
{
    node *ptr;
    cout<<endl<<"The Linked List stands..."<<endl;
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}

void rev_traverse()
{
    node *ptr;
    cout<<"The Reverse Linked List stands..."<<endl;
    for(ptr=tail;ptr!=NULL;ptr=ptr->prev) cout<<ptr->info<<" ";
    cout<<endl;
}

void Insert_first()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;
    node *ptr;
    ptr=new node();
    ptr->prev=NULL;
    ptr->info=data;
    ptr->link=head;
    head->prev=ptr;
    head=ptr;
}

void Insert_last()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;
    node *ptr;
    ptr=new node();
    ptr->prev=tail;
    ptr->info=data;
    ptr->link=NULL;
    tail->link=ptr;
    tail=ptr;
}

void Insert_before()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *srt,*temp,*temp2;
    for(srt=head;;srt=srt->link)
    {
        if(srt==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
        else if(srt->info==item)
        {
            if(srt==head) Insert_first();
            else
            {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                node *ptr;
                ptr=new node();
                ptr->prev=srt->prev;
                ptr->info=data;
                ptr->link=srt;
                srt->prev->link=ptr;
                srt->prev=ptr;

            }
            break;
        }
    }
}

void Insert_after()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *srt;
    for(srt=head;;srt=srt->link)
    {
        if(srt==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
        else if(srt->info==item)
        {
            if(srt==tail) Insert_last();
            else
            {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                node *ptr;
                ptr=new node();
                ptr->prev=srt;
                ptr->info=data;
                ptr->link=srt->link;
                srt->link->prev=ptr;
                srt->link=ptr;
            }
            break;
        }
    }
}

void Invalid()
{
    cout<<"Option Invalid"<<endl;
}
void Insert()
{
    system("cls");
    traverse();
    cout<<endl;
    cout<<"0. Terminate Program"<<endl;
    cout<<"1. Insert 1st position"<<endl;
    cout<<"2. Insert last position"<<endl;
    cout<<"3. Insert before an Item"<<endl;
    cout<<"4. Insert after an Item"<<endl;
    cout<<endl<<"Enter Option: ";
    int option;
    cin>>option;
    switch(option)
    {
    case 0:
        exit(0);
    case 1:
        Insert_first();
        break;
    case 2:
        Insert_last();
        break;
    case 3:
        Insert_before();
        break;
    case 4:
        Insert_after();
        break;
    default:
        Invalid();
        break;
    }
    //system("pause");
}

void initial_linked_list()
{
    int i,item,n;
    cout<<"Enter size of the Linked List: ";
    cin>>n;
    cout<<endl<<"Enter Elements..."<<endl;
    for(i=0;i<n;i++) cin>>item,creat(item);
}
int main()
{
    initial_linked_list();

    while(1)
    {
        traverse();
        rev_traverse();
        system("pause");
        Insert();
    }
}
