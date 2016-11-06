#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pion.in");
ofstream fout("pion.out");

/*

dpj1[i][j] - daca primul jucator e la rand si se alfa in pozitia i, j care este suma maxima pe care o poate obtine (tinand cont ca celalalt jucator joaca optim)
dpj2[i][j] - al doilea jucator, i, j, care este suma minima pe care trebuie sa o dea (tinand cont ca celalalt jucator joaca optim)

dpj1[i][j] - max(dpj2[i + 1][j], dpj2[i][j + 1]);
dpj2[i][j] - min(dpj1[i + 1][j], dpj1[i][j + 1]);

*/

const int MAXN=250;
int n,m;
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];




int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        int x;
        fin>>x;
        dp1[n+1][i]=x;
        dp2[n+1][i]=x;
    }

    for(int i=1;i<=n;i++){
        int x;
        fin>>x;
        dp1[i][m+1]=x;
        dp2[i][m+1]=x;
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp1[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
            dp2[i][j] = min(dp1[i + 1][j], dp1[i][j + 1]);
        }
    }

    fout<<dp1[1][1];


}
