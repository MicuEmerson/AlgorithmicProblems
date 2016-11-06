#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#define INF 10000000;
using namespace std;

ifstream fin("text.txt");
ofstream fout("alee.out");

void afisare(int a[200][200], int n){

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }



}




int main()
{

    int n,m,li,ci,lf,cf,lv,cv,i,j,d,x,y,t;
    int a[200][200],aux[200][200];
    int dl[4]= {-1,0,1,0};
    int dc[4]= {0,1,0,-1};
    fin>>n>>m;
    for(i=1; i<=m; i++)
    {
        fin>>x>>y;
        a[x][y]=1;
    }
    afisare(a,n);
    fin>>li>>ci>>lf>>cf;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            aux[i][j]=INF;
        }
    }
    aux[li][ci]=1;

    do
    {

        t=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {

                if(a[i][j]!=1)
                {

                    for(int d=0; d<=3; d++)
                    {
                        lv=i+dl[d];
                        cv=j+dc[d];
                    }
                    if(lv>=1 && lv<=n && cv>=1 && cv<=n)
                    {

                        if(a[lv][cv]==0)
                        {

                            if(aux[i][j]+1<aux[lv][cv])
                            {

                                aux[lv][cv]=aux[i][j]+1;
                                t=1;
                            }

                        }
                    }

                }
            }
        }
    }
    while(t==1);
    afisare(aux,n);

    cout<<aux[lf][cf];




}





