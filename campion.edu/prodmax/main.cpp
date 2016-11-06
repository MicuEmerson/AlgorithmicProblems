#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("prodmax.in");
ofstream fout("prodmax.out");

int nrCifre(int n)
{

    int nr=0;
    while(n>0)
    {
        nr++;
        n/=10;
    }
    return nr;

}


int nrInterval(int v[100],int x,int y)
{

    int i,nr=0;
    for(i=x; i<=y; i++)
    {
        nr=nr*10+v[i];
    }
    return nr;
}



int main()
{
    int n,nrC,nrC2,i,j;
    int v[100];
    long long nr1,nr2, rezMax=-9999999999, rez,x=999999999,y;
    fin>>n;
    nrC=nrCifre(n);
    nrC2=nrC;

    while(n>0)
    {
        v[nrC]=n%10;
        nrC--;
        n/=10;
    }

    for(i=1; i<nrC2; i++)
    {
        for(j=i+1;j<=nrC2;j++){
            nr1=nrInterval(v,1,i);
            nr2=nrInterval(v,j,nrC2);
            rez=nr1*nr2;
            if(rez>=rezMax){
                rezMax=rez;
            }

        }
    }

     for(i=1; i<nrC2; i++)
    {
        for(j=i+1;j<=nrC2;j++){
            nr1=nrInterval(v,1,i);
            nr2=nrInterval(v,j,nrC2);
            rez=nr1*nr2;
            if(rez==rezMax){
                if(x>nr1){
                    x=nr1;
                    y=nr2;
                }
            }

        }
    }

    fout<<rezMax<<endl;
    fout<<x<<endl;
    fout<<y;



}
