#include <bits/stdc++.h>
using namespace std;

ifstream fin("retele.in");
ofstream fout("retele.out");

const int MAXN = 5e4+5;
int n, m, x, y, nr;
int viz[MAXN];
vector < int > graf[MAXN], transpus[MAXN];
set < int > sol[MAXN];
set < pair <int, int> > v;
stack < int > stiva;

void dfs1(int nod)
{
    viz[nod]=1;
    for(auto it: graf[nod])
        if(!viz[it])
            dfs1(it);

    stiva.push(nod);
}

void dfs2(int nod)
{
    viz[nod]=1;
    sol[nr].insert(nod);

    for(auto it: transpus[nod])
        if(!viz[it])
            dfs2(it);
}


int main()
{
    fin>>n>>m;
    while(m--)
    {
        fin>>x>>y;
        graf[x].push_back(y);
        transpus[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(!viz[i])
            dfs1(i);

    fill(viz+1, viz+n+1, 0);

    while(!stiva.empty())
    {
        int nod = stiva.top();
        stiva.pop();
        if(!viz[nod])
        {
            nr++;
            dfs2(nod);
            v.insert(make_pair(*sol[nr].begin(), nr) );
        }
    }


    fout<<nr<<"\n";
    for(auto it : v)
    {
        fout<<sol[it.second].size()<<" ";
        for(auto it2: sol[it.second])
            fout<<it2<<" ";
        fout<<"\n";
    }
}






