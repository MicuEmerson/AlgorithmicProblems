#include <iostream>
#include <fstream>
#define INF 10000000
using namespace std;

ifstream fin("text.txt");

int main()
{
    int n,m,c,l,i,j,li,ci,lf,cf,lv,cv,t;
    int a[100][100];
    int L[100][100];
    int dl[4]= {0,-1,0,1};
    int dc[4]= {1,0,-1,0};
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    for(i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    cin>>li>>ci>>lf>>cf;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            L[i][j]=INF;
        }
    }
    L[li][ci]=1;
    do
    {
        t=0;
        for(l=1; l<=n; l++)
        {
            for(c=1; c<=n; c++)
            {
                if(a[l][c]==0)
                {
                    for(int d=0; d<=3; d++)
                    {
                        lv=l+dl[d];
                        cv=c+dc[d];
                        if(lv>=1 && lv<=n && cv>=1 && cv<=n)
                        {
                            if(a[lv][cv]==0)
                            {
                                if(L[l][c]+1<L[lv][cv])
                                {
                                    L[lv][cv]=L[l][c]+1;
                                    t=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(t==1);

	if(L[lf][cf]==INF){
		cout<<"imposibil";
	}
	else{
		cout<<L[lf][cf];
	}

}

/*
#include <iostream>
#include <fstream>
#define INF 10000000
using namespace std;

ifstream fin("text.txt");

int main()
{
    int l,c,n,m,li,ci,lf,cf,t,lv,cv;
    int a[100][100];
    int L[100][100];
    int dl[4]= {0,-1,0,-1};
    int dc[4]= {1,0,-1,0};
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        a[x][y]=1;
    }
    fin>>li>>ci>>lf>>cf;
    for(l=1; l<=n; l++)
    {
        for(c=1; c<=n; c++)
        {
            L[l][c]=INF;
        }
    }
    L[li][ci]=1;
    do
    {

        t=0;
        for(l=1; l<=n; l++)
        {
            for(c=1; c<=n; c++)
            {
                if(a[l][c]==0)
                {
                    for(int d=0; d<=3; d++)
                    {

                        lv=li+dl[d];
                        cv=ci+dc[d];
                        if(lv>=1 && lv<=n && cv>=1 && cv<=n)
                        {
                            if(a[lv][cv]==0)
                            {
                                if(L[l][c]+1<L[lv][cv])
                                {
                                    L[lv][cv]=L[l][c]+1;
                                    t=1;
                                }
                            }
                        }

                    }
                }
            }
        }




    }
    while(t=1);






}
*/














