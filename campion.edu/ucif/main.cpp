#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <math.h>
using namespace std;

ifstream fin("ucif.in");
ofstream fout("ucif.out");



int main()
{
    int i,j,n;
    long s=0;
    long nr;
    fin>>n;
    for(i=1;i<=n;i++){
        nr=1;
        for(j=1;j<=i;j++){
            nr=nr*i%10;
        }
       s+=nr;
    }
   fout<<s%10;


}
