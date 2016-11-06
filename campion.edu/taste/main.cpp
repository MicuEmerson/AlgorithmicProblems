#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("taste.in");
ofstream fout("taste.out");

pair < int , int > punct[100];
int v[4];
char c;
int i,j,x,nrMin[100][100],lin=0,nrMax=999999;
int cal,calMin=999999;

int nrCalorii(int a, int b)
{
    int nr=0;

    nr+=abs(punct[a].first-punct[b].first)+abs(punct[a].second-punct[b].second);

    return nr;
}


int main()
{
    //citiri
    for(i=0; i<=9; i++)
    {
        fin>>punct[i].first;
        fin>>punct[i].second;
    }
    int contor=0;
    for(i=1; i<=4; i++)
    {
        fin>>c;
        v[i]=(int)c-48;
        if(v[i]==0)
        {
            contor++;
        }
    }
    if(contor==4)
    {
        fout<<"0"<<endl<<"0000";
    }
    else
    {
        //parcurgere
        int nrA=0;
        int nrB=0;
        int n1,n2;
        int pX[100],dimX=0;
        int pY[100],dimY=0;
        nrA=nrA*10+v[1]*10+v[2];
        nrB=nrB*10+v[3]*10+v[4];

        for(i=0; i<=9; i++)
        {
            for(j=0; j<=9; j++)
            {
                n1=i*10+j;
                n2=i*10+j;
                if(n1%24==nrA)
                {
                    pX[++dimX]=n1;
                }
                if(n2%60==nrB)
                {
                    pY[++dimY]=n2;
                }
            }
        }

        for(i=1; i<=dimX; i++)
        {
            for(j=1; j<=dimY; j++)
            {
                cal=nrCalorii(pX[i]/10,pX[i]%10) + nrCalorii(pX[i]%10,pY[j]/10) + nrCalorii(pY[j]/10,pY[j]%10);
                if(cal<=calMin)
                {
                    calMin=cal;
                    lin++;
                    nrMin[lin][1]=pX[i]/10;
                    nrMin[lin][2]=pX[i]%10;
                    nrMin[lin][3]=pY[j]/10;
                    nrMin[lin][4]=pY[j]%10;
                    nrMin[lin][5]=cal;
                }
            }
        }

        fout<<calMin;
        for(i=1; i<=lin; i++)
        {
            if(nrMin[i][5]==calMin)
            {
                int nrrr=0;
                for(j=1; j<=4; j++)
                {
                    nrrr=nrrr*10+nrMin[i][j];
                }
                if(nrrr<nrMax)
                {
                    nrMax=nrrr;
                }
            }
        }
        fout<<endl<<nrMax;
    }
}
