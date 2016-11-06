#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");


int n,x;
pair <int , int > pare[5005],impare[5005],rez[5005];

void transformare(int x, int poz)
{

    int numere[10],dim=0,nrPar=0,nrImp=0;
    while(x>0)
    {
        numere[++dim]=x%10;
        x/=10;
    }

    for(int i=dim; i>1; i-=2)
    {

        nrPar=nrPar*10+numere[i];
        nrImp=nrImp*10+numere[i-1];
    }

    impare[poz].first=nrPar;
    impare[poz].second=poz;
    pare[poz].first=nrImp;
    pare[poz].second=poz;
}


int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
       fin>>x;
        transformare(x,i);
    }
    sort(pare+1,pare+n+1);
    sort(impare+1,impare+n+1);

    for(int i=1; i<=n; i++)
        cout<<impare[i].first<<" "<<impare[i].second<<endl;

    cout<<endl<<endl;

    for(int i=1; i<=n; i++)
        cout<<pare[i].first<<" "<<pare[i].second<<endl;


    for(int i=1;i<=n;i++){

       // rez[pare[i].second].first=upper_bound(impare+1,impare+n+1,pare[i].first)-impare;

    }




}
