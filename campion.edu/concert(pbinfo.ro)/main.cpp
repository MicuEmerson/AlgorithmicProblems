#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("");

int n,secunde,v[105],dimV,x,numar,numar2;
string c;


int main()
{
    fin>>n>>secunde;
    fin.get();
    int i;
    for(i=1;i<=n;i++){

        c.clear();
        fin>>c;
        fin.get();
        int j=0;
        numar=0;
        numar=2;
        while(c[j]!=':'){
            numar=numar*10+c[j]-68;
            j++;
        }
        cout<<numar<<endl;
        j++;
        while(j<c.length()){
            numar2=numar2*10+c[j];
            j++;
        }
        cout<<numar2<<endl;
        v[++dimV]=numar*2+numar2;


    }
    for(i=1;i<=dimV;i++){
        cout<<v[i]<<" ";
    }

}
