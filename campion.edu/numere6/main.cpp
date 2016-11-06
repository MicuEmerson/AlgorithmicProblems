#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

ifstream fin("numere6.in");
ofstream fout("numere6.out");


int laPutere(int n){

 int rez=1;
 for(int i=1;i<=n;i++){
    rez=rez*2;
 }
return rez;



}


void eliminarePoz(int v[100], int &n, int poz)
{

    for(int i=poz; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;
}

int transformareBinara(int a, int b)
{

    int dimA=0;
    int dimB=0;
    int k,j,i;
    int va[100];
    int vb[100];

    //a
    while(a>0)
    {
        va[++dimA]=a%2;
        a/=2;
    }
    k=dimA;
    for(j=1; j<=dimA/2; j++)
    {
        swap(va[j],va[k]);
        k--;
    }

    //b
    while(b>0)
    {
        vb[++dimB]=b%2;
        b/=2;
    }
    k=dimB;
    for(j=1; j<=dimB/2; j++)
    {
        swap(vb[j],vb[k]);
        k--;
    }




    while(va[1]==vb[dimB] && dimA>0 && dimB>0)
    {
        eliminarePoz(va,dimA,1);
        eliminarePoz(vb,dimB,dimB);


    }




     k=dimA;
    for(j=1; j<=dimA/2; j++)
    {
        swap(va[j],va[k]);
        k--;
    }


    k=dimB;
    for(j=1; j<=dimB/2; j++)
    {
        swap(vb[j],vb[k]);
        k--;
    }




    b=0;
    a=0;
    if(dimA==0)
    {
        for(i=dimB; i>=1; i--)
        {
            if(vb[i]==1)
            {
                b+=laPutere(i-1);
            }
        }
    }
    else if(dimB==0)
    {

        for(i=dimA; i>=1; i--)
        {
            if(va[i]==1)
            {
                a+=laPutere(i-1);
            }
        }

    }
    else if(dimA==0 && dimB==0){
        return 0;
    }
    else
    {

        for(i=dimB; i>=1; i--)
        {
            if(vb[i]==1)
            {
                b+=laPutere(i-1);
            }
        }


        for(i=dimA; i>=1; i--)
        {
            if(va[i]==1)
            {
                a+=laPutere(i-1);
            }
        }
    }

    return a+b;





}



int main()
{  int a,b,s;
   fin>>a>>b;
   s=transformareBinara(a,b);
   fout<<s;

}















