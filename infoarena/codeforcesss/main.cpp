#include <bits/stdc++.h>
using namespace std;


int v[20], n, maxim[20], nr;

void print()
{
    for (int i = 1; i <= maxim[n]; i++)
    {
        cout << "{ ";
        for (int j = 1; j <= n; j++)
            if (v[j] == i)
                cout << j << " ";
        cout << "}";
    }
    cout << "\n";
}

void back_tracking(int pas)
{
    if (pas == n + 1)
    {
        print();
        nr++;
    }
    else
        for (int i = 1; i <= maxim[pas - 1] + 1; i++)
        {
            v[pas] = i;
            maxim[pas] = max(maxim[pas - 1], i);
            back_tracking(pas + 1);
        }
}

int main()
{
    cout << "n = ";
    cin >> n;
    back_tracking(1);
    cout << "\n";
    cout <<"Number of elemenets: " << nr;
    return 0 ;
}
