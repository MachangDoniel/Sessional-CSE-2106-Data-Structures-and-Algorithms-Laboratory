//Selection Sort on Array

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
void Swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[],int n)
{
    int i,j,iMin;
    for(i=0;i<n-1;i++)
    {
        iMin=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[iMin]) iMin=j;
        }
        Swap(&arr[iMin],&arr[i]);
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
    selectionSort(a,n);
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
