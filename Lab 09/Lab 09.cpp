//Quick Sort

#include<bits/stdc++.h>
using namespace std;

int n;
void display(int *A,int n)
{
    cout<<"Display"<<endl;
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
}
void Swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int *A,int Start,int End)
{
    int pivot=A[End],pindex=Start,i;
    for(i=Start;i<End;i++)
    {
        if(A[i]<=pivot)
        {
            Swap(&A[i],&A[pindex]);
            pindex++;
        }
        display(A,n);
    }

    Swap(&A[pindex],&A[End]);
    display(A,n);
    cout<<endl;
    return pindex;
}

void QuickSort(int *A,int Start,int End)
{
    if(Start<End)
    {
        int pindex=Partition(A,Start,End);
        QuickSort(A,Start,pindex-1);
        QuickSort(A,pindex+1,End);
    }
}

int main()
{
    int i;
    cout<<"Enter the number of Elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter Elements..."<<endl;
    for(i=0;i<n;i++) cin>>A[i];
    QuickSort(A,0,n-1);
    display(A,n);
}
