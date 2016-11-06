#include <iostream>
#include <string.h>

using namespace std;
    int a[100][100];
    int n,m;
int suma(int i, int j){

 s=0;
 s+=a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i+1][j+1]+a[i+1][j-1]+a[i-1][j-1]+a[i-1][j+1];
 return s;


}


int main()
{


    int i,j;

    char c[100][100];
    char cuv[255];
    fin>>cuv;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            fin>>c[i][j];
            if(c[i][j]==cuv[0]){
                a[i][j]=1;
            }
        }
    }



    for(int d=1;d<strlen(cuv);d++){

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(c[i][j]==cuv[d]){
                    a[i][j]+=suma(a,i,j)
                }
            }
        }





    }



}

//neterminata ( inca nu stiu cum sa o fac de complexitate mica ) de complexitate mare e usor
