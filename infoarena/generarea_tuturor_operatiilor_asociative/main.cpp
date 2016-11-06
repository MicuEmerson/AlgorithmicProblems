#include <iostream>
using namespace std;

// generarea tuturor operatiilor asociative

int m[10][10], n;
long long s;

int check()
{
    //(a o b) o c = a o (b o c)
    for(int a=1; a<=n; a++)
        for(int b=1; b<=n; b++)
            for(int c=1; c<=n; c++)
                if(m[m[a][b]][c] && m[a][m[b][c]])
                    if(m[m[a][b]][c] != m[a][m[b][c]])
                        return 0;
    return 1;
}

void gen(int lin, int col)
{
    if(lin > n)
    {
        s++;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cout<<m[i][j]<<' ';
            cout<<'\n';
        }
        cout<<'\n';
    }
    else
    {
        for(int nr = 1; nr <= n; nr++)
        {
            m[lin][col] = nr;

            if(check())
                (col == n ? gen(lin+1, 1) : gen(lin, col+1));

            m[lin][col] = 0;
        }
    }


}

int main()
{
    cin >> n;
    gen(1, 1);
    cout << s;
}
