#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
const int MAXN=5e4+5;
int n,t,x,cate;
int v[MAXN],s[MAXN];


/*
8 7 5 12 123 213
p1 = p2 = 1
p1 -> p2 ... ++p2
++p1

*/



int nrBiti(int nr)
{

    int cati=0;
    while(nr>0)
    {
        if(nr%2==1) cati++;
        nr/=2;
    }
    return cati;
}

int main()
{
    fin>>n>>t;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        v[i]=nrBiti(x);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int p1=1, s = 0;
    int p2=0;
    while(p2<=n + 1){

        if(s<t){
            s+=v[++p2];
        }
        else if(s==t){
            cate++;
            s+=v[++p2];
        }
        else{
            s-=v[p1++];
        }


    }
    cout<<cate;



}
