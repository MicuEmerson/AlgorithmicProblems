#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
long long  n=200,m=20;
int a[101],b[101],c[101];
void initializare(long long n, int v[101])
{
    int i=1;
    v[0]=1;  // in a[0] retinem dimensiunea vectorului
    if(n==0) // daca cumva n este 0 ne asiguram ca il reprezentam
    {
        v[1]=0;
    }
    else
    {
        while(n>0)
        {
            v[i]=n%10;
            n/=10;
            i++;
            v[0]++;
        }
    }
}

void sumaAdouaNrMari(int a[101], int b[101], int c[101])    // in c vom salva a+b
{
    int t=0,i;

    for(i=1; i<=a[0] || i<=b[0] || t; i++)
    {

        t=a[i]+b[i]+t;
        c[i]=t%10;
        t=t/10;
    }
    c[0]=i-1;


}

void impartire(int A[], int B)
{
    int i, t = 0;
    for (i = A[0]; i > 0; i--, t %= B)
        A[i] = (t = t * 10 + A[i]) / B;
    for (; A[0] > 1 && !A[A[0]]; A[0]--);
}

void mul(int A[], int B[], int C[])
{
    int i, j, t ;
    memset(C, 0, sizeof(C));
    for (i = 1; i <= A[0]; i++)
    {
        for (t=0, j=1; j <= B[0] || t; j++, t/=10)
            C[i+j-1]=(t+=C[i+j-1]+A[i]*B[j])%10;
        if (i + j - 2 > C[0]) C[0] = i + j - 2;
    }
    memcpy(A, C, sizeof(C));
}



int main()
{


    initializare(n,a);
    initializare(m,b);
    for(int i=a[0]-1; i>=1; i--)
    {
        cout<<a[i];
    }
    cout<<endl;
    for(int i=b[0]-1; i>=1; i--)
    {
        cout<<b[i];
    }
    impartire(a,4);
    cout<<endl;
    for(int i=a[0]; i>=1; i--)
    {
        cout<<a[i];
    }



}
