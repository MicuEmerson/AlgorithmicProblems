#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("unupatru.in");
ofstream fout("unupatru.out");

typedef struct
{
    int nr[100];
} vvv;

vvv v[100];
char c[255];
int sume[100],dimS,cuPatru[100],cuUnu[100],dim4,dim1;
int n;

void calcumSuma(vvv x)
{

    int i;
    int    s=0;
    for(i=1; i<=x.nr[0]; i++)
    {
        s+=x.nr[i]*x.nr[i];
    }
    sume[++dimS]=s;

}

int nrRepetari(int n)
{
    int cate=1,s,cn;
    while(n!=4 && n!=1)
    {

        cn=n;
        s=0;
        cate++;
        while(cn>0)
        {
            s+=(cn%10)*(cn%10);
            cn/=10;
        }
        n=s;
    }
    return cate;

}

int isInVector4(int elem)
{

    for(int i=1; i<=dim4; i++)
    {
        if(elem==cuPatru[i])
        {
            return 1;
        }
    }
    return 0;
}

int isInVector1(int elem)
{

    for(int i=1; i<=dim1; i++)
    {
        if(elem==cuUnu[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i,j;
    fin>>n;
    n=0;
    fin.get();
   fin.get(c,255);
    for(i=0; i<strlen(c); i++)
    {
        n++;
        while(c[i]!=' ' && i<strlen(c))
        {
            v[n].nr[0]++;
            v[n].nr[v[n].nr[0]]=(int)c[i]-48;
            i++;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(v[i].nr[1]==4 && v[i].nr[0]==1)
        {
            cuPatru[++dim4]=i;
        }
        if(v[i].nr[1]==1 && v[i].nr[0]==1)
        {
            cuUnu[++dim1]=i;
        }
    }

    for(i=1; i<=n; i++)
    {
        calcumSuma(v[i]);
    }
    for(i=1; i<=dimS; i++)
    {
        if(isInVector1(i)==1)
        {
            fout<<"0 ";
        }
        else if(isInVector4(i)==1)
        {
            fout<<"0 ";
        }
        else
        {
            fout<<nrRepetari(sume[i])<<" ";
        }
    }








}
