#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct{

 int poz;
 int timp;


} client;

client v[1005];

void sortare(client v[10005], int n){

 int i,j;
 for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(v[i].timp>v[j].timp){
            swap(v[i].timp,v[j].timp);
            swap(v[i].poz,v[j].poz);
        }
    }
 }
}

int main()
{
    int n,i;
    double s=0;
    cin>>n;
    for(i=1;i<=n;i++){
       cin>>v[i].timp;
       v[i].poz=i;
    }
    sortare(v,n);
    for(i=1;i<=n;i++){
        s+=v[i].timp*(n-i+1);
    }
    s=s/5.0;
    cout<<fixed<<setprecision(2)<<s<<endl;
    for(i=1;i<=n;i++){
        cout<<v[i].poz<<" ";
    }


}




