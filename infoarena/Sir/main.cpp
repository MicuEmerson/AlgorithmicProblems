#include <bits/stdc++.h>
using namespace std;
ifstream fin("sir.in");
ofstream fout("sir.out");

const int MAXN=200005;
int n,X,Y,v[MAXN],z,inceputSir;
deque <int> deqMax,deqMin;

void insert_max(int poz)
{
    while(!deqMax.empty() && v[deqMax.back()] <= v[poz]) deqMax.pop_back();
    deqMax.push_back(poz);
}

int get_max(int poz)
{
    while(!deqMax.empty() && deqMax.front() <= poz) deqMax.pop_front();
    return v[deqMax.front()];
}

void insert_min(int poz)
{
    while(!deqMin.empty() && v[deqMin.back()] >= v[poz]) deqMin.pop_back();
    deqMin.push_back(poz);

}

int get_min(int poz)
{
    while(!deqMin.empty() && deqMin.front() <= poz) deqMin.pop_front();
    return v[deqMin.front()];
}

bool functie(int dimSecv)
{
    while(!deqMax.empty()) deqMax.pop_back();
    while(!deqMin.empty()) deqMin.pop_back();

    for(int i=1; i<=n; i++)
    {
        insert_max(i);
        insert_min(i);

        if(i>=dimSecv)
        {
            int rez = get_max(i-dimSecv) - get_min(i-dimSecv);

            if(rez<=z)
            {
                inceputSir=i-dimSecv+1;
                return true;
            }
        }
    }

    return false;
}

int cautare_binara()
{
    int st=X, dr=Y, m, last=-1;

    while(st<=dr)
    {
        m=(st+dr)/2;
        if( functie(m) )
        {
            last=m;
            st=m+1;
        }
        else dr=m-1;
    }

    return last;
}

int main()
{

    fin>>n>>X>>Y>>z;
    for(int i=1; i<=n; i++) fin>>v[i];

    int rezultatFinal = cautare_binara();

    if(rezultatFinal==-1) fout<<"-1";
    else fout<<rezultatFinal<<" "<<inceputSir<<" "<<inceputSir+rezultatFinal-1;


}
