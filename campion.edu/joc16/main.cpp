#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("joc16.in");
ofstream fout("joc16.out");




int main()
{
    int fR[40000],fB[40000],v[40000];
    int i,j,n,x,y,s=1,r=0;
    fin>>n>>x>>y;
    for(i=1;i<=n;i++){
        fR[i]=0;
        fB[i]=0;
    }
    i=1;
    j=n+1;
    i+=x;
    j-=y;
    fR[1]=1;
    fB[1]=1;
    while(i!=j && fR[i]==0 && fB[j]==0){
        s++;
        fR[i]=1;
        fB[j]=1;
        if(i+x<=n){
            i+=x;
        }
        else{
            i=n-i;
            i=x-i;
        }

        if(j-y>=1){
            j-=y;
        }
        else{
            j=y-j;
            j=n-j;
        }
    }
    fB[j]=1;
    fR[i]=1;
    for(int ii=1;ii<=n;ii++){
        fB[ii]+=fR[ii];
        if(fB[ii]==0){
            r++;
        }
    }

    fout<<r<<" "<<s<<" "<<i<<" "<<j;







}
