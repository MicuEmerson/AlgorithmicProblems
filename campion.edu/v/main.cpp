#include <iostream>
#include <fstream>
#include <algorithm>
#define INF 1000000000;
using namespace std;
ifstream fin("v.in");
ofstream fout("v.out");

typedef struct
{
    int ss;
    int c;
    int l;
} vvv;


int n,m,a[105][105],dimS;
vvv v[10010];


int functie(int i,int j,int cat)
{
    int s=0;
    s+=a[i][j];
    for(int d=1; d<=cat; d++)
    {
        i++;
        j++;
        s+=a[i][j];
    }
    for(int d=1; d<=cat; d++)
    {
        i--;
        j++;
        s+=a[i][j];
    }
    return s;
}
int cmp(vvv a, vvv b)
{

    if(a.ss>b.ss)
    {
        return 1;
    }
    return 0;
}
int cmp1(vvv a, vvv b)
{

    if(a.l<b.l)
    {
        return 1;
    }
    return 0;

}
int cmp2(vvv a, vvv b)
{

    if(a.c<b.c)
    {
        return 1;
    }
    return 0;

}
void rezolvare(int care)
{


    int i,j,s=0,cat=0;
    i=1;
    j=care;
    while(s<1000000010)
    {
        ++cat;
        s=functie(i,j,cat);
        if(s<=1000000000)
        {
            dimS++;
            v[dimS].ss=s;
            v[dimS].c=care;
            v[dimS].l=i+cat;
        }
    }
}



int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }

    for(int i=1; i<=n+1; i++)
    {
        a[i][m+1]=INF;
    }
    for(int j=1; j<=m+1; j++)
    {
        a[n+1][j]=INF;
    }


    //rez
    for(int i=1; i<=n; i++)
    {
        rezolvare(i);
    }
    sort(v+1,v+dimS+1,cmp);
    int panaLa=2;
    while(v[1].ss==v[panaLa].ss)
    {
        panaLa++;
    }
    panaLa--;
    sort(v+1,v+panaLa+1,cmp1);
    int panaLa2=2;
    while(v[1].l==v[panaLa2].l)
    {
        panaLa2++;
    }
    panaLa2--;
    sort(v+1,v+panaLa2+1,cmp2);
    fout<<v[1].ss<<" "<<v[1].c<<" "<<v[1].l;

}
