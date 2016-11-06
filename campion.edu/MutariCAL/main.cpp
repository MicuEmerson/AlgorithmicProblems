#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream fin("saritura_calului1.in");
ofstream fout("saritura_calului1.out");

int i,j,d,l_next,c_next;
int dl[8]= {-2,2,1,2,2,1,-1,-2};
int dc[8]= {1,-1,2,1,-1,-2,-2,-1};
  int a[101][101];
    int n,m,k=0,li,ci;

void mutariCal(int a[101][101],int n,int m, int li,int ci, int k)
{

    if(k==n*n)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }


    }
    else
    {
        for(d=0; d<=7; d++)
        {
            l_next=li+dl[d];
            c_next=ci+dc[d];
            if(l_next>=1 && l_next<=n && c_next>=1 && c_next<=m)
            {
                if(a[l_next][c_next]==0)
                {
                    a[l_next][c_next]=k+1;
                    mutariCal(a,n,m,l_next,c_next,k+1);
                    a[l_next][c_next]=0;
                }
            }
        }
    }
}


int main()
{


    cin>>n>>m>>li>>ci;
    mutariCal(a,n,n,li,ci,k);
    return 0;


}
