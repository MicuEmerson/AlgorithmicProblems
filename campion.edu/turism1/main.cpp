#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");

int n,m,k,x;

int main()
{   int i;
    fin>>n>>k>>m;
    for(i=1;i<=m;i++){

        while(fin>>x && x!=){
            cout<<x<<" ";
        }
        cout<<endl;


    }
}
