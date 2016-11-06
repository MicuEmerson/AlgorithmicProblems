#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

ifstream fin("text.txt");

int n,m;
int s[100][100];

void suma(int a[100][100]){

 for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
       s[i][j]+=a[i][j];

}

void afisare(){

 for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
        cout<<s[i][j]<<" ";
   }
   cout<<endl;

   }
}

bool isOk(int i, int j){

 if(i>=1 && j>=1 && i<=n && j<=n){
    return true;
 }
 return false;

}



void leeCombinat(int li, int ci){

 queue < pair < int, int > > coada;
 int a[100][100];
 int i,j,i_next,j_next;
 int dl[8]={-2,2,1,2,2,1,-1,-2};
 int dc[8]={1,-1,2,1,-1,-2,-2,-1};

 coada.push(make_pair(li,ci));
 a[li][ci]=1;

 while(!coada.empty()){

    i=coada.front().first;
    j=coada.front().second;
    coada.pop();
    for(int d=0;d<=7;d++){

        i_next=i+dl[d];
        j_next=j+dc[d];

        if(isOk(i_next,j_next) && a[i_next][j_next]==0 ){

            a[i_next][j_next]=a[i][j]+1;
            coada.push(make_pair(i_next,j_next));
        }
    }

 }
 suma(a);

}



int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++){
         int x,y;
         fin>>x>>y;
         leeCombinat(x,y);
         afisare();
         cout<<endl;
    }




}
