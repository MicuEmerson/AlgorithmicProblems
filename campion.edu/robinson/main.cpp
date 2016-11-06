#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("robinson.in");
ofstream fout("robinson.out");

void creareMatrice(int a[100][100],int m, int n)
{

    int i,j;
    long suma;
    int nr=n;
    j=1;
    for(i=1; i<=m; i++)
    {
        a[i][j]=nr;
        a[j][i]=nr;
        nr++;
    }

    for(i=2; i<=m; i++)
    {
        for(j=2; j<=m; j++)
        {
            suma=(a[i-1][j]+a[i][j-1])%1000;
            a[i][j]=suma;

        }
    }
}




void parcurgere(int a[100][100], int m, int l, int c){

 int i,j,v[100][100];
 i=l;
 j=c;
 while(i>=1 && i<=m && j>=1 && j<=m && v[i][j]!=1){
    fout<<i<<" "<<j<<endl;
    v[i][j]=1;
    if(a[i][j]%4==0){
        i--;
    }
    else if(a[i][j]%4==1){
        j++;
    }
    else if(a[i][j]%4==2){
        i++;
    }
    else{
        j--;
    }
 }

}



int main()
{

    int n,m,l,c;
    int a[100][100];
    fin>>m>>n>>l>>c;
    creareMatrice(a,m,n);
    fout<<a[m][m]<<endl;
    parcurgere(a,m,l,c);





}
