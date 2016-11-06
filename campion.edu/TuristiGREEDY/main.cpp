#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
/*
typedef struct{

   int start;
   int stop;

} vct;
vct v[1000];
int n,m,p,k,i,j;

void sortare(vct v[1000], int n)
{

    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(v[i].stop>v[j].stop)
            {
                swap(v[i].stop,v[j].stop);
                swap(v[i].start,v[j].start);

            }
        }
    }
}

void afisare(){
 for(i=1;i<=p;i++){
    cout<<v[i].start<<" "<<v[i].stop<<endl;
 }
 cout<<endl;
}


int main()
{
    fin>>k>>n>>m>>p;
    for(i=1;i<=p;i++){
        fin>>v[i].start;
        v[i].stop=v[i].start+m;
        if(v[i].stop>k){
            k=k+m;
        }
    }
    afisare();
    sortare(v,p);
    afisare();
}
*/

int n,m,p,k,i,j;
int x[365];

int cautaGhid(int start){





}


int main(){


  fin>>k>>n>>m>>p;
  for(i=1;i<=p;i++){
    fin>>j;
    x[j]++;
  }


}



























