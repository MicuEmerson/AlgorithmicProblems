#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("text.txt");
ofstream fout("text1.txt");

int a[505],b[505],i,k=1;
int aux[505];
void permutareStanga(int v[505], int n){

  int aux;
  aux=v[1];
  for(i=1;i<n;i++){
    v[i]=v[i+1];
  }
  v[n]=aux;

}

void permutareDreapta(int v[505], int n){

 int aux;
 aux=v[n];
 for(i=n;i>1;i--){
    v[i]=v[i-1];
 }
 v[1]=aux;

}

void afisare(int v[505], int n){

  for(i=1;i<=n;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;


}

void dimCMLungSirCrescator(int v[505], int n){
 aux[n]=1;
 for(i=n-1;i>=1;i--){
    if(v[i]<v[i+1]){
        aux[i]+=aux[i+1]+1;
    }
    else{
        aux[i]=1;
    }
 }
  afisare(aux,n);




}



int main()
{
    int n;
    fin>>n;
    for(i=1;i<=n/2;i++){
        fin>>a[i];
    }
    for(i=1;i<=n/2;i++){
        fin>>b[i];
    }
    n=n/2;
    afisare(a,n);
    dimCMLungSirCrescator(a,n);
    while(k<=n-1){






        permutareStanga(a,n);
        permutareDreapta(b,n);
        k++;

     //   afisare(a,n);
        //afisare(b,n);
    }

















}
