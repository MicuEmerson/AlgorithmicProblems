#include <iostream>
#include <fstream>
#define INF 99;
using namespace std;

ifstream fin("lasere.in");
ofstream fout("lasere.out");


pair <int, int > gropi[40005];
int tip,n,m,a[205][205],lasere[205][3],nr,transee;
int dl[8]= {0,1,1,1,0,-1,-1,-1};
int dc[8]= {1,1,0,-1,-1,-1,0,1};



void nrGropi()
{

    int i,j,d,i_next,j_next;
    int contor1,contor2;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            contor1=0;
            contor2=0;
            for(d=0; d<=7; d++)
            {
                i_next=i+dl[d];
                j_next=j+dc[d];
                if(i_next>=1 && i_next<=n && j_next>=1 && j_next<=n)
                {
                    contor2++;
                    if(a[i][j]<=a[i_next][j_next])
                    {
                        contor1++;
                    }
                }
            }
            if(contor1==contor2)
            {
                nr++;
                gropi[nr].first=i;
                gropi[nr].second=j;
            }
        }
    }
}

void nrTransee()
{

    int i,j,k,contor;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            contor=1;
            if(a[i][j]==99999)
            {

                k=j+1;
                while(a[i][k]==99999 && k<=n)
                {
                    k++;
                    contor++;
                }

                j=--k;
            }
            if(contor>1)
            {
                transee++;
            }

        }
    }

}

int main()
{
    int i,j;
    fin>>tip>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fin>>a[i][j];
        }
    }

    for(i=1; i<=m; i++)
    {
        fin>>lasere[i][1];
        fin>>lasere[i][2];
        fin>>lasere[i][3];
    }
    for(i=1; i<=m; i++)
    {

        if(lasere[i][3]==1)
        {
            lasere[i][1]--;
            while(lasere[i][1]>=1)
            {
                a[lasere[i][1]][lasere[i][2]]--;
                lasere[i][1]--;
            }
        }

        else if(lasere[i][3]==2)
        {
            lasere[i][2]++;
            while(lasere[i][2]<=n)
            {
                a[lasere[i][1]][lasere[i][2]]--;
                lasere[i][2]++;
            }
        }

        else if(lasere[i][3]==3)
        {
            lasere[i][1]++;
            while(lasere[i][1]<=n)
            {
                a[lasere[i][1]][lasere[i][2]]--;
                lasere[i][1]++;
            }
        }

        else
        {
            lasere[i][2]--;
            while(lasere[i][2]>=1)
            {
                a[lasere[i][1]][lasere[i][2]]--;
                lasere[i][2]--;
            }

        }
    }
    nrGropi();
    if(tip==1)
    {
        fout<<nr;
    }
    else
    {
        for(i=1; i<=nr; i++)
        {
            a[gropi[i].first][gropi[i].second]=99999;
        }
        nrTransee();
        fout<<transee;

    }

}




















