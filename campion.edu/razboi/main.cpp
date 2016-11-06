#include <iostream>
#include <fstream>
#define INF 999;
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int n,m,oras;
int a[502][502];


void RF(){

 for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
 }

}




int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,c;
        fin>>x>>y>>c;
        a[x][y]=c;
    }
    fin>>oras;
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                a[i][j]=0;
            }
            else if(a[i][j]==0){
                a[i][j]=INF;
            }
        }
    }
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;

    RF();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;





}
