#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("baschet.in");
ofstream fout("baschet.out");

int main()
{
    int n,v[1000],i,j,contor,contorMax=-999,x,y,s=0,gasit=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }

    for(i=1; i<n && gasit==0; i++)
    {
        j=i;
        contor=1;
        while(v[j]==v[j+1] && j+1<=n){
            j++;
            contor++;
        }

        if(contor>=3){
            x=i;
            y=j;
            gasit=1;
        }
        i=j;

    }

    if(gasit==0){

        fout<<"1"<<" "<<v[1];
    }
    else{
    for(i=x;i<=y;i++){
        s+=v[i];
    }
    fout<<contor<<" "<<s;
    }

}







