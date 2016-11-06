#include <fstream>

using namespace std;

ifstream fin("flori2.in");
ofstream fout("flori2.out");

int fibo[1000001];
int n;

int main()
{
    fin>>n;
    fibo[1]=1;
    fibo[2]=1;
    for(int i=3; i<=n+2; i++)
    {
        fibo[i]=(fibo[i-1]%9001+fibo[i-2]%9001)%9001;
    }
    fout<<fibo[n+2]-1;

}
