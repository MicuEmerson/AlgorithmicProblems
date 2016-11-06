#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
typedef struct{

  int nr;
  int f;

} vvv;

int n,k,dim,j,s;
int x[50000];
vvv v[50000];

void eliminare(int poz){

  for(int i=poz;i<=n;i++){
      v[i]=v[i+1];
  }
  dim--;
}

int main()
{
    //fin=fopen("turn.in","r");
   // fout=fopen("turn.out","w");

    fin=fopen("text.txt","r");
    fout=fopen("text1.txt","w");

    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&x[i]);
    }
    for(int i=1;i<=n;i++){
        dim++;
        v[dim].nr=x[i];
        v[dim].f=1;
        j=i+1;
        while(x[i]==x[j]){
            j++;
        }
        v[dim].f=j-i;
        i=j-1;
    }

    for(int i=1;i<=dim;i++){
        if(v[i].f>=k){
            eliminare(i);
            if(v[i].nr==v[i-1].nr){
                v[i].f+=v[i-1].f;
                eliminare(i-1);
                i--;
            }
            i--;
        }
    }
    for(int i=1;i<=dim;i++){
        s+=v[i].f;
    }

    fprintf(fout,"%d\n",s);
    for(int i=1;i<=dim;i++){
        for(int j=1;j<=v[i].f;j++){
            fprintf(fout,"%d ",v[i].nr);
        }
    }

}
