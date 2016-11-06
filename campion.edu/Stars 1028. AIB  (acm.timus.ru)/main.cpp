#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("stars.in");
ofstream fout("stars.out");


int v[32000];
int nivel[15000];


int interogare(int poz)
{
    int rez=0;
    while(poz>0)
    {
        rez+=v[poz];
        poz=poz-(poz&(-poz));
    }
    return rez;
}


void update(int valoare, int poz)
{
    while(poz<=32000)
    {
        v[poz]+=valoare;
        poz=poz+(poz&(-poz));
    }
}

int main()
{
    int n,i,x,y,rez;

    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>x;
        fin>>y;
        rez=interogare(x);
        nivel[rez]++;
        update(1,x);
    }
    for(i=0;i<n;i++){
        cout<<nivel[i]<<endl;
    }


}















