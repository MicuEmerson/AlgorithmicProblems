#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <deque>
using namespace std;
ifstream fin("maxk.in");
ofstream fout("maxk.out");

const int MAXN=1e6+5;
const int MAXVAL = 100001;
int v[MAXN],n,k;
int f[MAXVAL + 2];

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
        f[v[i]]++;
    }

    int j = 1, notOkay = 0, nrmin = MAXN;

    for (int i = 1; i <= MAXVAL; ++i)
        if (f[i] > k)
            notOkay++;

    for (int i = 1; i <= n; ++i)
    {
        while (notOkay && j <= n)
        {
            if (f[v[j]] == k + 1)
                --notOkay;
            )
            f[v[j]]--;
            j++;
        }
        if (notOkay > 0)  break;


        nrmin = min(nrmin, j - i);

        if (f[v[i]] == k)
            ++notOkay;
        f[v[i]]++;
    }

    cout << nrmin;


    return 0;
}
