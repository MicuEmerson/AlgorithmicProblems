#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

const int MAXN=252;

int a[MAXN][MAXN],s[MAXN][MAXN],f[1002];
int n,m;


int main()
{

     for(int i=1; i<=n; i++)
     {
         for(int j=i+1; i<=n; i++)
         {
             int d1 = bestcolt1[i][n];
             int d2 = beststart[i + 1][j][n];
             int d3 = bestcolt3[j + 1][n];

             if (d1 + d2 + d3 > maxim)
                 maxim = d1 + d2 + d3;
         }
     }

    // configuratia 3
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
 // mai esti ?
            // zona 1

            int d1Suma = -(1<<30);

            for (int c1x = 1; c1x <= i; ++c1x)
                for (int c1y = 1; c1y <= j; ++c1y)
                    for (int c2x = c1x; c2x <= i; ++c2x)
                        for (int c2y = c1y; c2y <= j; ++c2y)
                        {
                            int suma = 0;
                            for (int t = c1x; t <= c2x; ++t)
                                for (int k = c1y; k <= c2y; ++k)
                                    suma += v[t][k];
                            if (suma > d1Suma)
                                d1Suma = suma;
                        }
            // zona 2

            int d2Suma = (-1<<30);

            for (int c1x = i+1; c1x <= n; ++c1x)
                for (int c1y = 1; c1y <= j; ++c1y)
                    for (int c2x = c1x; c2x <= n; ++c2x)
                        for (int c2y = c1y; c2y <= j; ++c2y)
                        {
                            int suma = 0;
                            for (int t = c1x; t <= c2x; ++t)
                                for (int k = c1y; k <= c2y; ++k)
                                    suma += v[t][k];
                            if (suma > d2Suma)
                                d2Suma = suma;
                        }


           int d3Suma = (-1<<30);

            for (int c1x = 1; c1x <= n; ++c1x)
                for (int c1y = j+1; c1y <= m; ++c1y)
                    for (int c2x = c1x; c2x <= n; ++c2x)
                        for (int c2y = c1y; c2y <= m; ++c2y)
                        {
                            int suma = 0;
                            for (int t = c1x; t <= c2x; ++t)
                                for (int k = c1y; k <= c2y; ++k)
                                    suma += v[t][k];
                            if (suma > d3Suma)
                                d3Suma = suma;
                        }
        }

    }



















}
















