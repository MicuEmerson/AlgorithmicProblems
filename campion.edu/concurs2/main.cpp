#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#define INF 99;
using namespace std;

ifstream fin("concurs2.in");
ofstream fout("concurs2.out");

int dimNr,nrMutari,gasit;
int numar[1005],a[100][100],i,j;
char c[1005];

void read()
{
    fin>>dimNr>>nrMutari;
    fin.get();
    fin.get(c,1005);
    fin.get();

    for(i=0; i<=strlen(c); i++)
    {
        numar[i+1]=(int)c[i]-48;
    }

    for(i=0; i<=9; i++)
    {
        for(j=0; j<=9; j++)
        {
            fin>>a[i][j];
            if(a[i][j]==0)
            {
                a[i][j]=INF;
            }
            if(i==j){
                a[i][j]=0;
            }

        }
    }
}


void RF()
{
    int i,j,k;
    for(k=0; k<=9; k++)
    {
        for(i=0; i<=9; i++)
        {
            for(j=0; j<=9; j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}

void afisareGraf()
{

    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    int t;
    read();

    RF();

    for(i=1; i<=dimNr; i++)
    {
        gasit=0;
        for(j=9; j>=0 && gasit==0; j--)
        {
            if(nrMutari>=a[numar[i]][j] && numar[i]<j)
            {
                nrMutari=nrMutari-a[numar[i]][j];
                numar[i]=j;
                gasit=1;
                for(t=0; t<=9; t++)
                {
                    a[t][j]=INF;
                }
            }

        }
    }

    for(i=1; i<=dimNr; i++)
    {
        fout<<numar[i];
    }

}
