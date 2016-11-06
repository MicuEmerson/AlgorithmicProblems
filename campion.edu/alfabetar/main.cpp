#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin("text.txt");
ofstream fout("alfabetar.out");

int main()
{

    char c[255][255];
    int n,i,j,col=-999999;
    fin>>n;
    fin.get();
    for(i=1; i<=n; i++)
    {
        fin.get(c[i],255);
        if((int)strlen(c[i])>col)
        {
            col=(int)strlen(c[i]);
        }
        fin.get();
    }

    for(j=col-1;j>=0;j--){
        for(i=1;i<=n;i++){
            if(isalpha(c[i][j]) || c[i][j]==NULL){
               cout<<c[i][j];
            }
        }
        cout<<endl;
    }


}

























