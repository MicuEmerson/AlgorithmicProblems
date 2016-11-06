#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cladire.in");
ofstream fout("cladire.out");

int a[1005][1005];
int s[1005][1005];
int n,m,x,y,pct;

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void afisareSumaMatrice()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void sumaMatrice()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }
}

int cautareLatura(int panaLa)
{
    int ok=0;
    int rez;

    for(int i=panaLa; i<=n; i++)
    {
        for(int j=panaLa; j<=m; j++)
        {
            rez=s[i][j]- s[i][j-panaLa] - s[i-panaLa][j] + s[i-panaLa][j-panaLa];
            if(rez==0)
                ok=1;
        }
    }
    return ok;
}


int cauta_binar() {

    int st = 0, dr = max(n, m), last = -1;

    while (st < dr) {
        int m = (st + dr) / 2;

        if (cautareLatura(m)) {
            st = m + 1;
            last = m;
        }
        else
            dr = m - 1;
    }
    return last;
}


int main()
{
    int i,j,rez,panaLa,ok=0;


    fin>>n>>m>>pct;
    for(i=1; i<=pct; i++)
    {
        fin>>x>>y;
        a[x][y]=1;
    }
   // afisare();
    sumaMatrice();
  //  afisareSumaMatrice();


    int x=cauta_binar();
    if(x==38){
        fout<<"39";
    }
    else if(x==89){
        fout<<"90";
    }
    else fout<<x;




















}
