#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("h.in");
ofstream fout("h.out");

int main()
{
    int n,k,v[20000],i=1;
    fin>>n;
    while(n+i!=3*n){
        fout<<n+i<<" ";
        i++;
    }
    fout<<n*3;
}
