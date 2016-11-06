#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");

typedef struct
{

    int x,y,c;


} vvv;

int n,m;
vvv v[1000];
int poz[1000];

int cmp(vvv a, vvv b)
{

    if(a.c<b.c)
    {
        return 1;
    }
    return 0;

}

int main()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=m; i++)
    {
        fin>>v[i].x>>v[i].y>>v[i].c;
    }

    sort(v+1,v+m+1,cmp);

    for(i=1; i<=m; i++)
    {

        cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].c<<endl;

    }



}
