#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("text.txt");
ofstream fout("insule.out");

int n,m,a[101][101],VIZ[101][101];
int nr1,nr2,nr3;
int dl[4]= {0,-1,0,1};
int dc[4]= {1,0,-1,0};
queue < pair < int , int > > Q;


bool isOk(int i,int j)
{
    if(i<=n && i>=1 && j<=m && j>=1) return true;

    return false;
}

bool isBun(int i,int j)
{
    for(int d=0;d<=3;d++){
        int i_next=i+dl[d];
        int j_next=j+dc[d];
        if(a[i_next][j_next]=='1') return true;
    }
    return false;
}

int dfs(int i,int j, int tip)
{
    VIZ[i][j]=1;
    for(int d=0; d<=3; d++)
    {
        int i_next=i+dl[d];
        int  j_next=j+dc[d];
        if(isOk(i_next,j_next) && a[i_next][j_next]==tip && VIZ[i_next][j_next]==0) dfs(i_next,j_next,tip);
    }
}

void lee()
{


}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char c;
            fin>>c;
            a[i][j]=(int)c-48;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(VIZ[i][j]==0)
            {
                if(a[i][j]==1)
                {
                    nr1++;
                    dfs(i,j,1);
                }
                else if(a[i][j]==2)
                {
                    nr2++;
                    dfs(i,j,2);
                }
                else if(a[i][j]==3)
                {
                    nr3++;
                    dfs(i,j,3);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(isBun(i,j) && a[i][j]==0) Q.push(make_pair(i,j));

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    while(!Q.empty()){
        cout<<Q.front().first<<" "<<Q.front().second<<endl;
        Q.pop();
    }










}
