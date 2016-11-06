#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream fin("mere.in");
ofstream fout("mere.out");

typedef struct
{

    int x,y,h,r;

} vvv;

typedef struct
{

    int x,y,r;

} cerc;

vvv v[205];
cerc c[205];
int n,dim,dimC=1,h;

int cmp(vvv x1, vvv x2)
{

    if(x1.h>x2.h)
    {
        return 1;
    }
    return 0;
}

float calcul(vvv nr, cerc nr1)
{

    return sqrt(pow(nr1.x-nr.x,2.0)*pow(nr1.y-nr.y,2.0));

}


int ok(vvv nr)
{
    float rez;
    int sumaR;
    for(int i=1; i<=dimC; i++)
    {
        rez=calcul(nr,c[i]);
        sumaR=nr.r+c[i].r;
        if(rez<=sumaR)
        {
            return 1;
        }
    }
    return 0;

}

int main()
{

    fin>>n;
    fin>>c[dimC].x>>c[dimC].y>>h>>c[dimC].r;

    for(int i=1; i<n; i++)
    {
        int x1,x2,h1,r1;
        fin>>x1>>x2>>h1>>r1;

        if(h1<=h)
        {
            dim++;
            v[dim].x=x1;
            v[dim].y=x2;
            v[dim].h=h1;
            v[dim].r=r1;
        }

    }
    sort(v+1,v+dim+1,cmp);

    for(int i=1; i<=dim; i++)
    {

        if(ok(v[i])==1)
        {
            dimC++;
            c[dimC].x=v[i].x;
            c[dimC].y=v[i].y;
            c[dimC].r=v[i].r;
        }
    }
    fout<<dimC;

}



