#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("tablita.in");
ofstream fout("tablita.out");

void generare(long numar){


  long primulElemDinGrupa=1, grupa=1;
  int gasit=0;
  while(gasit==0){

      if(primulElemDinGrupa<=numar && grupa-1+primulElemDinGrupa>=numar){
         fout<<grupa;
         gasit=1;

      }
      else{
        primulElemDinGrupa=grupa+primulElemDinGrupa;
        grupa++;
      }

  }

}


int main()
{
    long numar;
    fin>>numar;
    generare(numar);
}
