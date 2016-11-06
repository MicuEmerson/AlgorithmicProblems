#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("drenaj.in");
ofstream fout("drenaj.out");

int n,m,gasit,cate,cate1;
int VIZ[101][101];
int a[101][101];
int dl[4]= {0,-1,0,1};
int dc[4]= {1,0,-1,0};

int isOk(int i, int j)
{
    int i_next,j_next;
    for(int d=0; d<=3; d++)
    {
        i_next=i+dl[d];
        j_next=j+dc[d];
        if(i_next<=n && i_next>=1 && j_next<=m && j_next>=1 && a[i_next][j_next]<a[i][j])
        {
            return 1;
        }
    }
    return 0;

}

void dfs(int i, int j, int care)
{

    VIZ[i][j]=care;
    if(isOk(i,j)==1 && gasit==0)
    {
        gasit=1;
    }
    int i_next,j_next;
    for(int d=0; d<=3; d++)
    {
        i_next=i+dl[d];
        j_next=j+dc[d];
        if(i_next<=n && i_next>=1 && j_next<=m && j_next>=1 && a[i_next][j_next]==care && VIZ[i_next][j_next]==0)
        {
            dfs(i_next,j_next,care);
        }
    }

}


int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            gasit=0;
            if(VIZ[i][j]==0)
            {
                cate1++;
                dfs(i,j,a[i][j]);
            }

            if(gasit==1)
            {
                cate++;
            }
        }
    }

    fout<<cate1-cate;







}
