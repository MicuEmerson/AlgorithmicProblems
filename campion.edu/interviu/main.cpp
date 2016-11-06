#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("interviu.in");
ofstream fout("interviu.out");

 int isOk(int v[100], int k){

   int i;
   for(i=1;i<=k-1;i++){
    if(v[k]<=v[i]){
        return 0;
    }
   }
   return 1;
 }


int main()
{
   int n,i,v[100],gasit=0;
   fin>>n;
   for(i=1;i<=n;i++){
    fin>>v[i];
   }
   i=4;
   while(i<=n && gasit==0){
    if(isOk(v,i)==1){
        gasit=1;
        fout<<i;
    }
    i++;
   }

   if(gasit==0){
    fout<<n;
   }


}
