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

void insert_first()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=head;
    head=ptr;
}

void insert_last()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    for(temp=head;temp!=NULL;temp=temp->link)
    {
        if(temp->link==NULL)
        {
            temp->link=ptr;
            break;
        }
    }
}

void insert_after()
{
    int item;
    cout<<"Enter item: ";
    cin>>item;

    for(temp=head;;temp=temp->link)
    {
        if(temp==NULL)
        {
            cout<<"NOT FOUND"<<endl;
        }
        else if(temp->info==item)
        {
            if(temp->link==NULL) insert_last();
            else
            {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                node *ptr;
                ptr=new node();
                ptr->info=data;
                ptr->link=temp->link;
                temp->link=ptr;
            }
            break;
        }
    }
}

void insert_before()
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
        }
        else if(ptr->info==item)
        {
            if(ptr==head) insert_first();
            else
            {
                int data;
                cout<<"Enter data: ";
                cin>>data;
                node *srt;
                srt=new node();
                srt->info=data;
                srt->link=ptr;
                temp->link=srt;
            }
            break;
        }
        temp=ptr;
    }
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

void Insert()
{
    system("cls");
    traverse();
    cout<<endl;
    cout<<"0. Terminate Program"<<endl;
    cout<<"1. Insert at 1st position"<<endl;
    cout<<"2. Insert at last position"<<endl;
    cout<<"3. Insert before in Item"<<endl;
    cout<<"4. Insert after an Item"<<endl;
    cout<<endl<<"Enter Option: ";
    int option;
    cin>>option;
    switch(option)
    {
    case 0:
        exit(0);
    case 1:
        insert_first();
        break;
    case 2:
        insert_last();
        break;
    case 3:
        insert_before();
        break;
    case 4:
        insert_after();
        break;
    default:
        cout<<"Option Invalid"<<endl;
        break;
    }
    system("pause");
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

void project()
{
    while(1)
    {
        system("cls");
        traverse();
        cout<<endl;
        cout<<"0. Terminate Program"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        int option;
        cin>>option;
        switch(option)
        {
        case 0:
            exit(0);
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        default:
            cout<<"Option Invalid"<<endl;
        }
    }
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
    project();
}
