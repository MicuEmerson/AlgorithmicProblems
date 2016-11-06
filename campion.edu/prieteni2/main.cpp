#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("prieteni2.in");
ofstream fout("prieteni2.out");

void eliminarePoz(int v[100], int &n, int poz){

 int i;
 for(i=poz;i<n;i++){
    v[i]=v[i+1];
 }
 n--;
}

int main()
{

    int n,i;
    int v[1000];
    int mic=9999;
    int s=0;
    fin>>n;
    if(n==1){
        fin>>s;
    }
    else{
    for(i=1;i<=n;i++){
        fin>>v[i];
        if(v[i]<mic){
            mic=v[i];
        }
        s+=v[i];
    }
    s=s-mic;
    for(i=1;i<=n;i++){
        if(v[i]==mic){
            eliminarePoz(v,n,i);
            break;
        }
    }
    s+=(n-1)*mic;

   }

    fout<<s;

}
