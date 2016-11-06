#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("text.txt");
ofstream fout("rv.out");

long long aib[100005];
long long s[100005];


long long interogare(int poz)
{

    long long rez=0;
    while(poz>0)
    {
        rez+=s[poz];
        poz-=poz&(-poz);
    }
    return rez;

}

void afisare(long long v[100005], int n)
{

    for(int i=1; i<=n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



int main()
{

    int t,c,n,st,dr,val,tip;
    int i,j;
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>n>>c;

        for(j=1; j<=c; j++)
        {

            fin>>tip;
            if(tip==0)
            {
                fin>>st>>dr>>val;
                aib[st]+=val;
                aib[dr+1]-=val;
            }
            else
            {
                fin>>st>>dr;
                for(i=1; i<=n; i++)
                {
                   s[i]=s[i-1]+aib[i];
                }

                if(st==dr)
                {
                    cout<<interogare(st)<<endl;
                }

                else
                {
                    cout<<interogare(dr)-interogare(st-1)<<endl;
                }
            }
            afisare(s,n);


        }

    }



}
