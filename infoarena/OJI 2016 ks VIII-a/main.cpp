#include <iostream>
#include <fstream>
#include <algorithm>
#include  <limits.h>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");
const int MAXN=1e5+5;

int n,k,v[MAXN];
long long sst[MAXN],sdr[MAXN],x,miny=9223372036854775807;

int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++) fin>>v[i];

    for(int i=1; i<=n; i++)
    {
        x+=v[i];
        if(i-k>=0)
        {
            sst[i]=max(x,sst[i-1]);
            x-=v[i-k+1];
        }
    }

    x=0;
    for(int i=n; i>=1; i--)
    {
        x+=v[i];
        if(n-i>=k-1)
        {
            sdr[i]=max(x,sdr[i+1]);
            x-=v[i+k-1];
        }
    }

    for(int i=1; i<=n; i++)
    {
        long long maxy=max(sdr[i+1],sst[i-k]);
        miny=min(maxy,miny);
    }

    cout<<miny;
}
