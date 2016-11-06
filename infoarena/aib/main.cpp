#include <bits/stdc++.h>

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

int n,m,x,rez,aib[100005];

void update(int poz, int valoare)
{
    while(poz <= n)
    {
        aib[poz] += valoare;
        poz += ( poz & (-poz) ) ;
    }
}

int query(int poz)
{
    int s = 0;

    while(poz > 0)
    {
        s += aib[poz];
        poz -= ( poz & (-poz) );
    }

    return s;
}

int cautare_binara(int suma)
{
    int st = 1, dr = n, m, last = -1;

    while(st <= dr)
    {
        m = (st+dr) / 2;
        rez = query(m);

        if(rez >= suma)
        {
            if(rez == suma)
                last = m;
            dr = m - 1;
        }
        else
        {
            st = m + 1;
        }
    }

    return last;
}


int main()
{
    fin>> n >> m;
    for(int i=1; i<=n; i++)
    {
        fin >> x;
        update(i,x);
    }

    while(m--)
    {
        int tip,x,y,suma;
        fin >> tip;

        if(tip == 0)
        {
            fin>> x >> y;
            update(x,y);
        }
        else if(tip == 1)
        {
            fin >> x >> y;
            fout << query(y) - query(x-1) << "\n";
        }
        else
        {
            fin >> x;
            fout << cautare_binara(x) << "\n";
        }
    }
}
