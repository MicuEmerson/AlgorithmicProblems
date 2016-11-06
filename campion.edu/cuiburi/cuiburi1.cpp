#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.141592
#define ui unsigned int
using namespace std;
FILE *fin, *fout;

typedef struct
{
    int tip;
    ui a,b,c,d;
    double arie;
} FIGURA;


ui n,i,j;
FIGURA F[2001];
int L[2001],rez;

void citeste(FIGURA &f)
{
    fscanf(fin,"%d",&f.tip);
    if (f.tip==0)
    {
        fscanf(fin,"%u%u%u%u",&f.a,&f.b,&f.c,&f.d);

        f.arie=(f.c-f.a)*(f.d-f.b);
    }
    else
    {
        fscanf(fin,"%u%u%u",&f.a,&f.b,&f.c);
        f.arie=PI*f.c*f.c;
    }
}

int cmp(FIGURA x, FIGURA y)
{
    if (x.arie<y.arie)
        return 1;
    return 0;
}

int interior(ui x, ui y, FIGURA f)
{
    ui d;
    d=(x-f.a)*(x-f.a)+(y-f.b)*(y-f.b);
    if (d<=f.c*f.c)
        return 1;
    return 0;
}

int inclusa(FIGURA x, FIGURA y)
// este x inclus in y ?
{
    // x dreptunghi, y dreptunghi
    if (x.tip==0 && y.tip==0)
        if (x.a>=y.a && x.c<=y.c&& x.b>=y.b && x.d<=y.d)
            return 1;
        else
            return 0;
    // x cerc, y dreptunghi
    if (x.tip==1 && y.tip==0)
    {
        FIGURA z;
        z.tip=0;
        z.a=x.a-x.c;
        z.b=x.b-x.c;
        z.c=x.a+x.c;
        z.d=x.b+x.c;
        return inclusa(z,y);
    }
    // x dreptunghi, y cerc
    if (x.tip==0 && y.tip==1)
        if (interior(x.a,x.b,y) && interior(x.a,x.d,y) && interior(x.c,x.b,y) && interior(x.c,x.d,y))
            return 1;
        else
            return 0;
    // x cerc, y cerc
    if (x.tip==1 && y.tip==1)
        if ((x.a-y.a)*(x.a-y.a)+(x.b-y.b)*(x.b-y.b)<=(x.c-y.c)*(x.c-y.c))
            return 1;
        else
            return 0;
}

int main()
{

    fin=fopen("cuiburi.in","r");
    fout=fopen("cuiburi.out","w");
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; i++)
        citeste(F[i]);
    sort(F+1,F+n+1,cmp);
    L[n]=1;
    for (i=n-1; i>=1; i--)
    {
        L[i]=0;
        for (j=i+1; j<=n; j++)
            if (inclusa(F[i],F[j]))
                if (L[j]>L[i])
                    L[i]=L[j];
        L[i]++;
    }
    rez=-1;
    for (i=1; i<=n; i++)
        if (L[i]>rez)
            rez=L[i];
    fprintf(fout,"%d",rez);

    return 0;
}
