#include <bits/stdc++.h>
using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

const int MAXN = 100005 , mod=9917;
int n, x, aib[MAXN], a[MAXN], b[MAXN], c[MAXN], rez;

void update(int poz, int valoare)
{
    while(poz<=n)
    {
        aib[poz] += valoare;
        poz += (poz & -poz);
    }
}

int query(int poz)
{
    int s = 0;
    while(poz>0)
    {
        s += aib[poz] % mod;
        poz -= (poz & -poz);
    }
    return s;
}

int cautare_binara(int valoare)
{
    int st = 1, dr = n, m;
    while(st<=dr)
    {
        m = (st+dr) / 2;

        if(b[m] == valoare )
            return m;
        else if(b[m] < valoare)
            st = m +1;
        else
            dr = m - 1;
    }
    return 0;

}

int main()
{
    fin >> n;
    for(int i=1; i<=n; i++)
    {
        fin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1; i<=n; i++)
    {
        c[i]=cautare_binara(a[i]);
    }

    for(int i=n; i>=1; i--)
    {
        rez += query(c[i]) % mod;

        update(c[i],1);
    }
    fout<<rez;
}
