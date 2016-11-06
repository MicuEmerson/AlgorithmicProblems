#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

typedef struct
{
    int elem;
    int O;
} vct;

vct v[200];

void citire(int x[100], int n)
{

    for(int i=1; i<=n; i++) cin>>x[i];
}

void reset(int f[10])
{
    for(int i=0; i<=9; i++) f[i]=0;
}


int cComun(int a, int b)
{
    int f1[10],f2[10];
    reset(f1),reset(f2);
    if(a==0) f1[0]++;
    while(a>0)
    {
        f1[a%10]++;
        a/=10;
    }
    if(b==0)f2[0]++;
    while(b>0)
    {
        f2[b%10]++;
        b/=10;
    }
    for(int i=0; i<=9; i++) if(f1[i]>0 && f2[i]>0) return 1;
    return 0;
}

int isPerfect(int poz, int v[100], int n)
{

    int i,contor=0;
    for(i=poz+1; i<=n; i++) if(cComun(v[poz],v[i])==1) contor++;
    if(contor==n-poz) return 1;
    return 0;
}

void sortare(vct v[100], int n){

 int i,j;
 for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(v[i].elem<v[j].elem){
            swap(v[i].elem,v[j].elem);
            swap(v[i].O,v[j].O);
        }
    }
 }
}


void inserareDupa(int v[100], int &n, int elem, int poz)
{

    n++;
    int i;
    for(i=n; i>poz; i--)
    {
        v[i]=v[i-1];
    }
    v[poz]=elem;
}


int main()
{
    int n=4,i,j;
    int x[100];
    citire(x,n);

    for(i=1; i<n; i++)
    {
        if(isPerfect(i,x,n)==1)
        {
            for(j=2; j<x[i]; j++)
            {
                if(x[i]%j==0)
                {
                    inserareDupa(x,n,j,i+1);
                }
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        v[i].elem=x[i];
        v[i].O=i;
    }
    sortare(v,n);
    for(i=1; i<=n; i++)
    {
        cout<<v[i].elem<<" ";

    }

    cout<<endl;
     for(i=1; i<=n; i++)
    {

        cout<<v[i].O<<" ";
    }


}
