#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
using namespace std;

ifstream fin("joc20.in");
ofstream fout("joc20.out");


int main()
{
    int n,i,primu=1,ultimu;
    int v[1000];
    int x;
    int s1=0,s2=0;
    fin>>n;
    ultimu=n;
    for(i=1;i<=n;i++){
        fin>>v[i];
    }
    for(i=1;i<=n;i++){
        fin>>x;
        if(i%2!=0){
            if(x==1){
                s1+=v[primu];
                primu++;
            }
            else{
                s1+=v[ultimu];
                ultimu--;
            }
        }
        else{
            if(x==1){
                s2+=v[primu];
                primu++;
            }
            else{
                s2+=v[ultimu];
                ultimu--;
            }
        }
    }
    if(s1>s2){
        fout<<s1<<" "<<"1";
    }
    else if(s1==s2){
        fout<<s1<<" "<<"0";
    }
    else{
        fout<<s2<<" "<<"2";
    }


}
