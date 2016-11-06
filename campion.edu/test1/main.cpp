#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("test1.in");
ofstream fout("test1.out");
int a,b;
int A[100],B[100],C[100];
int toate[100],dimToate;
int dimA,dimB,dimC;
int k,nr,copie,maxPrim=2,intrat;

int isPrim(int n)
{

    int nrDiv=2;
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            nrDiv++;
        }
    }
    if(nrDiv==2)
    {
        return 1;
    }
    return 0;

}


int main()
{
    int i,j;
    fin>>a>>b;
    toate[++dimToate]=a;
    toate[++dimToate]=b;

    while(a>0)
    {
        A[++dimA]=a%10;
        a/=10;
    }
    while(b>0)
    {
        B[++dimB]=b%10;
        b/=10;
    }
    k=dimB;
    for(i=1; i<=dimB/2; i++)
    {
        swap(B[i],B[k]);
        k--;
    }
    for(i=1; i<=dimA; i++)
    {

        copie=B[1];
        B[1]=A[i];

        nr=0;
        for(j=1; j<=dimB; j++)
        {
            nr=nr*10+B[j];
        }
        toate[++dimToate]=nr;

        B[1]=copie;
        copie=B[dimB];
        B[dimB]=A[i];

        nr=0;
        for(j=1; j<=dimB; j++)
        {
            nr=nr*10+B[j];
        }
        toate[++dimToate]=nr;

        B[dimB]=copie;
    }
    sort(toate+1,toate+dimToate+1);
    for(i=1; i<=dimToate; i++)
    {
        if(isPrim(toate[i])==1)
        {
            maxPrim=max(maxPrim,toate[i]);
            intrat=1;
        }
    }
    if(intrat==0)
    {
        fout<<toate[dimToate];
    }
    else
    {
        fout<<maxPrim;
    }
}
