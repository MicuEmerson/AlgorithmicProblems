#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("bete1.in");
ofstream fout("bete1.out");




int main()
{
    int a[1000], b[1000];
    int n,i,j,s=0,nrMaxA=-999,nrMaxB=-999,contor=0;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a[i];
        s+=a[i];
        if(nrMaxA<a[i]){
            nrMaxA=a[i];
        }
    }
     for(i=1;i<=n;i++){
        fin>>b[i];
        s+=b[i];
         if(nrMaxB<b[i]){
            nrMaxB=b[i];
        }
    }
    fout<<s/n<<endl;
    fout<<nrMaxA+nrMaxB<<endl;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(a[i]+b[j]==nrMaxA+nrMaxB){
            contor++;
            a[i]=0;
            b[j]=0;
        }
      }
    }
    fout<<contor;

}
