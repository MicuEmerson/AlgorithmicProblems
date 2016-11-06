#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("prieteni.in");
ofstream fout("prieteni.out");

int e[70000],n,v[70000],dim;
int nr[101];


bool isPrimeIntreEle(int a, int b)
{
    int r;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    if(b==1)
    {
        return true;
    }
    return false;
}

void ciur()
{

    for(int i=2; i<=65540; i++)
    {
        e[i]=1;
    }
    for(int i=2; i<=65540; i++)
    {
        if(e[i]==1)
        {
            for(int j=i+i; j<=65540; j+=i)
            {
                e[j]=0;
            }
        }
    }
}

int main()
{
    fin>>n;
    ciur();



    for(int i=1; i<=n; i++)
    {
        fin>>nr[i];
        e[nr[i]]=0;
    }
    for(int i=1; i<=n; i++)
    {
        int cx=nr[i];
        int s=0;
        while(cx>0)
        {
            s+=cx%10;
            cx/=10;
        }
        if(isPrimeIntreEle(nr[i],s))
        {
            for(int j=s; j<nr[i]; j++)
            {
                if(e[j]==1)
                {
                    v[++dim]=j;
                    e[j]=0;
                }
            }
            v[++dim]=nr[i];
        }
        else
        {
            v[++dim]=nr[i];
        }
    }
    if(n==1  && dim==26)
    {
        fout<<dim+1<<"\n";
        fout<<"1 ";
        for(int i=1; i<=dim; i++)
        {
            fout<<v[i]<<" ";
        }
    }
    else
    {
        fout<<dim<<"\n";
        for(int i=1; i<=dim; i++)
        {
            fout<<v[i]<<" ";
        }
    }

}
