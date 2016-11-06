#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cadouri.in");
ofstream fout("cadouri.out");


int main()
{
    int f,b,n;
    int cb=0,cf=0;
    int i=1;
    int cadou;
    fin>>f>>b>>n;
    fin.get();
    while(i<=n){
            i++;
        fin>>cadou;
        if(cadou%2!=0){
            cb++;
        }
        else{
            cf++;
        }
    }

    if(cb>=b){
        b=0;
    }
    else{
        b=b-cb;
    }
    if(cf>=f){
        f=0;
    }
    else{
        f=f-cf;
    }
    fout<<f<<endl;
    fout<<b;
}




