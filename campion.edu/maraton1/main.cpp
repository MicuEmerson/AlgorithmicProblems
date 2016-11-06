#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("text.txt");

int n,k,contor;
int v[5005];

int tip(int i){

  if(i==-2){
    return 5;
  }
  if(i==-1){
    return 3;
  }
  return 2;

}


int main()
{
    int i;
    fin>>n>>k;
    for(i=1;i<=n;i++){
        fin>>v[i];
    }
    contor=k;
    for(i=1;i<=n;i++){

       if(v[i]!=0){

       }
       else{

          if(tip(v[i])-(contor%10)>0){
            contor+=k;
          }
          else{

          }

       }



    }


}











