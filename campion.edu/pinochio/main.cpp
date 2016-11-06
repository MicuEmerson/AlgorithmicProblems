#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("pinochio.in");
ofstream fout("pinochio.out");


int main()
{

    int cm,zile,p;
    int sapt,zileRamase;
    fin>>cm>>p>>zile;
    sapt=zile/7;

    zileRamase=zile%7;

    cm=cm+ (5*sapt*p);
    cm=cm- (2*sapt);

    if(zileRamase<=5){
        cm=cm+ (zileRamase*p);
    }
    else{
        zileRamase=zileRamase-5;
        cm=cm+ (5*p);
        cm=cm- zileRamase;
    }
    fout<<cm;


}
