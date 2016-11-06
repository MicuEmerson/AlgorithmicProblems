#include <bits/stdc++.h>

using namespace std;

ifstream fin("reteta.in");
ofstream fout("reteta.out");

int a[25][25],n,m,x;
double pret1[25],pret2[25];
double maxy=99999999;

double ok(int bit)
{

    int f[25],v[25],dim=0;
    double s=0;

    memset(f,0,sizeof(f));

    for(int i=0; i<=m ; i++)
    {
        if( bit & (1<<i) )
        {
            v[++dim]=i+1;
            for(int j=1; j<=a[i+1][0]; j++)
                f[ a[i+1][j] ]++;
        }
    }

    for(int i=1; i<=n; i++)
        if(f[i]!=1)
            return 0;

    for(int i=1; i<=dim; i++)
    {
        int poz=v[i];
        int lungime=a[poz][0];
        int compensat=a[poz][lungime+1];

        if(compensat==1)
            for(int j=1; j<=lungime; j++)
                s+= pret1[ a[poz][j] ];
        else
            for(int j=1; j<=lungime; j++)
                s+= pret2[ a[poz][j] ];

    }
    return s;


}


int main()
{

    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        fin>>x;
        fin>>a[i][0];
        a[i][ a[i][0]+1 ] = x;

        for(int j=1; j<=a[i][0]; j++)
            fin>>a[i][j];
    }

    for(int i=1; i<=n; i++)
    {
        fin>>pret1[i];
        pret2[i]=pret1[i]/2.0;
    }

    for(int i=1; i <= (1<<m) ; i++)
    {
        double rez = ok(i);
        if(rez) maxy=min(maxy,rez);
    }


    fout<<fixed<<setprecision(1)<<maxy;


}

