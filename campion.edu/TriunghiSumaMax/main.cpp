#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
int i,j;

void citireTriunghi(int a[100][100], int n){

  for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        fin>>a[i][j];
    }
  }
}

void afisareTriunghi(int a[100][100], int n){

  for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}


int nrMax(int a, int b){

 if(a>b){
    return a;
 }
 return b;


}

int sumaMax(int a[100][100], int n){

 int aux[100][100];

 //completam ultima linie
 for(j=1;j<=n;j++){
    aux[n][j]=a[n][j];

 }
 //completa restu
 for(i=n-1;i>=1;i--){
    for(j=1;j<=i;j++){

       aux[i][j]=a[i][j]+nrMax(aux[i+1][j],aux[i+1][j+1]);

    }
 }
 afisareTriunghi(aux,n);

}


int main()
{
    int a[100][100];
    int n;
    fin>>n;
    citireTriunghi(a,n);
    afisareTriunghi(a,n);
    sumaMax(a,n);

}
