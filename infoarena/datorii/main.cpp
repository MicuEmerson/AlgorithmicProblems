#include <bits/stdc++.h>

using namespace std;

ifstream fin("datorii.in");
ofstream fout("datorii.out");

int n,m,x,rez,aib[100005];

void update(int poz, int valoare)
{
    while(poz <= n)
    {
        if(aib[poz] + valoare <= 0)
            aib[poz] = 0;
        else
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
        int tip,x,y;
        fin >> tip >> x >> y;
        if(tip)
            fout << query(y) - query(x-1) << "\n";
        else
            update(x,-y);
    }
}



