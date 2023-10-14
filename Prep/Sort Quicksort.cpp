//Quick sort in c++/
#include<bits/stdc++.h>
using namespace std;
int Partition(int *A,int Start,int End)
{
    int pivot=A[End];
    int partitionindex=Start;
    int i;
    for(i=Start;i<End;i++)
    {
        if(A[i]<=pivot)
        {
            swap(A[i],A[partitionindex]);
            partitionindex++;
        }
    }
    swap(A[partitionindex],A[End]);
    return partitionindex;
}
void quicksort(int *A,int Start,int End)
{
    if(Start<End)
    {
        int partitionindex=Partition(A,Start,End);
        quicksort(A,Start,partitionindex-1);
        quicksort(A,partitionindex+1,End);
    }
}
int main()
{
    int elements,i;
    cout<<"No. of Elements: ";
    cin>>elements;
    int A[elements];
    for(i=0;i<elements;i++)
        cin>>A[i];
    quicksort(A,0,elements-1);
    for(i=0;i<elements;i++)
        cout<<A[i]<<" ";
}
