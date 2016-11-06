#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("disjoint.in");
ofstream fout("disjoint.out");
const int MAXN = 100100;

int dad[MAXN], range[MAXN];

inline int find (int nod)
{
    if (dad[nod] == nod)
        return nod;
    dad[nod] = find (dad[nod]);
    return dad[nod];
}

void reunion (int nod1, int nod2)
{
    nod1 = find(nod1);
    nod2 = find(nod2);

    if (range[nod1] > range[nod2])
        dad[nod2] = nod1;
    else if (range[nod2] > range[nod1])
        dad[nod1] = nod2;
    else
    {
        dad[nod2] = nod1;
        ++range[nod1];
    }
}

int n, m;

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        dad[i]=i;
        range[i]=1;
    }

    for(int i=1; i<=m; i++)
    {
        int tip,x,y;
        fin>>tip>>x>>y;
        if(tip==1)
        {
            reunion(x,y);
        }
        else
        {
            fout << ( find(x) == find(y) ? "DA" : "NU" );
            fout<<"\n";
        }

    }
}
