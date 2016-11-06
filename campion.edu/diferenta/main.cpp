#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");

int n,m;
int pp[40000];
int v[201],dim=200;

void generare(){

  for(int i=1;i<=dim;i++){
    v[i]=i*i;
    pp[v[i]]=1;
  }
}
int cate(int x){

  int nr=0;
  int i=1;
  while(v[i]+x<=40000){
      if(pp[v[i]+x]==1){
        nr++;
      }
      i++;
  }
  return nr;

}

int main()
{
    fin>>n>>m;
    generare();

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;
            fin>>x;
            cout<<cate(x)<<" ";

        }
        cout<<"\n";
    }

}
