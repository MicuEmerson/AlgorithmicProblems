#include <bits/stdc++.h>
using namespace std;
ifstream fin("suma.in");
ofstream fout("suma.out");
/*
long long  n,mod,s;

int f(int n, int m){
    if (solve[n][m])
        return rez[n][m];
    if(m==0 || m==n)
        return 1;
    else
        return f(n-1,m-1)+f(n-1,m);
}

int f(int i){


    if(i == n) {
        return 0;
    }
    sir[i] = 0;
    f(i + 1);
    sir[i] = 1;
    f(i + 1);
}

int solve(int x1,int y1, int x2, int y2)
{
    int mx=(x1+x2-1)/2;
    int my=(y1+y2-1)/2;

    if(x1==x2) return 10;

    for(int i=x1; i<=mx; i++)
        for(int j=y1; j<=my; j++)
            a[i][j]=1;

   int rez1 =  solve(x1,my+1,mx,y2);
   int rez2 =  solve(mx+1,y1,x2,my);
   int rez3 =  solve(mx+1,my+1,x2,y2);


   cout<<rez1+rez2+rez3;
}

int n,m,a[100][100];
void recur(int i, int j, int n, int m)
{
    if(i==n+1) return;
    if(j==m+1)
    {
        cout<<endl;
        recur(i+1,1,n,m);
        return;
    }


    cout<<a[i][j]<<" ";
    recur (i,j+1,n,m);

}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    recur(1,1,n,m);


}
*/
int nr;
void f(int i, int j)
{


    if( i<=j  ) return;
     cout<<i << " " << j <<" "<< ++nr<<endl;


    f(i-2, j-1);  // primul apel
    f(i-3 , j -1);  // al doilea apel

}

/*
f(10,3) -> f(8,2) -> f(6,1) -> f(4,0) -> f(2,-1) -> f(0,-2)  -> f(-2,-2)

f(-2,-2) -> return;
f(0,-1)  -> f(-3, -2) -> return;

f(2,-1)  -> f(-1,-2)  -> f(-3,-3) -> return;

f(-1,-2) -> f(-4,-3) -> return;

f(4,0) -> f(1,-1) -> f(-1, -1) -> return ;

f(1,-1) -> (-2,-1) -> return ;
*/



int main()
{

    f(7,4);

}




