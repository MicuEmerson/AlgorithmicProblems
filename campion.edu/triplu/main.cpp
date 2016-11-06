#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("triplu.in");
ofstream fout("triplu.out");

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



int main(){

    int x,y,nrX,nrY,nrX2,nrY2,cx,cy,gasit=0,i;
    long nr=0;
    int v[100];
    fin>>x>>y;
    cx=x;
    cy=y;
    nrX=nrCifre(x);
    nrY=nrCifre(y);
    nrX2=nrCifre(x);
    nrY2=nrCifre(y);
    if(nrX>nrY){
        while(nrCifre(x)!=nrY){
            x/=10;
        }
    }
    else if(nrX<nrY){
        while(nrCifre(y)!=nrX){
            y/=10;
        }
    }

    if(x>y){
            gasit=1;
        nr=cx;
        while(cy>0){
            v[nrY]=cy%10;

            nrY--;
            cy/=10;
        }
    }
    else{
            gasit=2;
        nr=cy;
        while(cx>0){
            v[nrX]=cx%10;
            nrX--;
            cx/=10;
        }
    }
    if(gasit==1){
        for(i=1;i<=nrY2;i++){

            nr=nr*10+v[i];
        }
    }
    else{
        for(i=1;i<=nrX2;i++){
            nr=nr*10+v[i];
        }
    }

    fout<<nr*3;



}















