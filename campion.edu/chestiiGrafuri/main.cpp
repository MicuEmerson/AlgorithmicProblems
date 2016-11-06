#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("text.txt");
ofstream fout("gears.out");

int a[1005][1005];
int n,m,x,y;

void RW()
{
    int i,j,k;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i!=j && j!=k && k!=i)
                {
                    if(a[i][k]==1 && a[k][j]==1)
                    {
                        a[i][j]=1;
                    }
                }
            }
        }
    }
}


int main()
{
    int i,j;
    fin>>n>>m;
    cout<<m<<endl;
    for(i=1; i<=m; i++)
    {
        fin>>x>>y;
        cout<<x<<" "<<y<<endl;
        a[x][y]=1;
    }
     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    RW();

}
