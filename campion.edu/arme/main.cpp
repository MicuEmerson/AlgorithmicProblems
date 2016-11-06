#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("arme.in");
ofstream fout("arme.out");



int main()
{
    int n,m,i,j,s=0;
    int a[1000],b[1000];
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>a[i];
    }
    for(i=1;i<=m;i++){
        fin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    i=1;
    j=m;
    while(a[i]<b[j] && i<=n && j>0){
        a[i]=b[j];
        i++;
        j--;

    }

    for(i=1;i<=n;i++){
        s+=a[i];
    }
    fout<<s;
}













