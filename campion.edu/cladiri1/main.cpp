
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("cladiri1.in");
ofstream fout("cladiri1.out");


typedef struct{

 int x;
 int y;
 int r;
} cladire;

int v[10005];

int main(){

 int i,lg,lt,intens,nvl,afectat=0,nvlMax=-99999,nrMax=-99999,gasit=0;
 cladire q;

 fin>>lg>>lt>>intens;
 fin.get();

 while(!fin.eof()){

    fin>>q.x;
    fin>>q.y;
    fin>>q.r;
    fin.get();
    nvl=max(abs(lg-q.x),abs(lt-q.y));

    if(intens-nvl>=q.r){
        afectat++;
        v[nvl]++;
        if(nvl>nvlMax){
            nvlMax=nvl;
            gasit=1;
        }
    }
}

fout<<afectat<<"\n";

 for(i=0;i<=nvlMax;i++){
    if(v[i]>nrMax){
        nrMax=v[i];
    }
 }

 if(gasit==1){
    fout<<nrMax<<"\n";
    for(i=0;i<=nvlMax;i++){
    if(v[i]==nrMax){
        fout<<i<<" ";
    }
 }
}
else{
    fout<<"0";
}


return 0;
fin.close();
fout.close();




}


/*
#include <fstream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
int x,y,lat,lon,in,gr,fr[10005],af,maxi,i,m,grad,nivel;

int main()
{
    freopen("cladiri1.in","r",stdin);
    freopen("cladiri1.out","w",stdout);

    scanf("%d %d %d",&lon,&lat,&in);

    while (scanf ("%d",&x)>=0)
    {
        scanf ("%d",&x);
        scanf ("%d",&y);
        scanf ("%d",&gr);

        nivel=max(abs(x-lat),abs(y-lon));
        grad=in-nivel;

        if (gr<=grad)
        {
            af++;
            fr[nivel]++;
        }
        m=max(m,nivel);
    }
    printf ("%d\n",af);

    for (i=0; i<=m; i++)
    {
        maxi=max(maxi,fr[i]);
    }
    printf ("%d\n",maxi);

    if (maxi !=0)
    {
        for (i=0; i<=m; i++)
        {
            if (maxi==fr[i])
            {
                printf ("%d ",i);
            }
        }
    }
    return 0;
}
*/
/*
#include <fstream>

#include <cstdio>

using namespace std;

int x,y,lat,lon,in,gr,fr[10005],af,maxi,i,m,grad,nivel;

int main()
{
    freopen("cladiri1.in","r",stdin);

    freopen("cladiri1.out","w",stdout);

    scanf("%d %d %d",&lon,&lat,&in);

    while (scanf ("%d",&x)>=0)
    {
        scanf ("%d",&y);
        scanf ("%d",&gr);

        int a=x-lon;
        if (a<0)a=a*(-1);

        int b=y-lat;
        if (b<0)b=b*(-1);

        nivel=max(a,b);

        grad=in-nivel;

        if (gr<=grad)
        {
            af++;
            fr[nivel]++;
        }

        m=max(m,nivel);
    }

    printf ("%d\n",af);

    for (i=0; i<=m; i++) maxi=max(maxi,fr[i]);

    printf ("%d\n",maxi);

    if (maxi !=0) for (i=0; i<=m; i++) if (maxi==fr[i]) printf ("%d ",i);

    return 0;

}
*/







