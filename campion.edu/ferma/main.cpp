#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

typedef struct
{

    int nr;
    int ok;

} vvv;

vvv v[5005];
int n,nrT;
vector < int > t[5005];



int transport()
{

    int f[5005],suma[5005].rest[5005];


}


int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i].nr;
    }
    v[0].nr=n;
    transport();

}
