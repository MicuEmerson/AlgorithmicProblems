#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("text.txt");

priority_queue <pair < int , int > > pcoada;
pair < int , int > a;
int v[11];
int sters[200005];
int n,g,m,x,g1,alCatelea;


int main()
{   int i;
    fin>>n>>g1>>m;
    for(i=1; i<=10; i++)
    {
        fin>>v[i];
    }
    n+=m;

    for(i=1; i<=n; i++)
    {

        fin>>x;
        g+=x;
        pcoada.push(make_pair(x,n-i));

        if(g>g1)
        {
            alCatelea++;
            a=pcoada.top();
            pcoada.pop();
            g-=a.first;
            sters[n-a.second]=alCatelea;

        }
    }
    for(i=1;i<=10;i++){

        cout<<sters[v[i]]<<endl;
    }





}
