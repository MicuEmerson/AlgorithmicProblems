#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("balcon.in");
ofstream fout("balcon.out");

void creareMatriceSpirala(int a[50][50], int n, int v[2500])
{

    int i,j,nr=0;

    for(i=1; i<=n/2+1; i++)
    {
        for(j=i; j<=n-i+1; j++)
        {
            nr++;
            a[i][j]=v[nr];
        }

        for(j=i+1; j<=n-i+1; j++)
        {
            nr++;
            a[j][n-i+1]=v[nr];
        }

        for(j=n-i; j>=i; j--)
        {
            nr++;
            a[n-i+1][j]=v[nr];
        }

        for(j=n-i; j>=i+1; j--)
        {
            nr++;
            a[j][i]=v[nr];
        }
    }
}
void afisareMatrice(int a[50][50], int n){
 int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        fout<<a[i][j]<<" ";
    }
    fout<<endl;
  }



}
int main()
{
    int n,i;
    int v[2500],a[50][50];
    fin>>n;
    for(i=1;i<=n*n;i++){
        fin>>v[i];

    }
    sort(v+1,v+n*n+1);
    creareMatriceSpirala(a,n,v);
    afisareMatrice(a,n);
}
