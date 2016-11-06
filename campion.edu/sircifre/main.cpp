#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sircifre.in");
ofstream fout("sircifre.out");

int n,v[505],f[10];

void dublaEliminare(int v[505], int &n, int poz){

 int i;
 for(i=poz;i<n-1;i++){
    v[i]=v[i+2];
 }
 n-=2;

}


int main()
{
    int i;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>v[i];
    }
    for(i=1;i<n;i++){
        if(v[i]+1==v[i+1] || v[i]-1==v[i+1]){
            dublaEliminare(v,n,i);
            i=i-2;
        }
    }
    if(n==0){
        fout<<"-1";
    }
    else{
        for(i=1;i<=n;i++){
            f[v[i]]++;
        }
        for(i=0;i<=9;i++){
            if(f[i]>0){
                fout<<i<<" "<<f[i]<<endl;
            }
        }
    }






}



