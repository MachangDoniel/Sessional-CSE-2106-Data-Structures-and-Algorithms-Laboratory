//Merge sort in C++/
#include<bits/stdc++.h>
using namespace std;
void Merge(int *A,int *L,int leftCount,int *R,int rightCount)
{
    int i=0,j=0,k=0;
    while(i<leftCount && j< rightCount)
    {
        if(L[i]<R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<leftCount)
        A[k++]=L[i++];
    while(j<rightCount)
        A[k++]=R[j++];
}
void MergeSort(int *A,int n)
{
    int mid,i;
    if(n < 2)
        return;
    mid = n/2;
    int left[mid],right[n-mid];
    for(i=0; i<mid; i++)
        left[i]=A[i];
    for(i=mid; i<n; i++)
        right[i-mid]=A[i];
    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(A,left,mid,right,n-mid);
}
int main()
{
    int i,numberofElements;
    cout<<"Enter No. of Elements in array: ";
    cin>>numberofElements;
    int A[numberofElements];
    for(i=0; i<numberofElements; i++)
        cin>>A[i];
    MergeSort(A,numberofElements);
    for(i=0; i<numberofElements; i++)
        cout<<A[i]<<" ";
    return 0;
}
