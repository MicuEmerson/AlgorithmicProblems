#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <set>
#include <ctype.h>
#include <string.h>

using namespace std;
ifstream fin("text.txt");
ofstream fout("secventa.out");

const int MAXN=1e5+5;
int n,k,v[MAXN];
deque < int > deqMin,deqMax;


int main()
{

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>v[i];


    for(int i=1; i<=n; i++)
    {

        while( !deqMax.empty() && v[i]>=v[deqMax.back()]) deqMax.pop_back();

        deqMax.push_back(i);



            cout<<v[deqMax.front()]<<" ";

            if(!deqMax.empty() && i-deqMax.front()>=k ) deqMax.pop_front();





    }




}
