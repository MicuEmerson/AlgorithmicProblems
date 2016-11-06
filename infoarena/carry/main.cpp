#include <iostream>
#include <algorithm>
using namespace std;
const int mod=10000007,MAXN=1e6+5;
int t,x;
long long perfecte[MAXN],imperfecte[MAXN];

int main()
{

    perfecte[1]=4;
    imperfecte[1]=1;

    for(int i=2;i<MAXN;i++){
        imperfecte[i]=(perfecte[i-1]+imperfecte[i-1])%mod;
        perfecte[i]= imperfecte[i-1]*4%mod;
    }
    cin>>t;
    while(t--){
        cin>>x;
        cout<<(perfecte[x-1]*4)%mod<<"\n";
    }

}
