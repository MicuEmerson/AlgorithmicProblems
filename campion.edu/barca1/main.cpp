#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

struct comparator {

  bool operator() (pair<int, int> &a, pair<int, int> &b) const
  {
      if (a.first == b.first)
        return a.second > b.second;
      return a.first < b.first;
  }
};


priority_queue< pair<int, int>, vector<pair<int, int> >, comparator > heap;

const int nrPitici = 10;
const int maxIndici = 200100;

int n, m, g, sol[nrPitici + 1], indici[maxIndici];

int main()
{
    freopen("barca1.in", "r", stdin);
    freopen("barca1.out", "w", stdout);
    scanf("%d%d%d", &n, &g, &m);
    for (int i = 1 ; i <= nrPitici; ++i)
        scanf("%d", &sol[i]);

    n += m;

    int curSum = 0, scosi = 0;

    for (int i = 1; i <= n; ++i)
    {
        int pitic;
        scanf("%d", &pitic);

        heap.push(make_pair(pitic, i));
        curSum += pitic;

        if (curSum > g)
        {
            pair<int, int> a = heap.top();
            heap.pop();

            curSum -= a.first;
            indici[a.second] = ++scosi;
        }
    }

    for (int i = 1; i <= nrPitici; ++i)
        printf("%d\n", indici[sol[i]]);

    return 0;
}



