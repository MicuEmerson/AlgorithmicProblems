#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdlib>

using namespace std;


int main()
{
   long long n,m,c,a,i,j,nrMax=-999999999,x,y;
   cin>>n>>m;
   a=0;
   for(i=1;i<=n;i++){
        a++;
        c=1;
    for(j=1;j<=n;j++){
        if(abs(c-a)<abs(c-m)){
            if(abs(c-m)-abs(c-a) >nrMax){
                nrMax=abs(c-m)-abs(c-a);
            }
        }
        c++;
    }
   }
   cout<<nrMax;




}
