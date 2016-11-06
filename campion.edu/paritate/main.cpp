#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("paritate.in");
ofstream fout("paritate.out");

int putere(int n){

 int nr=1;
 for(int i=1;i<=n;i++){
    nr=nr*2;
 }
 return nr;

}



int main()
{
    int b[30000],i,nrDe1,dimB=0,alCatelea=-1,dimC=-1,numar,gasit=0;
    char c[2555],x,y;

    while(!fin.eof())
    {
        fin>>x;
        alCatelea++;
       // cout<<alCatelea<<endl;
        nrDe1=0;
        numar=0;
        for(i=7; i>=1 && !fin.eof(); i--)
        {
            fin>>y;
            if((int)y-48==1)
            {   numar+=putere(i-1);
                nrDe1++;
            }
        }

        if(nrDe1%2==1 && (int)x-48!=1 || nrDe1%2==0 && (int)x-48!=0 && !fin.eof()){
           // b[++dimB]=alCatelea;
            if(gasit==0){
                fout<<"NU"<<endl;
                gasit=1;
            }
            fout<<alCatelea<<" ";
        }
        c[++dimC]=(char)numar;

    }
    c[dimC]=NULL;


    if(gasit==0){
        fout<<"DA"<<endl;
        fout<<c;
    }
    /*
    else{
        cout<<"NU"<<endl;
        for(i=1;i<=dimB;i++){
            cout<<b[i]<<" ";
        }
    }
    */


}







