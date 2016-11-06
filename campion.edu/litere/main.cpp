
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("litere.in");
ofstream fout("litere.out");

int numar[10005],suma[10005];


int isPoz(char f[100], char c){

 for(int i=0;i<strlen(f);i++){
    if(f[i]==c){
        return i;
    }
 }
 return -1;

}

int main()
{
    int n,m,i,cate=0,dimF=-1,dimNumar=0,rest=0,dimS=0;

    char c[10005], f[100];
    int v[100];
    fin>>n;
    fin.get();
    fin>>c;
    fin>>m;
    //cate
    for(i=0;i<m;i++){
        int x;
        fin>>x;
        v[i]=x;
    }
    for(i=0;i<strlen(c)-1;i++){
        if(strchr("AEIOUaeiou",c[i])==0 && strchr("AEIOUaeiou",c[i+1])!=0 || strchr("AEIOUaeiou",c[i])!=0 && strchr("AEIOUaeiou",c[i+1])==0){
            cate++;
        }
    }
    cout<<cate<<endl;
    //sir litere distincte
    for(i=0;i<strlen(c);i++){
        if(!strchr(f,c[i])){

            f[++dimF]=c[i];
        }
    }
    f[++dimF]=NULL;

    //creare nr
    for(i=0;i<strlen(c);i++){
        numar[++dimNumar]=+v[isPoz(f,c[i])];
        cout<<numar[dimNumar];
    }
    cout<<endl;

    //creare suma
     for(i=dimNumar;i>=1;i--){

        suma[++dimS]=((i*numar[i])+rest)%10;
        rest=((i*numar[i])+rest)/10;
    }

    for(i=dimS;i>=1;i--){
        cout<<suma[i];
    }
}


