#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
FILE *fin, *fout;
char c;
int k,n,cate,rest=0;
int f[101];


int main()
{

    fin=fopen("text.txt","r");
    fout=fopen("prefix1.out","w");

    fscanf(fin,"%d",&k);

    while(c=fgetc(fin) && (int)c>=48 && (int)c<=57)
    {

        rest=rest*10+((int)c-48);
        rest=rest%k;
        f[rest]++;
    }
    int maxy=-1;
    for(int i=0; i<k; i++)
    {
        maxy=max(maxy,f[i]);
    }
    for(int i=0; i<k; i++)
    {
        if(f[i]==maxy)
        {
            cout<<i<<" "<<maxy<<endl;
            fprintf(fout,"%d %d",i,maxy);
            break;
        }
    }


}
