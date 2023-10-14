//Counting sort

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n=9,k=6;
    int i,j,l,B[n],c[k];
    int A[n]={2,5,3,0,2,3,0,3};
    for(j=0;j<n;j++) cout<<A[j]<<" ";
    cout<<endl;
    for(i=0;i<k;i++)
    {
        c[i]=0;
    }
    for(j=0;j<n;j++) cout<<A[j]<<" ";
    cout<<endl;
    for(i=1;i<n;i++)
    {
        c[A[i]]=c[A[i]]+1;
    }
    for(j=0;j<n;j++) cout<<A[j]<<" ";
    cout<<endl;
    for(i=1;i<k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(j=0;j<n;j++) cout<<A[j]<<" ";
    cout<<endl;
    for(j=n-1;j>=0;j--)
    {
        B[c[A[j]]]=A[j];
        c[A[j]]=c[A[j]]-1;
    }
    for(j=0;j<n;j++) cout<<B[j]<<" ";
    cout<<endl;
}
