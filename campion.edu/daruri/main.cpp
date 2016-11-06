#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("daruri.in");
ofstream fout("daruri.out");

int cmmdc(int a, int b){

 while(a!=b){
    if(a>b){
        a=a-b;
    }
    else{
        b=b-a;
    }
 }
 return a;

}



int main()
{
    int t,l;
    fin>>t>>l;
    if(cmmdc(t,l)==1){
        fout<<"0"<<endl;
        fout<<"0"<<" "<<"0";
    }
    else{
        fout<<cmmdc(t,l)<<endl;
        fout<<t/cmmdc(t,l)<<" "<<l/cmmdc(t,l);
    }
}
