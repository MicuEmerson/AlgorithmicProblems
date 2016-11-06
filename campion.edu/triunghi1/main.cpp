#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("triunghi1.in");
ofstream fout("triunghi1.out");

int main()
{
    int l,c,x;
    fin>>l>>c;
    x = (l*(l+1))/2 - (l-c);
    if(x%9==0)
    {
        fout<<"9";
    }
    else
    {
        fout<<x%9;
    }
}
