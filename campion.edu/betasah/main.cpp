#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("betasah.in");
ofstream fout("betasah.out");

int n,d,k,cate;
int a[1005][1005];
int f[1005],maxy=-9999;
pair < int , int > p[105];

bool isOk(int i, int j)
{

    if(i<=n && j<=i && j>=1 && i>=1 && a[i][j]!=1 && a[i][j]!=-1)
    {
        return true;
    }
    return false;
}

void marcare(int i, int j)
{

    int dl[8]= {0,1,1,1,0,-1,-1,-1};
    int dc[8]= {1,1,0,-1,-1,-1,0,1};
    int i_next,j_next;
    for(int d=0; d<=7; d++)
    {

        i_next=i+dl[d];
        j_next=j+dc[d];
        while(isOk(i_next,j_next))
        {
            if(a[i_next][j_next]!=2)
            {
                cate++;
                a[i_next][j_next]=2;
            }
            i_next+=dl[d];
            j_next+=dc[d];
        }
    }

}


int main()
{
    int i,x,y;
    fin>>n>>d>>k;
    for(i=1; i<=d; i++)
    {
        fin>>p[i].first>>p[i].second;
        a[p[i].first][p[i].second]=-1;
    }
    for(i=1; i<=k; i++)
    {
        fin>>x>>y;
        a[x][y]=1;
        f[x]++;
    }
    for(i=1; i<=n; i++)
    {
        maxy=max(maxy,i-f[i]);
    }
    fout<<maxy<<endl;



    for(i=1; i<=d; i++)
    {

        marcare(p[i].first,p[i].second);

    }
    fout<<cate;






}
