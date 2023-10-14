//Insertion Sort on Array

#include<bits/stdc++.h>
using namespace std;

int n;
int bin_search(int num,int *a)
{
    int i,j,mid,b,e;
    for(b=0,e=n-1;;)
    {
        mid=(b+e)/2;
        if(a[mid]==num) return mid;
        else if(a[mid]>num) e=mid-1;
        else b=mid+1;
        if(b>e) return -1;
    }
}
void InsertionSort(int a[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int value=a[i],b=i;
        while(b>0 && a[b-1]>value)
        {
            a[b]=a[b-1];
            b--;
        }
        a[b]=value;
    }
}
int main()
{
    int i,k;
    cout<<"Enter the number of element: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    InsertionSort(a,n);
    for(i=0;i<n;i++)
    {
       cout<<a[i]<<" ";
    }
    cout<<endl;
    int num,index;
    //while(1){
    cout<<"Enter the number you want to search at array: "<<endl;
    cin>>num;
    index=bin_search(num,a);
    if(index==-1) cout<<"The Number is missing in the array\n";
    else cout<<"The position of the number is: "<<(index+1)<<endl;
    //}
}
