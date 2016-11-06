#include <bits/stdc++.h>

using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

const int mod = 666013;
string a,b;
int sA, sB, putere = 1;


int main()
{
    cin>>b>>a;
    for(int i=0; i<b.size(); i++) sB = ( sB*26 + (int)b[i] ) % mod;

    for(int i=0; i<b.size()-1; i++) sA = ( sA*26 + (int)a[i] ) % mod,


    for (int i=0; i<b.size()-1; i++)
        putere = putere*26 % mod;



    for(int i=b.size()-1; i<a.size(); i++)
    {
        sA = ( sA*26 + (int)a[i] ) % mod;

        if(sA == sB)
        {
            cout<<i - b.size() + 1 << "\n";
        }

        sA = ( sA+mod - (int)a[i] * putere) % mod;

    }

}
