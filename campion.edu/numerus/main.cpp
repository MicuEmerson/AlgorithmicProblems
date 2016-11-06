#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("numerus.in");
ofstream fout("numerus.out");




int main()
{
    long k,linie;
    long long n,primuNumar,nrCrescut;
    long long v[100],b[100];
    int i=0;
    fin>>k>>n;
    primuNumar=1+(k-1)*5;
    if(k%2==0){
      primuNumar+=4;
      i++;
      v[i]=primuNumar;
      for(i=2;i<=6;i++){
        v[i]=primuNumar;
        primuNumar--;
      }
    }
    else{
        for(i=1;i<=5;i++){
            v[i]=primuNumar;
            primuNumar++;
        }
        primuNumar--;
        v[6]=primuNumar;

    }

    for(i=1;i<=6;i++){
        fout<<v[i]<<" ";
    }
    fout<<endl;



    i=1;
    nrCrescut=n;
    while(nrCrescut%5!=0){
        nrCrescut++;
    }
    linie=nrCrescut/5;
    fout<<linie<<endl;
    if(linie%2==0){

        b[i]=nrCrescut;
        for(i=2;i<=6;i++){
            b[i]=nrCrescut;
            nrCrescut--;
        }
    }
    else{
        nrCrescut-=4;
        for(i=1;i<=5;i++){
            b[i]=nrCrescut;
            nrCrescut++;
        }
        nrCrescut--;
        b[6]=nrCrescut;
    }


    if(linie%2==0){
    for(i=1;i<=6;i++){
        if(b[i]==n && i==1){
            fout<<"A"<<" "<<"B";
        }
        if(b[i]==n && i==3){
            fout<<"C";
        }
        if(b[i]==n && i==4){
            fout<<"D";
        }
        if(b[i]==n && i==5){
            fout<<"E";
        }
        if(b[i]==n && i==6){
            fout<<"F";
        }
    }
    }
    else{

        for(i=1;i<=6;i++){
        if(b[i]==n && i==1){
            fout<<"A";
        }
        if(b[i]==n && i==2){
            fout<<"B";
        }
        if(b[i]==n && i==3){
            fout<<"C";
        }
        if(b[i]==n && i==4){
            fout<<"D";
        }
        if(b[i]==n && i==5){
            fout<<"E"<<" "<<"F";
        }
    }

    }




}






