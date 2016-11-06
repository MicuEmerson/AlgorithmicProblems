#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
//FILE *fin, *fout;
ifstream fin("pajura.in");
ofstream fout("pajura.out");


int n,m;
int v1[1010];
int v2[1010];
int v3[1010];
char c;

int isOk(int x[1010], int y[1010])
{
    for(int i=1; i<=x[0]; i++)
    {
        if(x[i]!=y[i]) return 0;
    }
    return 1;
}

int isOk1(int x[1010], int y[1010])
{
    int inv=x[0];
    for(int i=1; i<=x[0]; i++)
    {
        if(x[i]!=y[i]) return 0;
    }
    return 1;
}


int main()
{
    //fin=fopen("text.txt","r");
    //fout=fopen("text1.txt","w");
    while(1)
    {
       //fscanf(fin,"%d",&n);
        //fscanf(fin,"%d",&m);
        fin>>n>>m;
        if(n==0 && m==0){break;}
        v1[0]=m;
        v3[0]=m;
        int bun=1;
        for(int i=1; i<=m; i++)
        {
            //fscanf(fin,"%s",&c);
            fin>>c;
            if(c=='P'){
                v1[i]=1;
                v3[i]=0;
            }
            else{
                v1[i]=0;
                v3[i]=1;
            }
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                //fscanf(fin,"%s",&c);
                fin>>c;
                if(c=='P') v2[j]=1;
                else v2[j]=0;
            }
            if(isOk(v1,v2)==0 && isOk1(v3,v2)==0) bun=0;
        }

        //fprintf(fout,"%d\n",bun);
        fout<<bun<<"\n";
    }

}
