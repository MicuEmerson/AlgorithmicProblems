#include <iostream>

using namespace std;


template<class T>

T f(T a, T b) {
    return a + b;
}

vector<int>

//double f(double a, double b) {
//    return a + b;
//}

int main() {
    int a = 2;
    int b = 3;
    double c = 2.5;
    double d = 3.2;

    cout << f(a, b) << " " << f(c, d);
    return 0;
}
