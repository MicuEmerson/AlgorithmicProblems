#include <bits/stdc++.h>
#define long long ll;
using namespace std;


ifstream fin("distincte.in");
ofstream fout("distincte.out");

const int MAXN = 100005, mod = 666013;
int n,k,m,x;
int aib[MAXN],dim[MAXN];
vector < int > v[MAXN];
pair < pair<int,int>, int> p[MAXN];

void update(int poz, int valoare)
{
    while(poz <= n)
    {
        aib[poz] = (aib[poz] + valoare) % mod;
        poz += ( poz & (-poz) ) ;
    }
}

int query(int poz)
{
    int s = 0;

    while(poz > 0)
    {
        s = (s + aib[poz]) % mod;
        poz -= ( poz & (-poz) );
    }

    return s;
}

int main()
{
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(v[x].empty())
            update(i,x);

        v[x].push_back(i);

    }
    for(int i=1; i<=3; i++)
    {
        cout<<i<<": ";
        for(auto it: v[i])
            cout<<it<<" ";
        cout<<endl;
    }

    for(int i=1; i<=m; i++)
    {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    sort(p + 1, p + m + 1);


    for(int i=1,j=1; i<=m; i++)
    {
        if(p[i].first == j)
        {
            while(p[i].first == j && i <= m)
                rez[ p[i].second ] = query( p[i++].first.second );
        }
        else
        {
            j++;

        }


        i--;




    }




}
