#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("reactivi.in");
ofstream fout("reactivi.out");

int n;
pair < int , int > p[8005];

void sortare(){

 int i,j;
 for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(p[i].second>p[j].second){
            swap(p[i],p[j]);
        }
        else if(p[i].second==p[j].second){
            if(p[i].first>p[j].first){
                swap(p[i],p[j]);
            }
        }
    }
 }

}


int main()
{
   int i,j,nr=1;
   fin>>n;
    for(i=1;i<=n;i++){
        fin>>p[i].first;
        fin>>p[i].second;
    }

    sortare();

    for(i=1;i<n;i++){
        j=i+1;

       if(p[i].second<=p[j].first){
         nr++;
       }
       else{
           while(p[i].second>p[j].first && j<=n){
                j++;
           }
           if(j<=n){
            nr++;
           }
           i=--j;
       }
    }
    fout<<nr;


}
