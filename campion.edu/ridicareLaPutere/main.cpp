#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("lgput.in");
ofstream fout("lgput.out");
const int mod = 1999999973;

int putere(int a, int b) {
    if (b == 0)
        return 1;

    long long rez;

    if (b % 2 == 0) {
        rez = putere(a, b/2);
        return (rez * rez) % mod;
    }
    else {
        rez = putere(a, (b-1)/2);
        return ((1LL * a * rez) % mod * rez)%mod;
    }
}

// n ^ p
// p = 100101001 = (2 ^ 0 + 2 ^ 3 + 2 ^ 5 + 2 ^ 8)
// n ^ (2 ^ 0 + 2 ^ 3 + 2 ^ 5 + 2 ^ 8) = n ^ (2 ^ 0) * n ^ (2 ^ 3) * n ^ (2^5) * n ^ (2^8)

// n ^ (2 ^ 0) = n
// n ^ (2 ^ 0) * (n ^ (2^0)) = n ^ (2^1)
// n ^ (2^1) * n ^ (2^1)  = n ^ (2 ^ 2)


//(1 << i) = 1 00000 (de i ori)

//x & (1 << i) -> verifici daca bitul de pe pozitia i din x este 1

//x =  101001
//1<<i=001000    i= 3
//     001000


int putere2 (int n, int p) {

    long long rez = 1;

    for (int i = 0; (1 << i) <= p; ++i) {
        if (p & (1 << i))
            rez = rez * n % mod;
        n = 1LL * n * n % mod;
    }
    return rez;

}

// n = n ^ 1 = n ^ (2 ^ 0) =
// n * n = n ^ 2
// i = 0


int main()
{
    int n, p;
    fin >> n >> p;
    fout << putere2(n, p);
    return 0;
}
