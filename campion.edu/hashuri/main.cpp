/*

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

const int MOD = 1000000; // to do verificam pe infoarena cum merge si cu alte valori
vector < int > hashuri[MOD];


int get_hash(int x) {
    return x%MOD;
}

void add(int x)
{
    int y=get_hash(x);
    int found=0;

    for (auto it : hashuri[y])
        if(it==x){
            found=1;
            break;
        }


    if(!found)
        hashuri[y].push_back(x);


}

void del(int x)
{
    int y=get_hash(x);
    for (auto it = hashuri[y].begin(); it != hashuri[y].end(); ++it)
        if (*it == x) {
            hashuri[y].erase(it);
            return;
        }
}

int exist(int x)
{
    int y=get_hash(x);
    for (auto it : hashuri[y])
        if(it==x)
            return 1;

    return 0;
}




int main()
{
    int n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int tip,val;
        fin>>tip>>val;
        if(tip==1)
        {
            add(val);
        }
        else if(tip==2)
        {
            del(val);
        }
        else
        {
            fout<<exist(val)<<"\n";
        }
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <unordered_set>
using namespace std;
ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

unordered_set<int> s;

int main() {
    int n; fin >> n;

    for (int i = 1; i <= n; ++i) {
        int x, tip;
        fin >> tip >> x;
        if (tip == 1)
            s.insert(x);
        if (tip == 2)
            s.erase(x);
        if (tip == 3)
            fout << (s.find(x) != s.end()) << "\n";
    }
    return 0;
}























