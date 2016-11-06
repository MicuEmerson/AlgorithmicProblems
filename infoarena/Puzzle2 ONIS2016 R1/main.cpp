#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
ifstream fin("zana.in");
ofstream fout("zana.out");

const int MAXN=1e5+5;
int used[MAXN],a[1000][1000],n,m,nodStart,dim,l=2,c;
vector < int > graf[MAXN];
queue < int > Q;


int main()
{

    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(graf[i].size()==2)
        {
            a[1][++dim]=nodStart=i;
            used[i]=1;
            break;
        }

    Q.push(graf[nodStart][0]);


    while(!Q.empty())
    {
        int nod=Q.front();
        a[1][++dim]=nod;
        used[nod]=1;
        Q.pop();

        for(int i=0; i<graf[nod].size(); i++)
        {
            if(graf[graf[nod][i]].size()==3 && !used[graf[nod][i]] )
            {
                Q.push(graf[nod][i]);
            }
            else if(graf[graf[nod][i]].size()==2 && !used[graf[nod][i]])
            {
                a[1][++dim]=graf[nod][i];
                used[graf[nod][i]]=1;
            }
        }
    }
    c=dim;

    for(int i=1; i<=dim; i++)
        for(auto it:  graf[a[1][i]])
            if(!used[it])
            {
                used[it]=1;
                Q.push(it);
            }

    dim=0;
    while(!Q.empty())
    {

        if(dim==3) l++,dim=0;

        int nod=Q.front();
        Q.pop();
        a[l][++dim]=nod;
        used[nod]=1;

        for(auto it: graf[nod])
            if(!used[it])
                Q.push(it);
    }
    l--;

    cout<<c<<" "<<l<<"\n";
    for(int i=1; i<=l; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

}
