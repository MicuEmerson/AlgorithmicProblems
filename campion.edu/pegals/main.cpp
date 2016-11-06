#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pegals.in");
ofstream fout("pegals.out");
int n;
int main()
{
    fin>>n;
    fout<<"3"<<endl;
    if(n%2==0){
        fout<<n<<" "<<(n-1)/2<<" 1";
    }
    else{
        fout<<n-1<<" "<<(n-1)/2<<" 1";
    }
}
