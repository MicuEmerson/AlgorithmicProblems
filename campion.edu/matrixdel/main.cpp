#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
using namespace std;

ifstream fin("matrixdel.in");
ofstream fout("matrixdel.out");

void stergereLinie(int a[100][100], int &n, int m, int lin){

 int i,j;
 for(i=lin;i<n;i++){
    for(j=1;j<=m;j++){
        a[i][j]=a[i+1][j];
    }
 }
 n--;
}

void stergereColoana(int a[100][100], int n, int &m, int col){

 int i,j;
 for(i=1;i<=n;i++){
    for(j=col;j<m;j++){
        a[i][j]=a[i][j+1];
    }
 }
 m--;


}

void citireMatrice(int a[100][100], int n, int m){

 int i,j;
 for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        fin>>a[i][j];
    }
 }

}

void afisareMatrice(int a[100][100], int n, int m){

 int i,j;
 for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        fout<<a[i][j]<<" ";
    }
    fout<<endl;
 }

}

int main()
{
    int n,m,nrLin,nrCol,x,i,j=0;
    int a[100][100];
    fin>>n>>m;
    citireMatrice(a,n,m);
    fin>>nrLin;
    for(i=1;i<=nrLin;i++){
        fin>>x;
        x+=j;
        stergereLinie(a,n,m,x);
        j--;
    }
    fin>>nrCol;
    j=0;
    for(i=1;i<=nrCol;i++){
        fin>>x;
        x+=j;
        stergereColoana(a,n,m,x);
        j--;
    }
    afisareMatrice(a,n,m);


}
