#include <iostream>
#include <fstream>
using namespace std;

int a1[10002],b1[10002],a2[10002],b2[10002];

void adunare(int a[], int b[], int c[])
{

    int t=0,i,n;
    for(i=1; i<=a[0] || b[0]; i++)
    {

        int s;
        s=a[i]+b[i]+t;
        c[c[++0]]=s%10;
        t=s/10;
    }
    n=c[0];
    for(i=1; i<=c[0]/2; i++)
    {
        swap(c[i],c[n]);
        n--;
    }
}

void copiere(){




}


int main()
{
    int n;

    fin>>n;
    a1[0]=1;
    b1[0]=1
          a1[1]=1;
    b1[1]=1;
    for(int i=2; i<=n; i++)
    {
          adunare(a1,b1,a2);
          adunare(a1,b1,b2);
          adunare(a1,b2,b2);
          adunare(,,a1)
    }
}
