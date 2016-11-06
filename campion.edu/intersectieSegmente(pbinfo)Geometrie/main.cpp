#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
ifstream fin("distantapunctdreapta.in");
ofstream fout("distantapunctdreapta.out");


int main()
{
   int p1,p2;
   int x1,y1,x2,y2;
   float a,b,c;
   float d;
   fin>>p1>>p2>>x1>>y1>>x2>>y2;
   a=y2-y1;
   b=x2-x1;
   c=x1*y2-x2*y1;

   d=(float)(abs(a*p1+b*p2+c))  /  (float)sqrt( pow(a,2.0) + pow(b,2.0) );

   fout<<fixed<<setprecision(2)<<d;





}
