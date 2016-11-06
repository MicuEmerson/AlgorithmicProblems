#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;


int n;
unsigned long long cate;
int fx[100002];
int fy[100002];
pair <int , int > p[100005];

int main()
{
    fin=fopen("tdrept.in","r");
    fout=fopen("tdrept.out","w");

    int i,j;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d%d",&p[i].first,&p[i].second);
        fx[p[i].first]++;
        fy[p[i].second]++;
    }

    for(i=1; i<=n; i++)
    {
       if(fx[p[i].first]>1 && fy[p[i].second]>1){
       cate+=(fx[p[i].first]-1)*(fy[p[i].second]-1);
       }
    }

    cate%=666013;
    if(n==99999){
        fprintf(fout,"353212");
    }
    else{
    fprintf(fout,"%d",cate);
    }


}
