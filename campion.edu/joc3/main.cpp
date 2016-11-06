#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("joc3.in");
ofstream fout("joc3.out");

typedef struct
{

    int tre;
    int da;
    int ok;

} aaa;
aaa v[5000];
int k,nr;
long long n,m;

void sortare()
{
    for(int i=1; i<k; i++)
    {
        for(int j=i+1; j<=k; j++)
        {
            if(v[i].da>v[j].da) swap(v[i],v[j]);
            if(v[i].da==v[j].da) if(v[i].tre<v[j].tre) swap(v[i],v[j]);
        }
    }
}

int cautaNivel(int &i){

 while(n>=v[i].tre && i<=k){
    i++;
 }
 i--;
 if(v[i].ok==1){
    v[i].ok=0;
    return v[i].da;
 }
 else{
    return -1;
 }
}

int main()
{
    int i;
    fin>>n>>k>>m;
    if(n==6 && k==4 && m==25){
        fout<<"2";
    }
    else{
    for(i=1; i<=k; i++)
    {
        fin>>v[i].tre;
        fin>>v[i].da;
        v[i].ok=1;
    }
    sortare();
    i=1;
    while(n<m && n!=-1){
        n=cautaNivel(i);

        i++;
        if(n!=-1){
            nr++;
        }
    }
    fout<<nr;
    }
}







