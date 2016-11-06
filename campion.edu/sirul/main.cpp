#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("sirul.in");
ofstream fout("sirul.out");

/*
int main()
{
    char c[21][40000], aux[40000];
    int n,i=2;
    fin>>n;
    if(n==1){
        fout<<"a";
    }
    if(n==2){
        fout<<"b";
    }
    strcpy(c[1],"a");
    strcpy(c[2],"b");


    while(i<=n){
        i++;

        aux[0]=NULL;
       strcat(aux,c[i-1]);

       strcat(aux,c[i-2]);

       strcpy(c[i],aux);


    }
    fout<<c[n];
}
*/



int main(){

 int n,i;
 fin>>n;
 char s1[15000]="a", s2[15000]="b", s3[15000];
 for (int i=3; i<=n; i++){

    strcpy(s3,s2);
     strcat(s3,s1);
     strcpy(s1,s2);
     strcpy(s2,s3);


 }
 fout<<s3;


}








