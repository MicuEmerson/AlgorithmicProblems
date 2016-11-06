#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

ifstream fin("text.txt");
ofstream fout("stele1.out");

void afisare( unsigned long long a[9][2])
{

    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=2; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int nrCifre(long long n){

 int nr=0;
 while(n>0){
    nr++;
    n/=10;
 }
 return nr;
}








void eliminare(int v[10], int &n, int poz)
{

    for(int i=poz; i<=n; i++)
    {
        v[i]=v[i+1];
    }
    n--;


}

int main()
{
    unsigned long long a [9][2];
    int nr1=2,nr2=8;
    int i,j;
    a[1][1]=1;
    a[2][1]=12;
    a[3][1]=123;
    a[4][1]=1234;
    a[5][1]=12345;
    a[6][1]=123456;
    a[7][1]=1234567;
    a[8][1]=12345678;
    a[9][1]=123456789;
    a[1][2]=9;
    a[2][2]=98;
    a[3][2]=987;
    a[4][2]=9876;
    a[5][2]=98765;
    a[6][2]=987654;
    a[7][2]=9876543;
    a[8][2]=98765432;
    a[9][2]=987654321;
    int k;
    long long n,aa,bb;
    int v[10];
    int dimV=0;
    fin>>k>>n>>aa>>bb;

    if(a[k][1]>a[k][2])
    {
        cout<<a[k][1];
    }
    else
    {
        cout<<a[k][2];
    }
    cout<<endl;
    while(n>0)
    {
        v[++dimV]=n%10;
        n/=10;
    }
    int q=dimV;
    for(i=1; i<=dimV/2; i++)
    {
        swap(v[i],v[q]);
        q--;
    }

    if(v[1]==1)
    {
        for(i=1; i<dimV; i++)
        {
            if( v[i]+1!=v[i+1])
            {
                eliminare(v,dimV,i+1);
                i--;
            }
        }

    }
    else
    {

        for(i=1; i<dimV; i++)
        {
            if( v[i]-1!=v[i+1])
            {
                eliminare(v,dimV,i+1);
                i--;
            }
        }
    }
     q=dimV;
     long long numar=0;
    for(i=1; i<=dimV; i++)
    {
        numar=numar*10+v[i];
    }
    cout<<numar<<endl;


    int nrA,nrB,nrA2,nrB2;
    nrA=nrCifre(aa);
    nrA2=nrA;
    nrB=nrCifre(bb);
    nrB2=nrB;
    int contor2=0;
    while(nrB>nrA){
        contor2++;
        nrB--;
    }
    contor2--;

    int nrSpeciale=0;
    nrSpeciale=contor2*+2;

    if(aa<=a[nrA2][1]){
        nrSpeciale++;

    }
    if(aa<=a[nrA2][2]){
        nrSpeciale++;

    }
    if(bb<=a[nrB2][1]){
        nrSpeciale++;

    }
    if(bb<=a[nrB2][2]){
        nrSpeciale++;

    }
    cout<<nrSpeciale;



}





