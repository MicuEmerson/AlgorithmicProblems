#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("pizza.in");
ofstream fout("pizza.out");
int n,f[3];
char c[100];

int main()
{
    int i,cate=0,miny;
    fin>>n;
    fin.get();
    for(i=1; i<=n; i++)
    {
        fin.get(c,100);
        fin.get();
        if(c[0]=='3')
        {
            f[3]++;
        }
        else if(c[strlen(c)-1]=='2')
        {
            f[2]++;
        }
        else
        {
            f[1]++;
        }
    }



    miny=min(f[1],f[3]);


    cate+=miny;


    f[1]=f[1]-miny;

    f[3]=f[3]-miny;
    cate+=f[2]/2;
    f[2]=f[2]%2;



    cate+=f[1]/4;

    f[1]=f[1]%4;

    cate+=f[3];

    f[3]=0;
    if(f[1]==3 && f[2]>0){
        cate=cate+2;
    }
    else if(f[1]==3 && f[2]==0){
        cate++;
    }
    else if(f[1]==1 || f[1]==2 && f[2]==0){
        cate++;
    }
    else{
        cate+=f[2];
    }

    fout<<cate;




}
