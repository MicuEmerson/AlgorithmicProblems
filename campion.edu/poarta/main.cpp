#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int n,m,k,x,y,rez;
int startX,startY,stopX,stopY;
int nrFaraStelare;
int pStart=999999,pStop=999999,distPorti,distMin;
pair <int, int> p[105];


int main()
{
    int i;

    fin>>n>>m>>k;
    fin>>startX>>startY>>stopX>>stopY;
    for(i=1;i<=k;i++){
        fin>>p[i].first;
        fin>>p[i].second;
    }

    //cea mai apropiata poarta de start;

     for(i=1;i<=k;i++){
        rez=abs(startX-p[i].first)+abs(startY-p[i].second);
        pStart=min(pStart,rez);
     }
     //cea mai apropiata poaarta de stop

      for(i=1;i<=k;i++){
        rez=abs(stopX-p[i].first)+abs(stopY-p[i].second);
        pStop=min(pStop,rez);
     }

     // distanta poartaStart la poarta stop

     distPorti=abs(startX-stopX)+abs(startY-stopY);

     // distanta minina;
     distMin=min(distPorti,pStart+pStop+1);


     //nrModuri fara porti stelare
      x=abs(startX-stopX)+1;
      y=abs(startY-stopY)+1;
      cout<<x<<" "<<y<<endl;





}
