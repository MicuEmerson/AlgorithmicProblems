#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("matriosca.out");
const int MAXN=2550;
const int INF = (1 << 31) - 1;
int n,dim;
vector <int>  v[MAXN];
int v1[MAXN];

int BS(int nr){

 int st=1,dr=dim + 1,m, last = dim + 1;
 while(st<=dr){

    m=(st+dr)/2;
    if (v1[m] > nr) {
        last = m;
        dr = m - 1;
    }
    else
        st = m + 1;
 }
 return last;
}


int main()
{
    fill(v1 + 1, v1+ MAXN + 1,INF);
    fin>>n;
    for(int i=1;i<=n;i++){
         int x;
         fin>>x;
         int poz=BS(x);
         if(poz>dim)
            dim++;
         v[poz].push_back(i);
         v1[poz]=x;
    }
    cout<<dim<<"\n";
    for(int i=1;i<=dim;++i){
        cout<<v[i].size()<<" ";
        for(int j=0;j<v[i].size();++j){
           cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;

}

/*
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("matriosca.out");

const int MAXN=2550;
int n,x;
vector <int> v[MAXN],v1;
*/


















