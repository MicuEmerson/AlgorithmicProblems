#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("traseu2.in");
ofstream fout("traseu2.out");



int main()
{
    int a[101][101],n,x,y,i,j;
    char c[255];
    fin>>n>>x>>y;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            fin>>a[i][j];
        }
    }

    fin.get();
    fin.get(c,255);
    for(i=0;i<strlen(c);i++){
        if(c[i]=='N' && a[x-1][y]==0 && x-1>=1 && y<=n && y>=1){
            x--;
        }
        if(c[i]=='E' && a[x][y+1]==0 && y+1<=n && x<=n && y>=1){
            y++;
        }
        if(c[i]=='S' && a[x+1][y]==0 && x+1<=n && y<=n && y>=1){
            x++;
        }
        if(c[i]=='V' && a[x][y-1]==0 && y-1>=1 && x<=n && x>=1 ){
            y--;
        }

    }
    fout<<x<<" "<<y;
    fin.close();
    fout.close();

}




