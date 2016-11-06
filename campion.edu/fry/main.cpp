#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("fry.in");
ofstream fout("fry.out");
int n,k;
vector <int> v[2500];
int f[1005];

int main()
{
    cin>>n>>k;
    int n2=n*2;
    while(n2%k!=0)
    {
        n2++;
    }
    int dim=n2/k;
    cout<<dim;
    for(int i=1; i<=n; i++)
    {
        f[i]=2;
    }





}
