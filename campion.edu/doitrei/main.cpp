#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("doitrei.in");
ofstream fout("doitrei.out");

int main()
{
    int n,v[1005],i,k=0;
    fin>>n;
    v[++k]=5;

    i=1;
    while(i<=n-2){
        v[++k]=4;
        i++;
    }
    v[++k]=2;
    i=1;
    while(i<=n-2){
        v[++k]=8;
        i++;
    }
    v[++k]=9;
    for(i=1;i<=k;i++){
        fout<<v[i];
    }

}
