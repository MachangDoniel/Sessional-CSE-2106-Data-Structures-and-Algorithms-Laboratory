//Radix sort

#include<bits/stdc++.h>
using namespace std;



void countsort(int a[1000],int n,int x)
{
    int d[1000],t;
    for(int s=1; s<=n; s++) // extracting the concerned digit from the number
    {
        t = a[s];

        t = t / (pow(10,x-1));
        d[s] = t%10;
    }
    int c[10],b[1000],i,j;
    for(i=0; i<=9; i++)
        c[i] = 0;
    for(j = 1; j<=n; ++j)
        c[d[j]] = c[d[j]] + 1; //c[i] contains no of elements equal to i
    for(i =0; i<9; i++)

        c[i+1] = c[i+1] + c[i];
    for(j=n; j>0; j--)
    {
        b[c[d[j]]] = a[j]; //shift the array’s numbers
        c[d[j]] = c[d[j]] -1;
    }
    for(i=1; i<=n; i++)
        a[i] = b[i];
}

void radixsort(int a[1000],int n,int digits)
{
    for(int i =1; i<=digits; i++)
        countsort(a,n,i);
}

int main()
{
    int n=1000,k=5;
    int i,j,l,B[n],c[k];
    int A[n]= {2,5,3,0,2,3,0,3};
    radixsort(A,k,8);
    for(i=0;i<8;i++) cout<<A[i]<<" ";
    cout<<endl;
}
