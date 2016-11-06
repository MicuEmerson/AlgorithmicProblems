#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("meteo1.in");
ofstream fout("meteo1.out");


int main()
{
    int n,v[1005],x,y,i,j,seg,segMax=-9999,gasit=0;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>v[i];
    }
    for(i=1;i<n;i++){

        j=i;
        seg=1;
        while(v[j]>=0 && v[j+1]<0 && j+1<=n || v[j]<0 && v[j+1]>=0 && j+1<=n){
            seg++;
            j++;
        }
        if(seg>=2){
            gasit=1;
        }
        if(seg>=segMax){
            segMax=seg;
            x=i;
            y=j;
        }
        i=j;

    }
    if(gasit==0){
        fout<<"0";
    }
    else{
    fout<<segMax<<endl;
    for(i=x;i<=y;i++){
        fout<<v[i]<<" ";
    }

    }


}
