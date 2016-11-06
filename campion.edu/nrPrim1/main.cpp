#include <iostream>
#include <fstream>
using namespace std;

int getNrDivizori(int n) {
    int nrDiv = 1;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int curDiv = 0;
            while (n % i == 0) {
                ++curDiv;
                n /= i;
            }
            nrDiv *= (curDiv + 1);
        }
    }

    if (n != 1) {
        nrDiv *= 2;
    }

    return nrDiv;
}

int main()
{

    int a;
    cin >> a;

    for (int i = a + 1; ; ++i) {
        if (getNrDivizori(i) == 2) {
            cout << i;
            break;
        }
    }


    return 0;
}
