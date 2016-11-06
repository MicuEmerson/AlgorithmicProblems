#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("noroc.in");
ofstream fout("noroc.out");
int n,st,dr,care,gasit;
int s[201],r[201],f[201],v[201],v1[201];
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        fin>>x;
        v1[i]=x;
        x=x*x;
        v[i]=x;
    }
    for(int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+v[i];
    }
    for(int i=1; i<=n; i++)
    {
        r[i]=s[i]%n;
        f[r[i]]++;
    }

    if(f[0]>0)
    {
        for(int i=1; i<=n; i++)
        {
            if(r[i]==0)
            {
                dr=i;
                break;
            }
        }
        fout<<dr<<"\n";
        for(int i=1; i<=dr; i++)
        {
            fout<<v1[i]<<" ";
        }
    }
    else
    {
        for(int i=0; i<=n; i++)
        {
            if(f[i]>1)
            {
                care=i;
                break;
            }
        }
        for(int i=1; i<=n && gasit<2; i++)
        {
            if(r[i]==care && gasit==0)
            {
                st=i;
                gasit++;
            }
            else if(r[i]==care && gasit==1)
            {
                dr=i;
                gasit++;
            }
        }
        fout<<dr-st<<"\n";
        for(int i=st+1; i<=dr; i++)
        {
            fout<<v1[i]<<" ";
        }
    }
}
