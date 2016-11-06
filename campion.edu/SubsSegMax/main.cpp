#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ssm.in");
ofstream fout("ssm.out");

// i - in sirul tau ... cauti un j astfel incat suma sir[j .. i] maxim
// sir[j ... i] = sir[1 .. i] - sir[1 .. j -1]
// min dintre sume partiale care se ermina in intervalul 1..i


int main()
{
    int n,x,s=0,sMax=-999999999, pozInceput = 1, st, fn;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        s+=x;
        if(s>sMax)
        {
            sMax=s;
            st = pozInceput;
            fn = i;
        }

        if (s < 0) {
            s = 0;
            pozInceput = i + 1;
        }

    }
    fout<<sMax<<" "<<st<<" "<<fn;



}
