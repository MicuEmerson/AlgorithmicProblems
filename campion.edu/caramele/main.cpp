#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");

int n,t,v[10001];

int main()
{
    fin>>n>>t;
    for(int i=1; i<=n; i++)
    {
        fin>>v[i];
    }
    int cate=1,cate2=0;
    while(cate>0)
    {

        cate=0;
        for(int i=2; i<=n; i++)
        {
            if(v[i-1]+1!=v[i] || v[i-1]+1!=v[i] || v[i-1]+1==v[i] && v[i+1]+1==v[i] || v[i-1]-1==v[i] && v[i+1]-1==v[i])
            {
                if(i+1<=n)
                {
                    swap(v[i-1],v[i]);
                    cate++;
                }
            }
        }
        cate2+=cate;
    }
    cout<<cate2;


}
