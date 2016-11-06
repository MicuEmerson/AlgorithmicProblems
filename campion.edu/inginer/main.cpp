#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("text.txt");
//FILE *fin,*fout;

int n,m;
int a[100][100];

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int isOk(int x1, int y1)
{

    if(a[x1][y1]!=0)
    {
        return 0;
    }
    if(x1<=n && x1>=1 && y1<=m && y1>=1)
    {
        return 1;
    }
    return 0;
}

void lee(int li, int ci)
{
    int i_next,j_next,i,j;
    int dl[4]= {0,1,0,-1};
    int dc[4]= {1,0,-1,0};
    queue < pair < int , int > > coada;
    a[li][ci]=1;
    coada.push(make_pair(li,ci));
    while(!coada.empty())
    {

        i=coada.front().first;
        j=coada.front().second;
        coada.pop();

        for(int d=0; d<=3; d++)
        {

            i_next=i+dl[d];
            j_next=j+dc[d];

            if(isOk(i_next,j_next) &&  a[i_next][j_next] == 0)
            {
                coada.push(make_pair(i_next,j_next));
                a[i_next][j_next]=a[i][j]+1;
                 afisare();
            }
        }
    }
}

int main()
{
    int x1,y1,x2,y2,i,j;
    char c;
    fin>>n>>m;
    n=n+2;
    m=m+2;
    for(i=2; i<n; i++)
    {
        for(j=2; j<m; j++)
        {
            fin>>c;
            if(c=='X')
            {
                a[i][j]=-1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    afisare();
    cout<<endl;
    fin>>x1>>y1>>x2>>y2;
    x1++;
    y1++;
    x2++;
    y2++;
    lee(x1,y1);


    /*
    while(x1!=0 && y2!=0 && x2!=0 && y2!=0)
    {

        fin>>x1>>y1>>x2>>y2;

    }
    */
}



















