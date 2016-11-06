#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
ifstream fin("carte1.in");
ofstream fout("carte1.out");
const int MAXN=1e4+5;
int n;
int v[MAXN];
int poz[MAXN];
int maxy=-1,zi,cate,careZi,zi2;
int main()
{

    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
        poz[v[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {

        zi++;
        cate=1;
        while(poz[i]<=poz[i+1] && i<=n)
        {
            cate++;
            i++;
        }
        maxy=max(cate,maxy);
    }

    for(int i=1; i<=n; i++)
    {
        cate=1;
        zi2++;
        while(poz[i]<=poz[i+1] && i<=n)
        {
            cate++;
            i++;
        }
        if(cate==maxy){
            careZi=zi2;
            break;
        }
    }
    fout<<zi<<" "<<careZi<<" "<<maxy;




}
