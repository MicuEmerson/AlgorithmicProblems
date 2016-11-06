#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("reactivi.in");
ofstream fout("reactivi.out");

int i,j,n,x,y,nr;
pair <int , int > punct[8000];



void sortare(){
  for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(punct[i].first>punct[j].first){
            swap(punct[i].first,punct[j].first);
            swap(punct[i].second,punct[j].second);
        }
        else if(punct[i].first==punct[j].first){
             if(punct[i].second<punct[j].second){
                swap(punct[i].second,punct[j].second);
             }
        }
    }
  }
}

void afisare(){

 for(i=1;i<=n;i++){
    cout<<punct[i].first<<" "<<punct[i].second<<endl;
 }
 cout<<endl;


}

int main()
{
    fin>>n;

    for(i=1;i<=n;i++){
        fin>>x>>y;
       punct[i].first=x;
       punct[i].second=y;
    }

     afisare();
    sortare();

     afisare();


    for(i=1;i<=n;){

        j=i+1;
        nr++;
        while(punct[i].second>=punct[j].first && i<=n &&j<=n){
            i++;
            j++;
        }
        i=j;
    }
    fout<<nr;



}
