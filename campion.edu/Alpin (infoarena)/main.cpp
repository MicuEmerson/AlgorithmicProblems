#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

const int MAXN = 1200;

int n,a[1200][1200], pd[MAXN][MAXN], ;
int f[1200][1200];
vector < pair < int , int > > v[1200][1200], intra[MAXN][MAXN]];
vector < pair < int , int > sol, last[MAXN][MAXN];

bool isOk(int i_next, int j_next, int i ,int j)
{

    if(i_next<=n && i_next>=1 && j_next<=n && j_next>=1 && a[i][j]<a[i_next][j_next])
    {
        return true;
    }
    return false;
}

void vecini(int i, int j)
{

    int dl[4]= {0,-1,0,1};
    int dc[4]= {1,0,-1,0};
    int i_next,j_next;
    for(int d=0; d<=3; d++)
    {

        i_next=i+dl[d];
        j_next=j+dc[d];
        if(isOk(i_next,j_next, i, j))
        {

            v[i][j].push_back(make_pair(i_next, j_next));
            intra[i_next][j_next].push_back(make_pair(i, j));
            f[i_next][j_next]++;

        }
    }
}

void sortareTopologica()
{

    queue < pair < int , int > > coada;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(f[i][j]==0)
            {
                coada.push(make_pair(i,j));
            }
        }
    }
    while(!coada.empty())
    {

        pair<int, int> nod;
        nod = coada.front();
        coada.pop();
        sol.push_back(nod);

        for (auto it : v[nod.first][nod.second])
        {
            f[it.first][it.second]--;
            if(f[it.first][it.second]==0)
            {
                coada.push(it);
            }
        }
    }
}

void calculeza() {
    for (int i = 0; i < sol.size(); ++i) {
        pd[sol[i].first][sol[i].second] = 1;
        for (auto it: intra[sol[i].first][sol[i].second]) {
            if (pd[it.first][it.second] + 1 > pd[sol[i].first][sol[i].second]) {
                pd[sol[i].first][sol[i].second] = pd[it.first][it.second] + 1;
                last[sol[i].first][sol[i].second] = it;
            }
    }

}


int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            fin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            vecini(i,j);
        }
    }
}
