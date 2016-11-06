#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("furnica.in");
ofstream fout("furnica.out");

int n,k,s=0,mx,i,j,x;
int a[100][101];
int f[100][101],f2[202];
int dl[8]= {-1,-1,0,1,1,1,0,-1};
int dc[8]= {0,1,1,1,0,-1,-1,-1};
int i_actual,j_actual;

bool isOk(int i, int j)
{

    if(i>=1 && i<=n && j<=n && j>=1)
    {
        return true;
    }
    return false;

}


int main()
{
    fin>>n>>k;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j]=(i+j)%6;
        }
    }

    s+=a[1][1];
    a[1][1]=0;
    f[1][1]=1;
    i_actual=1;
    j_actual=1;
    for(i=1; i<=k; i++)
    {
        fin>>x;
        x--;
        if(isOk(i_actual+dl[x],j_actual+dc[x]))
        {
            i_actual+=dl[x];
            j_actual+=dc[x];
            s+=a[i_actual][j_actual];
            a[i_actual][j_actual]=0;
            f[i_actual][j_actual]++;
        }

    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            f2[f[i][j]]++;
            mx=max(mx,f[i][j]);

        }

    }

    fout<<s<<" "<<f2[mx];

}
