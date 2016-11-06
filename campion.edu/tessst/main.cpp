#include <iostream>
#include <vector>
using namespace std;

5 10 14 15 16
n = 20

template<class T>


vector < int > f(int n, vector < int > v)
{

    for (int i = 1; i < v.size(); ++i)
    {
        for (int j = v[i - 1] + 1; j <= v[i] - 1; ++j)
            v2.push_back(j);
    }
    return v2;
}
O(n + v.size())




int main()
{
    int n;
    cin>>n;
    f(n);
}

