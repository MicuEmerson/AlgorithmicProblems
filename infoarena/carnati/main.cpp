#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("carnati.in");
ofstream fout("carnati.out");

const int MAXN=2e3+5;
int n,c,rez;
pair <int , int> v[MAXN];


int solve(int price)
{
    int sol = 0 , sum = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        sum = sum - c * (v[i].first - v[i - 1].first);
        if(sum < 0)
            sum = 0;
        if(v[i].second >= price)
            sum = sum + price;
        sol = max(sol , sum - c);
    }

    return sol;
}

int main()
{

    fin>>n>>c;
    for(int i=1; i<=n; i++)
        fin>>v[i].first>>v[i].second;

    sort(v+1,v+n+1);

    for(int i=1; i<=n; i++)
        rez=max(rez,solve(v[i].second));

    fout<<rez;



}
