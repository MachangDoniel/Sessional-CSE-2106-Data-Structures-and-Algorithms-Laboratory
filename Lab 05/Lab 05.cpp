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
    cout<<"The Linked List stands..."<<endl;
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

void delete_first()
{
    head=head->link;
    head->prev=NULL;
}

void delete_last()
{
    tail=tail->prev;
    tail->link=NULL;
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
            else if(ptr==tail) delete_last();
            else
            {
                temp->link=ptr->link;
                ptr->link->prev=temp;
            }
            break;
        }
        temp=ptr;
    }
}

void delete_before()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;
    node *ptr,*temp,*temp2;
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
                temp2->link=ptr;
                ptr->prev=temp2;
            }
            break;
        }
        temp2=temp;
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
            else if(ptr->link==tail) delete_last();
            else
            {
                ptr->link=ptr->link->link;
                ptr->link->link->prev=ptr;
            }
            break;
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
    {
        traverse();
        rev_traverse();
        system("pause");
        Delete();
    }
}
