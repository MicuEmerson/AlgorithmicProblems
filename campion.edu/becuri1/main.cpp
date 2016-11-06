#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("becuri2.in");
ofstream fout("becuri2.out");
int n,a,b;
int v1[100],v2[100],v[100];
int stinse,aprinse,sMax=-99999;

int main()
{
    int i,k;
    fin>>n>>a>>b;
    i=0;
    while(a>0)
    {
        v1[++i]=a%2;
        a/=2;
    }
    i=0;
    while(b>0)
    {
        v2[++i]=b%2;
        b/=2;
    }
    k=n;
    for(i=1; i<=n/2; i++)
    {
        swap(v1[i],v1[k]);
        k--;
    }
    k=n;
    for(i=1; i<=n/2; i++)
    {
        swap(v2[i],v2[k]);
        k--;
    }
    for(i=1;i<=n;i++){
        if(v1[i]==v2[i] && v1[i]==1){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
    }

    for(i=1;i<=n;i++){
        if(v1[i]!=v2[i]){
            if(v2[i]==1){
                aprinse++;
                v1[i]=1;
            }
            else{
                stinse++;
                v1[i]=0;
            }
        }
    }


    for(i=1;i<n;i++){

        int j=i+1;
        int s=1;
        while(v[i]==v[j] && v[i]!=0 && j<=n){
            s++;
            j++;
        }
        sMax=max(sMax,s);

    }
    fout<<stinse<<" "<<aprinse<<" "<<sMax<<endl;





}
