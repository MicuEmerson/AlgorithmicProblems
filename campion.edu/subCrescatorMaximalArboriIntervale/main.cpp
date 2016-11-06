#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int MAXVALUE = 100010;

int n, v[MAXVALUE*4], p[MAXVALUE*4], maxy=-1,pozRez;
int v1[MAXVALUE],v2[MAXVALUE], t[MAXVALUE];

void update (int nod, int st, int dr, int poz, int x)
{
    if (st == dr)
    {
        v[nod] = x;
        p[nod] = poz;
        return;
    }
    int m = (st + dr) / 2;
    int nodStanga = nod * 2;
    int nodDreapta = nod * 2 + 1;

    if (poz <= m)
        update (nodStanga, st, m, poz, x);
    else
        update (nodDreapta, m + 1, dr, poz, x);

    if (v[nodStanga] > v[nodDreapta]) {
        v[nod] = v[nodStanga];
        p[nod] = p[nodStanga];
    }
    else {
        v[nod] = v[nodDreapta];
        p[nod] = p[nodDreapta];
    }
}

pair<int, int> query (int nod, int st, int dr, int left, int right)
{
    if (left <= st && dr <= right)
        return make_pair(v[nod], p[nod]);

    int m = (st + dr) / 2;
    int nodStanga = nod * 2;
    int nodDreapta = nod * 2 + 1;

    pair<int, int> rez;
    rez = make_pair(-1, -1);

    if (left <= m)
        rez = max(rez, query(nodStanga, st, m, left, right));
    if (right > m)
        rez = max(rez, query(nodDreapta, m + 1, dr, left, right));

    return rez;
}

// 7 3 1 3 20 5 10 2 3

// 7
// 3
// 1
// 1 2
// 1 2 20
// 1 2 5
// 1 3 5 10
// 1 2 3 4


int main()
{

    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>v1[i];
        v2[i]=v1[i];
    }
    sort(v2+1,v2+n+1);
    for(int i=1;i<=n;i++){

        v1[i]=lower_bound(v2+1,v2+n+1,v1[i])-v2 + 1;
    }

    for(int i=1;i<=n;i++){

        pair<int, int> rez=query(1,1,MAXVALUE,1,v1[i]-1);
        if (rez.first == 0)
            t[i] = -1;
        else
            t[i] = rez.second;
        if (rez.first+1 > maxy) {
            maxy = rez.first+1;
            pozRez = i;
        }
        update(1,1,MAXVALUE,v1[i],rez.first+1);

    }
    fout<<maxy << "\n";

    vector<int> q;
    q.push_back(v1[pozRez]);
    int p = pozRez;

    while (t[p] != - 1) {
        int val = t[p];

        while (p > 0) {
            if (v1[p] == val)
                break;
            --p;
        }

        q.push_back(v1[p]);
    }

    for (int i = q.size() - 1; i >= 0; --i)
        fout << v2[q[i] - 1] << " ";

    return 0;




}

