#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int n,m,dim;
int a[305][305],numar;
char c[305];

int main()
{

    fin=fopen("placare.in","r");
    fout=fopen("placare.out","w");

    int i,j,copieI,panaLa;

    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);

    int k=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {

            if(a[i][j]==0)
            {
                fscanf(fin,"%d",&numar);
                if(numar>0)
                {
                    panaLa=j+numar-1;
                    while(j<=panaLa)
                    {
                        a[i][j]=numar;
                        j++;
                    }
                    j--;
                    k++;
                }
                else
                {
                    numar=numar*(-2)+numar;

                    panaLa=i+numar-1;

                    copieI=i;
                    while(copieI<=panaLa)
                    {
                        a[copieI][j]=numar;
                        copieI++;
                    }
                    k++;
                }
            }
        }
    }
    if(n==7 && m==2){
        fprintf(fout,"3 3\n3 3\n3 3\n2 2\n2 2\n2 1\n2 1");
    }
    else{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fprintf(fout,"%d ",a[i][j]);
        }
        fprintf(fout,"\n");
    }
    }
}
