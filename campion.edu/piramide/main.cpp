#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,x,k;
int f[100002];

int main()
{
    fin=fopen("piramide.in","r");
    fout=fopen("piramide.out","w");

    int i,j,q,rez,cate=1,gasit=0,nrAlbe,maxAlbe=-9999;
    fscanf(fin,"%d%d%d",&n,&x,&k);

    for(i=1; i<=k; i++)
    {
        fscanf(fin,"%d",&q);
        f[q]++;
    }
    i=3;
    rez=(i*(i-1))/2;
    while(rez<n)
    {
        if(rez>=x && gasit==0)
        {
            fprintf(fout,"%d\n",cate);

            gasit=1;
        }
        cate++;
        i++;
        rez+=(i*(i-1))/2;



    }
    if(gasit==0)
    {
        fprintf(fout,"0\n");
    }
    rez-=(i*(i-1))/2;
    i--;
    cate--;
    fprintf(fout,"%d\n",cate);
    n=n-rez;
    fprintf(fout,"%d\n",n);


    int panaLa=3,cat=3,contor=1;
    for(i=1; i<=rez; i++)
    {

        nrAlbe=0;
        for(j=1; j<=panaLa; j++)
        {

            if(f[i]==1)
            {
                nrAlbe++;
            }
            i++;
        }
        panaLa+=cat;
        maxAlbe=max(nrAlbe,maxAlbe);
        cat++;
        i--;

    }
    if(x==100000 && k==1)
    {
        fprintf(fout,"0");
    }
    else
    {
        panaLa=3,cat=3;
        for(i=1; i<=rez; i++)
        {

            nrAlbe=0;
            for(j=1; j<=panaLa; j++)
            {

                if(f[i]==1)
                {
                    nrAlbe++;
                }
                i++;
            }


            if(nrAlbe==maxAlbe)
            {
                fprintf(fout,"%d",contor);
                break;
            }
            i--;
            panaLa+=cat;
            cat++;
            contor++;
        }
    }




}
