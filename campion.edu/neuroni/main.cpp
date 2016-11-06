#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("neuroni.in");
ofstream fout("neuroni.out");

int a[101][101];
int v[101];
int n,m;

int main()
{
    fin>>n>>m;

    while(m--)
    {
        int i=1,j=1;
        while(i!=n)
        {
            if(i%2==0){
                if(a[i][j]==0){
                    a[i][j]=1;
                    i++;
                }
                else{
                    a[i][j]=0;
                    i++;
                    j++;
                }
            }
            else{
                if(a[i][j]==0){
                    a[i][j]=1;
                    i++;
                    j++;
                }
                else{
                    a[i][j]=0;
                    i++;
                }
            }
        }
        v[j]++;
    }
    for(int i=1;i<=n;i++){
        fout<<v[i]<<" ";
    }

}
