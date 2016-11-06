#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <ctype.h>
using namespace std;

ifstream fin("nrcuv.in");
ofstream fout("nrcuv.out");

string c;
int nrcuv;

int main()
{
    int i;
    getline(fin,c);

    for(i=0; i<c.length(); i++)
    {
        if(isalpha(c[i]))
        {
            while(isalpha(c[i]) && i<c.length() || c[i]=='-' && isalpha(c[i-1]) && isalpha(c[i+1]) && i<c.length())
            {
                i++;
            }
            nrcuv++;
        }

    }
    fout<<nrcuv;


}

















