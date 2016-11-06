#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("comori.in");
ofstream fout("comori.out");






int main()
{
    int x=0,y=0,n,a,b;
    fin>>n;
    fin.get();
    int i=1;
    while(i<=n){
        i++;
        fin>>a>>b;
        fin.get();
        if(a==1){
            y=y+b;
        }
        else if(a==2){
            x=x+b;
            y=y+b;
        }
        else if(a==3){
            x=x+b;

        }
        else if(a==4){
            x=x+b;
            y=y-b;
        }
        else if(a==5){
            y=y-b;
        }
        else if(a==6){
            x=x-b;
            y=y-b;
        }
        else if(a==7){
            x=x-b;
        }
        else{
            x=x-b;
            y=y+b;
        }

    }
    fout<<x<<" "<<y;




}
