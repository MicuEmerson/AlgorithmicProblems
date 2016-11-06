#include <iostream>
#include <fstream>
using namespace std;

int suma_tren(vector<int> tren) {
    int suma = 0;
    for (int i = 0; i < tren.size(); ++i)
        suma += tren[i];
    return suma;
}

void tren_functie (vector<int> &tren, int kCur) {
    if (kCur == k) {
        if (suma_tren(tren) > sol)
            sol = suma_tren(tren);
        return;
    }

    vector<int> tren1, tren2;

    for (int i = 0; i < tren.size(); ++i) {
        if (i % 2 == 0)
            tren1.push_back(tren[i]);
        else
            tren2.push_back(tren[i]);
    }

    tren_functie(tren1, kCur + 1);
    tren_functie(tren2, kCur + 1);

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
