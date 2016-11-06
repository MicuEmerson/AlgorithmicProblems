#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");
int n,apa,fara;
int a[101][101];

int main()
{

    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int alCatelea,cate;
        fin>>alCatelea>>cate;
        a[alCatelea][0]=cate;
        for(int j=1; j<=cate; j++)
        {
            fin>>a[alCatelea][j];
        }
    }
    fin>>apa>>fara;

    for(int i=1; i<=n; i++)
    {
        sort(a[i]+1,a[i]+a[i][0]+1);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=a[i][0]; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
