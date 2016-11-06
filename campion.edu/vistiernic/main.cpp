#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("vistiernic.in");
ofstream fout("vistiernic.out");

void factoriPrimi(int nr, int f[100], int p[100], int &dim)
{

    int i;
    int numar=2,putere;
    dim=0;

    while(nr>1)
    {
        if(nr%numar==0)
        {
            putere=0;
            while(nr%numar==0)
            {
                putere++;
                nr/=numar;
            }
            dim++;
            f[dim]=numar;
            p[dim]=putere;
        }
        else
        {
            numar++;
        }
    }

}



int main()
{
    int n,x,f[100],p[100],dim,p5=0,p2=0,i,j;
    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>x;
        factoriPrimi(x,f,p,dim);

        for(j=1; j<=dim; j++)
        {
            if(f[j]==2)
            {
                p2+=p[j];
            }
            if(f[j]==5)
            {
                p5+=p[j];
            }
        }
    }
    if(p5>p2){
        fout<<p2;
    }
    else{
        fout<<p5;
    }

}
