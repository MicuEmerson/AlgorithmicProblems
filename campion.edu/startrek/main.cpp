#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("startrek.in");
ofstream fout("startrek.out");

typedef struct{

  int d;
  int v;
  int m;


} aaa;

aaa tot[4005];
int n,t,nr=1,cate=1;

void sortare(){

 for(int i=1;i<n;i++){
    for(int j=i+1;j<=n;j++){
        if(tot[i].m>tot[j].m){
            swap(tot[i],tot[j]);
        }
    }
 }
}
int main()
{
    fin>>n>>t;
    int i;
    for(i=1;i<=n;i++){
        fin>>tot[i].d;
    }
    for(i=1;i<=n;i++){
        fin>>tot[i].v;
        tot[i].m=tot[i].d/tot[i].v;
    }

    sortare();

    for(i=2;i<=n;i++){
      if(cate*t<=tot[i].m){
        nr++;
        cate++;
      }
    }
    fout<<nr;

}
