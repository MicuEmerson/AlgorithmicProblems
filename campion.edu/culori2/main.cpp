#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("culori2.in");
ofstream fout("culori2.out");

int n,k,identice,c,cate,cateMax=-99999;
int v[1005];

int main()
{
    int i,j;
    fin>>n>>k;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    if(v[1]==v[2] && v[1]==v[n])
    {
        identice++;
    }
    for(i=2; i<=n; i++)
    {

        if(i==n)
        {
            if(v[i-1]==v[i] && v[1]==v[i])
            {
                identice++;
            }
        }

        else
        {
            if(v[i]==v[i-1] && v[i-1]==v[i+1])
            {
                identice++;
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        j=i+1;
        c=k;
        cate=1;
        while(c-1>0)
        {
            if(j>n)
            {
                j=1;
            }
            if(v[i]==v[j])
            {
                cate++;
            }
            c--;
            j++;
        }
        cateMax=max(cateMax,cate);
    }
    fout<<identice<<endl;
    fout<<cateMax;

}
