#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int info;
    node *link;
};

node *head=NULL,*temp;
void creat(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL) head=temp=ptr;
    else temp->link=ptr,temp=ptr;
}

void traverse()
{
    node *ptr;
    cout<<"The Linked List stands..."<<endl;
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}

void delete_first()
{
    head=head->link;
}

void delete_last()
{
    node *ptr,*temp;
    for(ptr=head;ptr!=NULL;ptr=ptr->link)
    {
        if(ptr->link==NULL) temp->link=NULL;
        temp=ptr;
    }
}

void delete_item()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *ptr,*temp;
    for(ptr=head;;ptr=ptr->link)
    {
        if(ptr==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
        else if(ptr->info==item)
        {
            if(ptr==head) delete_first();
            else if(ptr->link==NULL) delete_last();
            else
            {
                temp->link=ptr->link;
            }
        }
        temp=ptr;
    }
}

void delete_before()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *ptr,*temp,*prev;
    for(ptr=head;;ptr=ptr->link)
    {
        if(ptr==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
        else if(ptr->info==item)
        {
            if(ptr==head) cout<<"Something went wrong."<<endl;
            else if(head->link==ptr) delete_first();
            else
            {
                prev->link=ptr;
            }
        }
        prev=temp;
        temp=ptr;
    }
}

void delete_after()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *ptr;
    for(ptr=head;;ptr=ptr->link)
    {
        if(ptr==NULL)
        {
            cout<<"NOT FOUND"<<endl;
            break;
        }
        else if(ptr->info==item)
        {
            if(ptr->link==NULL) cout<<"Something went wrong."<<endl;
            else if(ptr->link->link==NULL) delete_last();
            else
            {
                ptr->link=ptr->link->link;
            }
        }
    }
}

void Delete()
{
    system("cls");
    traverse();
    cout<<endl;
    cout<<"0. Terminate Program"<<endl;
    cout<<"1. Delete 1st position"<<endl;
    cout<<"2. Delete last position"<<endl;
    cout<<"3. Delete an Item"<<endl;
    cout<<"4. Delete before an Item"<<endl;
    cout<<"5. Delete after an Item"<<endl;
    cout<<endl<<"Enter Option: ";
    int option;
    cin>>option;
    switch(option)
    {
    case 0:
        exit(0);
    case 1:
        delete_first();
        break;
    case 2:
        delete_last();
        break;
    case 3:
        delete_item();
        break;
    case 4:
        delete_before();
        break;
    case 5:
        delete_after();
        break;
    default:
        cout<<"Option Invalid"<<endl;
        break;
    }
    system("pause");
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
        Delete();
}
