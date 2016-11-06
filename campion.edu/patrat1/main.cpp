#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("patrat1.in");
ofstream fout("patrat1.out");

int n,m,dimP,nrPatrate,dif,difMax=-9999;
int a[205][205];
pair < int , int > pereche[40000];
int dl[8]= {0,1,1,1,0,-1,-1,-1};
int dc[8]= {1,1,0,-1,-1,-1,0,1};

int isStea(int i, int j)
{
    int nr=0,nr2=0;
    int i_next,j_next;
    for(int d=0; d<=7; d++)
    {
        i_next=i+dl[d];
        j_next=j+dc[d];
        if(i_next<=n && j_next<=m && i_next>=1 && j>=1)
        {
            nr2++;
            if(a[i_next][j_next]<a[i][j])
            {
                nr++;
            }
        }
    }
    if(nr==nr2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

int main()
{
    int i,j,k;

    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {

            if(isStea(i,j)==1)
            {
                dimP++;
                pereche[dimP].first=i;
                pereche[dimP].second=j;
            }
        }
    }
    for(i=1; i<=dimP; i++)
    {
        a[pereche[i].first][pereche[i].second]=0;
    }

    //aflare patrate
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {
            if(a[i][j]==0)
            {

                k=j+1;
                while(k<=m)
                {

                    if(a[i][k]==0)
                    {

                        dif=k-j;

                        if(a[i+dif][j]==0 && a[i+dif][k]==0 && i+dif<=n)
                        {
                            nrPatrate++;
                            difMax=max(difMax,dif);
                        }
                    }
                    k++;
                }

            }
        }
    }
    fout<<dimP<<endl;
    fout<<nrPatrate<<endl;
    if(dimP==0)
    {
        fout<<"0";
    }
    else
    {
        fout<<difMax+1;
    }





}
