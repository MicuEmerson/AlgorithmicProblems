#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("pluton.in");
ofstream fout("pluton.out");
typedef struct
{

    int nr;
    int f[10];
    int pluton;


} vvv;
vvv v[4005];
int freg[4005];

int n,nrPluton=0;
int nrMax,nr,nrCate,carePluton;

int isIdentice(int a[10], int b[10])
{
    int i,j;
    for(i=0; i<=9; i++)
    {
        for(j=0; j<=9; j++)
        {
            if(a[i]!=b[i])
            {
                return 0;
            }
        }
    }
    return 1;
}


int main()
{
    int i,j,copie;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i].nr;
        copie=v[i].nr;

        while(copie>0)
        {
            v[i].f[copie%10]++;
            copie/=10;
        }
    }

    for(i=1; i<=n; i++)
    {
        if(v[i].pluton==0)
        {
            v[i].pluton=++nrPluton;
            nr=1;
            for(j=i+1; j<=n; j++)
            {
                if(v[j].pluton==0)
                {
                    if(isIdentice(v[i].f,v[j].f)==1)
                    {
                        v[j].pluton=nrPluton;
                        nr++;
                    }

                }
            }
           if(nr>nrMax){
            nrMax=nr;
            carePluton=v[i].pluton;
           }
        }
    }
    for(i=1;i<=n;i++){
        freg[v[i].pluton]++;
    }
    for(i=1;i<=n;i++){
        if(freg[i]==nrMax){
            nrCate++;
        }
    }
    fout<<nrPluton<<endl<<nrMax<<endl<<nrCate<<endl;




    for(i=1;i<=n;i++){
        if(v[i].pluton==carePluton){
            fout<<v[i].nr<<" ";
        }
    }







}
