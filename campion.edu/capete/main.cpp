#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("capete.in");
ofstream fout("capete.out");



int main()
{
    int n,capete;
    fin>>n;
    capete=n*6-n;
    fout<<capete;
}
