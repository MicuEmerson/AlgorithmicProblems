#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cartonas.in");
ofstream fout("cartonas.out");
typedef struct
{

    int nr[105];
    int nivel;
    int nrC1;

} vvv;

int n,x,s;
vvv v[105];

int cmp(vvv a, vvv b){

 if(a.nrC1>b.nrC1){
    return 1;
 }
 else if(a.nrC1==b.nrC1){
     if(a.nivel<b.nivel){
        return 1;
     }
 }
 return 0;

}


int tBinara(int numar){

   int nr=0;
   while(numar>0){
      if(numar%2==1){
        nr++;
      }
      numar/=2;
   }
   return nr;
}



int main()
{
    int i,j;

    fin>>n>>x;
    for(i=1; i<=n; i++)
    {
        fin>>v[1].nr[i];
    }
    v[1].nivel=1;
    for(i=2; i<=n; i++)
    {
        v[i].nivel=i;
        for(j=1; j<=n-i+1; j++)
        {

            v[i].nr[j]=v[i-1].nr[j]+v[i-1].nr[j+1];

        }
    }

    for(i=1; i<=n; i++)
    {
        s=0;
        for(j=1; j<=n-i+1; j++)
        {
           s+=v[i].nr[j];
        }
        v[i].nrC1=tBinara(s);
    }
    fout<<v[n].nr[1]<<endl;

    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            if(v[i].nr[j]==x){
                fout<<v[i].nivel<<endl;
                break;
            }
        }
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++){
        fout<<v[i].nivel<<" ";
    }


}
