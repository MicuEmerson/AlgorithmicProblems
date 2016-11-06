#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("joct.in");
ofstream fout("joct.out");
int main()
{
    int n,dim,v[105],i,nr1,nr2,j;
    char c;

    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>dim;
        fin>>nr1;
        for(j=2; j<=dim; j++)
        {
            fin>>nr2;
            nr1=nr1^nr2;
        }
        fin>>c;


        if(nr1==0)
        {
            if(c=='G')
            {
                fout<<"I"<<endl;
            }
            else if(c=='I')
            {
                fout<<"G"<<endl;
            }
        }
        else
        {
            fout<<c<<endl;
        }


    }



}
