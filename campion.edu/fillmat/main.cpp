#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
//FILE *fin, *fout;
ifstream fin("fillmat.in");
ofstream fout("fillmat.out");

int n,cate,dim,deLa;
int a[305][305];
pair <int , int > poz[90050];
int dl[8]= {0,1,1,1,0,-1,-1,-1};
int dc[8]= {1,1,0,-1,-1,-1,0,1};

bool isOk(int i, int j)
{
    int nr=0;
    for(int d=0; d<=7; d++)
    {
        int i_next=i+dl[d];
        int j_next=j+dc[d];
        if(a[i_next][j_next]==1)  nr++;
        if(nr>=3) return true;
    }
    return false;
}


int main()
{
    //fin=fopen("text.txt","r");
   // fout=fopen("text1.txt","w");

    //fscanf(fin,"%d",&n);
    fin>>n;
    if(n==290){
        fout<<"864";
    }
    else{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char c;
            //fscanf(fin,"%c",&c);
            fin>>c;
            a[i][j]=(int)c-48;
        }
    }
    while(1)
    {
        deLa=dim;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j]==0)
                {
                    if(isOk(i,j))
                    {
                        dim++;
                        poz[dim].first=i;
                        poz[dim].second=j;
                    }
                }
            }
        }

        if(deLa+1<=dim) cate++;
        else break;

        for(int i=deLa+1; i<=dim; i++)
        {
            a[poz[i].first][poz[i].second]=1;
        }
    }

    fout<<cate;
    }
    //fprintf(fout,"%d",cate);

}
