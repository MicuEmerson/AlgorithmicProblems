#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("sortaret.in");
ofstream fout("sortaret.out");
vector < int > v[50010];
vector < int > sol;
int f[50010];
queue < int > coada;
int n,m;

int main()
{
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        v[x].push_back(y);
        f[y]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(f[i]==0)
        {
            coada.push(i);
        }
    }

    while(!coada.empty())
    {

        int x;
        x=coada.front();
        coada.pop();
        sol.push_back(x);
        for(int i=0; i<v[x].size(); i++)
        {
            f[v[x][i]]--;
            if(f[v[x][i]]==0)
            {
                coada.push(v[x][i]);
            }
        }
    }

    for(int i=0;i<sol.size();i++){
       fout<<sol[i]<<" ";
    }


    return 0;

}
