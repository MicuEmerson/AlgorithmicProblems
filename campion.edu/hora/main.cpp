#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("hora.in");
ofstream fout("hora.out");

int v[145050],dim,s;
string x;

int main()
{
    while(!fin.eof())
    {
        fin>>x;
        if(x[x.size()-1]=='*')
            v[++dim]=1;
        else
            v[++dim]=0;
    }

    for(int i=1; i<=dim; i++)
    {
        int j=i+1;
        int cat=0;
        while(v[i]==v[j] && j<=dim)
        {
            cat++;
            j++;
        }
        s+=cat;
        i+=cat;
    }

    if(v[1]==v[dim]) s++;

    fout<<s;


}
