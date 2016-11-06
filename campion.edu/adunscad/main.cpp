#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("adunscad.in");
ofstream fout("adunscad.out");

int can[22][365];
int rez[22][365];
int v[22],dim;

int n,m,x;

int main()
{
    fin>>n>>m;
    n+=180;
    can[0][180] = 1;
    for(int i=1; i<=m; i++)
    {
        fin>>x;

        for(int j=0; j<=360; j++)
        {
            if(can[i-1][j])
            {
                can[i][j+x]=1;
                rez[i][j+x]=x;

                can[i][j-x]=1;
                rez[i][j-x]=-x;
            }
        }
    }

    if(can[m][n])
    {
        for(int i=m; i>=1; i--)
        {
            v[++dim]=rez[i][n];
            n-=rez[i][n];
        }
         fout<<v[dim];
        for(int i=dim-1; i>=1; i--)
        {
            if(v[i]>0)
                fout<<"+"<<v[i];
            else
                fout<<v[i];
        }
    }
    else
        fout<<0<<endl;

}
