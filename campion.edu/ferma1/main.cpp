#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ferma1.in");
ofstream fout("ferma1.out");

typedef struct
{
    int nr;
    char clr;
} sss;

const int MAXN=410;
int viz[MAXN][MAXN], val[MAXN], viz1[MAXN][MAXN];
char a[MAXN][MAXN],culoare;
int n,m,tip,cate,dim,maxy,maxy2=-1,x,y;
sss s[MAXN][MAXN];
int dl[4]= {0,-1,0,1};
int dc[4]= {1,0,-1,0};

bool isOk(int i, int j)
{
    if(i<=n && j<=m && i>=1 && j>=1) return true;
    return false;
}

int umple(int i, int j, char t)
{
    viz1[i][j]=dim;
    for(int d=0; d<=3; d++)
    {
        int i_next=i+dl[d];
        int j_next=j+dc[d];
        if(viz1[i_next][j_next]==0 && a[i_next][j_next]==t && isOk(i_next,j_next))
        {
            cate++;
            umple(i_next,j_next,t);
        }
    }
    return cate;
}

sss umple1(int i, int j)
{
    sss s;
    s.nr=0;

    //N+S
    if(a[i-1][j]==a[i+1][j] && s.nr < viz[i-1][j]+viz[i+1][j]+1 && viz1[i-1][j]!=viz1[i+1][j] && isOk(i-1,j) && isOk(i+1,j)){
        s.nr=viz[i-1][j]+viz[i+1][j]+1;
        s.clr=a[i-1][j];
    }
    //V+E
    if(a[i][j-1]==a[i][j+1] && s.nr < viz[i][j-1]+viz[i][j+1]+1 && viz1[i][j-1]!=viz1[i][j+1] && isOk(i,j-1) && isOk(i,j+1)){
        s.nr=viz[i][j-1]+viz[i][j+1]+1;
        s.clr=a[i][j-1];
    }
    //N+E
    if(a[i-1][j]==a[i][j+1] && s.nr < viz[i-1][j]+viz[i][j+1]+1 && viz1[i-1][j]!=viz1[i][j+1] && isOk(i-1,j) && isOk(i,j+1)){
        s.nr=viz[i-1][j]+viz[i][j+1]+1;
        s.clr=a[i-1][j];
    }
    //N+V
    if(a[i-1][j]==a[i][j-1] && s.nr < viz[i-1][j]+viz[i][j-1]+1 && viz1[i-1][j]!=viz1[i][j-1] && isOk(i-1,j) && isOk(i,j-1)){
        s.nr=viz[i-1][j]+viz[i][j-1]+1;
        s.clr=a[i-1][j];
    }
    //S+V
    if(a[i+1][j]==a[i][j-1] && s.nr < viz[i+1][j]+viz[i][j-1]+1 && viz1[i+1][j]!=viz1[i][j-1] && isOk(i+1,j) && isOk(i,j-1)){
        s.nr=viz[i+1][j]+viz[i][j-1]+1;
        s.clr=a[i+1][j];
    }
    //S+E
    if(a[i+1][j]==a[i][j+1] && s.nr < viz[i+1][j]+viz[i][j+1]+1 && viz1[i+1][j]!=viz1[i][j+1] && isOk(i+1,j) && isOk(i,j+1)){
        s.nr=viz[i+1][j]+viz[i][j+1]+1;
        s.clr=a[i+1][j];
    }

    return s;

}




int main()
{
    fin>>tip>>n>>m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            fin>>a[i][j];


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(viz1[i][j]==0)
            {
                dim++;
                cate=1;
                val[dim]=umple(i,j,a[i][j]);
                maxy=max(maxy,val[dim]);
            }
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            viz[i][j]=val[viz1[i][j]];


    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            s[i][j]=umple1(i,j);



    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i][j].nr>maxy2){
                maxy2=s[i][j].nr;
                x=i;
                y=j;
                culoare=s[i][j].clr;
            }
        }
    }
    if(tip==1){
        fout<<maxy<<"\n";
    }
    else{
        fout<<x<<" "<<y<<"\n"<<culoare<<"\n";
    }

}
