#include <bits/stdc++.h>

using namespace std;

ifstream fin("baruri.in");
ofstream fout("baruri.out");

int t,n,m,x,aib[100005];

void update(int poz, int valoare)
{
    while(poz <= n)
    {
        aib[poz] += valoare;
        poz += ( poz & (-poz) );
    }
}

int query(int poz)
{
    int s = 0;
    if(poz>n) poz = n;
    while(poz > 0)
    {
        s += aib[poz];
        poz -= ( poz & (-poz) );
    }
    return s;
}

int main()
{

    fin>>t;
    while(t--)
    {
        fin>>n;
        fill(aib+1, aib+n+1, 0);
        for(int i=1; i<=n; i++)
        {
            fin>>x;
            update(i,x);
        }
        fin>>m;
        while(m--)
        {
            int tip,x,y,z;

            fin>>tip>>x>>y;
            if(tip == 0)
            {
                fout << query(x+y) - query(x-y-1) - ( query(x) - query(x-1) ) << "\n";
            }
            else if(tip == 1)
            {
                update(y,x);
            }
            else if(tip == 2)
            {
                update(y,-x);
            }
            else
            {
                fin>>z;
                update(y,-x);
                update(z,x);
            }
        }

    }
}
