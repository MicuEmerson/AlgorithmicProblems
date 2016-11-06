#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("porumb.in");
ofstream fout("porumb.out");

int main()
{
    int n,m,s=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        fin>>x;
        s+=x;
    }
    if(m-1 < n-m){
        s=s+(m-1)+(n-1);
    }
    else{
        s=s+(n-m)+(n-1);
    }
    fout<<s;

}
