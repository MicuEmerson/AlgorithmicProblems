#include <fstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <float.h>


using namespace std;
const int MAXN=1005;
int k,n,v[MAXN];
int dp[MAXN][105][105];

const int inf = 1 << 30;


int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>v[i];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 100; ++j)
            for (int t = 0; t < 100; ++t)
                dp[i][j][t] = inf;

    dp[0][0][0] = 0;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=i && j<=k;j++){

            // facem o noua subsecventa din ultimul element
            int valoare=inf;
            for(int t=0;t<=100;t++)
                valoare=min(valoare,dp[i-1][j-1][t]);

            dp[i][j][v[i]]=min (dp[i][j][v[i]], valoare + v[i]);

            for(int t=1;t<=100;t++) {
                int add = 0;
                if (t < v[i])
                    add = v[i] - t;
                dp[i][j][max(t, v[i])] = min (dp[i][j][max(t,v[i])], dp[i - 1][j][t] + add);
            }
        }
    }
    int miny=((1<<31)-1);
    for(int i=1;i<100;i++) miny=min(dp[n][k][i],miny);
    cout<<miny;



}
