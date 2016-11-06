#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

FILE *fin,*fout;
int v[100][105];
int dl[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
int n,m,cate,cateMax;
int a[100][105];
void ffill(int i, int j){

   int i_next,j_next;
   int d;
   v[i][j]=1;
   for(d=0;d<=3;d++){
    i_next=i+dl[d];
    j_next=j+dc[d];
    if(i_next<=n && i_next>=1 && j_next<=m && j_next>=1 && v[i_next][j_next]==0 && a[i_next][j_next]==0){
         cate++;
         ffill(i_next,j_next);
    }
   }
}
int main()
{

    fin=fopen("foto.in","r");
    fout=fopen("foto.out","w");
    int i,j;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            fscanf(fin,"%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]==0 && v[i][j]==0){
                cate=1;
                ffill(i,j);

            }
            cateMax=max(cate,cateMax);
        }
    }

     fprintf(fout,"%d",cateMax);
}
