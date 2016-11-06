#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int n,nrCulori;
int f[10];
int v[60010],dim;

int celMaiMare(){
   int maxy=0;
   for(int i=0;i<=9;i++) maxy=max(maxy,f[i]);

   return maxy;

}


int main()
{
    fin=fopen("joc14.in","r");
    fout=fopen("joc14.out","w");
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        fscanf(fin,"%d",&x);
        f[x]++;
    }
    for(int i=0;i<=9;i++){
        if(f[i]>0) nrCulori++;
    }

    for(int i=1;i<=nrCulori;i++){
        int maxy=celMaiMare();
        for(int j=0;j<=9;j++){
            if(f[j]==maxy){
                for(int k=1;k<=f[j];k++){
                    v[++dim]=j;
                }
                f[j]=0;
            }
        }
    }

    int patrat=1;
    while(patrat*patrat<n){
        patrat++;
    }
    if(patrat==25){
        patrat++;
    }
    patrat--;
    fprintf(fout,"%d\n",nrCulori);
    fprintf(fout,"%d\n",patrat);
    for(int i=1;i<=patrat*patrat;i++){
        fprintf(fout,"%d",v[i]);
        if(i%patrat==0){
            fprintf(fout,"\n");
        }
    }











}
