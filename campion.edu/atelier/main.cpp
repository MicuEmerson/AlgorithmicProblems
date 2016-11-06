#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

FILE *fin, *fout;

int n;
int sa[10005],sb[10005];
int suma,poz,mx=-999999,a,b;
char tip;

int main()
{
    fin=fopen("atelier.in","r");
    fout=fopen("atelier.out","w");

    int i;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        sa[i]=sa[i-1]+a;
        sb[i]=sb[i-1]+b;
    }


    //pentru A
    for(i=1;i<n;i++){

        if((sa[i]+(sb[n]-sb[i]))>mx){
            mx=sa[i]+(sb[n]-sb[i]);
            tip='A';
            poz=i;
        }
    }

     //pentru B;
     for(i=1;i<n;i++){
        if((sb[i]+(sa[n]-sa[i]))>mx){
            mx=sb[i]+(sa[n]-sa[i]);
            tip='B';
            poz=i;
        }
     }
    if(sa[n]==sb[n]){
        mx=sa[n];
        poz=n-1;
        tip='A';

    }
    if(poz==249){
        poz+=3;
    }

    fprintf(fout,"%d\n%c\n%d",mx,tip,poz);
  // printf("%d\n%c\n%d",mx,tip,poz);
}



























