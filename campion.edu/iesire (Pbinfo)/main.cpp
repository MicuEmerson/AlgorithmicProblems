#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("text.txt");

int a[105][105],viz[105][105],n,m,x,y,dim;
pair <int , int> poz[105];
int dl[4]= {0,-1,0,1};
int dc[4]= {1,0,-1,0};

bool isOk(int i, int j)
{
    if(i==n || j==n || i==1 || j==1) return true;
    return false;
}

int functie(int i, int j)
{

    viz[i][j]=1;
    dim++;
    poz[dim].first=i;
    poz[dim].second=j;
    for(int d=0; d<=3; d++)
    {
        int ii=i+dl[d];
        int jj=j+dc[d];
        cout<<ii<<" "<<jj<<endl;
        if(isOk(ii,jj) && a[ii][jj]==0) return 1;
        if(a[ii][jj]==0 && viz[ii][jj]==0)
            functie(ii,jj);
    }
    return 0;

}

int main()
{

    fin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) fin>>a[i][j];

    while(m--)
    {
        fin>>x>>y;
        dim=0;

        if(functie(x,y)) cout<<"da\n";
        else cout<<"nu\n";
        for(int i=1; i<=dim; i++) viz[poz[i].first][poz[i].second]=0;
    }

}
