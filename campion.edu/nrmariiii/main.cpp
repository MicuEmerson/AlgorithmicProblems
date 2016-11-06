#include <iostream>
#include <fstream>

using namespace std;

struct NumereMari {
    int a[1000];

    NumereMari operator + (NumereMari b) {
        NumereMari rez;
        int i, t = 0;

        for (i = 1; i <= a[0] || i <= b.a[0]; ++i) {
            rez.a[i] = (t += a[i] + b.a[i]) % 10;
            t = t / 10;
        }
        if (t)
            rez.a[i++] = 1;
        rez.a[0] = i - 1;

        return rez;

    }

};


NumereMari v1, v2;


int main() {
    v1.a[0] = 2;
    v1.a[1] = 1;
    v1.a[2] = 1;

    v2.a[0] = 2;
    v2.a[1] = 1;
    v2.a[2] = 1;

    v1 = v1 + 2;
	return 0;
}




