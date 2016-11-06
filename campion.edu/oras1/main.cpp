#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("oras1.in");
ofstream fout("oras1.out");

int n,m,cladiri,maxy=-999,maxy1;
char a[210][210];
int VIZ[210][210];
int dl[8]= {0,1,1,1,0,-1,-1,-1};
int dc[8]= {1,1,0,-1,-1,-1,0,1};
int dl1[4]= {0,-1,0,1};
int dc1[4]= {1,0,-1,0};

bool isOk(int i,int j)
{

    if(i<=n && i>=1 && j<=m && j>=1) return true;

    return false;
}

void dfs(int i, int j)
{
    VIZ[i][j]=1;
    for(int d=0; d<=3; d++)
    {
        int i_next=i+dl1[d];
        int j_next=j+dc1[d];
        if(isOk(i_next,j_next) && a[i_next][j_next]=='C' && VIZ[i_next][j_next]==0) dfs(i_next,j_next);
    }
}

void dfs1(int i, int j)
{
    VIZ[i][j]=1;
    for(int d=0; d<=3; d++)
    {
        int i_next=i+dl1[d];
        int j_next=j+dc1[d];
        if(isOk(i_next,j_next) && a[i_next][j_next]=='P' && VIZ[i_next][j_next]==0){
            maxy1++;
            dfs1(i_next,j_next);
        }
    }
}

bool cerintaUnu1(int i, int j)
{

    for(int d=0; d<=7; d++)
    {
        int i_next=i+dl[d];
        int j_next=j+dc[d];
        if(a[i_next][j_next]=='.' || i==n || j==m || i==1 || j==1) return true;
    }
    return false;
}


int cerintaUnu()
{
    int cate=0;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i][j]!='.' && cerintaUnu1(i,j)) cate++;
    return cate;
}



int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            fin>>a[i][j];


    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(VIZ[i][j]==0 && a[i][j]=='C')
            {
                cladiri++;
                dfs(i,j);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(VIZ[i][j]==0 && a[i][j]=='P')
            {
                maxy1=1;
                dfs1(i,j);
                maxy=max(maxy,maxy1);
            }
        }
    }
    fout<<cerintaUnu()<<" "<<cladiri<<" "<<maxy;


}
