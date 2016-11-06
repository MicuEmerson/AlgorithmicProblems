#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
ifstream fin("set.in");
ofstream fout("set.out");
unsigned long long n,a1,aN,s;
int a[1000],b[1000],c[1000];

void inmultire(int A[], int B[], int C[])
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

void impartire(int A[], int B)
{
    int i, t = 0;
    for (i = A[0]; i > 0; i--, t %= B)
        A[i] = (t = t * 10 + A[i]) / B;
    for (; A[0] > 1 && !A[A[0]]; A[0]--);
}

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


int main()
{

    fin>>n;
    a1=n*(n-1);
    aN=a1+(2*(n-1));
    aN+=a1;
    initializare(aN,a);
    initializare(n,b);
    inmultire(a,b,c);
    impartire(c,2);

    fout<<a1<<endl;
    for(int i=c[0]; i>=1; i--)
    {
        fout<<c[i];
    }

}
