#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("kfactor.in");
ofstream fout("kfactor.out");

int E[100005];
int prime[100005],nrP;
int v[5000005];
int k,a,b,cate;

void ciur()
{

    int i,j;
    for(i=2; i<=k; i++)
    {
        E[i]=1;
    }
    for(i=2; i<=k; i++)
    {
        if(E[i]==1)
        {
            prime[++nrP]=i;
            for(j=i+i; j<=k; j=j+i)
            {
                E[j]=0;
            }
        }
    }


}


int main()
{
    int i,j,r=0,st;
    fin>>k>>a>>b;
    ciur();
    for(i=a; i<=b; i++)
    {
        v[i-a+1]=i;
    }
    for(i=1; i<=nrP; i++)
    {

        r=a%prime[i];
        if(r==0)
        {
            st=1;
        }
        else
        {
            st=prime[i]-r+1;
        }
        for(j=st; j<=b-a+1; j=j+prime[i])
        {
            while(v[j]%prime[i]==0)
            {
                v[j]/=prime[i];
            }
        }

    }
    for(i=1; i<=b-a+1; i++)
    {
        if(v[i]==1)
        {
            cate++;
        }
    }
    fout<<cate;




}
