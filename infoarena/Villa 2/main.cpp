#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

const int MAXN=1e5+5;
int n,k,v[MAXN];
int bestDif=-((1<<31)-1);
deque <int> deqMin,deqMax;

void insertMin(int poz)
{
    while(!deqMin.empty() && v[poz]<=v[deqMin.back()])
        deqMin.pop_back();

    deqMin.push_back(poz);
}

void insertMax(int poz)
{
    while(!deqMax.empty() && v[poz]>=v[deqMax.back()])
        deqMax.pop_back();

    deqMax.push_back(poz);
}


int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++) fin>>v[i];

    for(int i=1; i<=n; i++)
    {
        insertMin(i);
        insertMax(i);

        if(i>=k+1)
        {
            int dif=v[deqMax.front()]-v[deqMin.front()];
            bestDif=max(bestDif,dif);

            if(!deqMax.empty() && i-deqMax.front()>=k) deqMax.pop_front();
            if(!deqMin.empty() && i-deqMin.front()>=k) deqMin.pop_front();
        }
    }
    fout<<bestDif;





}






















