#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("figura.in");
ofstream fout("figura.out");

int main()
{
    int p=0,d,n,i,j,x,y;
    int a[100][100];
    fin>>d>>n;


    for(i=1;i<=n;i++){
        fin>>x;
        fin>>y;
        a[x][y]=1;

    }


    for(i=1;i<=d;i++){
        for(j=1;j<=d;j++){
            if(a[i][j]==1){
                if(a[i][j-1]==0){
                    p++;
                }
                if(a[i][j+1]==0){
                    p++;
                }
                if(a[i-1][j]==0){
                    p++;
                }
                if(a[i+1][j]==0){
                    p++;
                }
            }
        }
    }
    fout<<p;

}
