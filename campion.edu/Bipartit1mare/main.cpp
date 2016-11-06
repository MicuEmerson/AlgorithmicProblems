/*
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");

int n,m,a[105][105],x,y,i,j;
int unu[105],dimUnu, doi[105], dimDoi;

int main()
{
    fin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        fin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    a[1][0]=-1;

    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(a[i][j]==1)
            {
                if(a[i][0]==-1)
                {
                    if(a[j][0]==0)
                    {
                        a[j][0]=-2;
                    }
                    else
                    {
                        if(a[j][0]==-1)
                        {
                            break;
                        }
                    }
                }
                else if(a[i][0]==-2)
                {
                    if(a[j][0]==0)
                    {
                        a[j][0]=-1;
                    }
                    else
                    {
                        if(a[j][0]==-2)
                        {
                            break;
                        }
                    }
                }
                else{

                    a[i][0]=-1;
                    cout<<"AAA"<<a[i][0]<<" "<<i<<endl;
                }
            }
        }
    }

    for(i=1;i<=n;i++){
            cout<<a[i][0]<<" ";
        if(a[i][0]==-1){
            unu[++dimUnu]=i;
        }
        else if(a[i][0]==-2){
            doi[++dimDoi]=i;
        }
    }
    cout<<endl;
    cout<<dimUnu<<" "<<dimDoi<<endl;

    if(dimUnu!=n && dimDoi!=n && dimUnu+dimDoi==n){

          cout<<"DA"<<endl;
          for(i=1;i<=dimUnu;i++){
            cout<<unu[i]<<" ";
          }
          cout<<endl;
          for(i=1;i<=dimUnu;i++){
            cout<<doi[i]<<" ";
          }
    }
    else{
        cout<<"NU";
    }
}
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("izolate.out");


int n,nrc,x,y;
int a[105][105];
int VIZ[105];

void DFS(int nod)
{
    VIZ[nod]=nrc;
    for(int i=1; i<=n; i++)
    {
        if(a[i][nod]==1 && VIZ[i]==0)
        {
            DFS(i);
        }
    }
}


int main()
{

    int n;
    fin>>n;
    while(fin>>x>>y)
    {
        a[x][y]=1;
        a[y][x]=1;
    }

    for(int i=1; i<=n; i++)
    {
        if(VIZ[i]==0)
        {
            nrc++;
            DFS(i);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<VIZ[i]<<" ";
    }


}





















