#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("text.txt");
ofstream fout("cladiri1.out");

int main()
{

    int nA,nB,k,m,i,j;
    long long vA[100005], vB[100005], nrMaxA,nrMinB;
    cin>>nA>>nB>>k>>m;

      for(i=1; i<=nA; i++)
        {
            cin>>vA[i];
        }
        for(i=1; i<=nB; i++)
        {
            cin>>vB[i];
        }


    if(k>m)
    {

        nrMinB=vB[1];

        //construire A
        while(vA[nA]>=nrMinB)
        {
            nA--;
        }

        //construire B
        nrMaxA=vA[nA];
        j=1;
        while(vB[j]<=nrMaxA)
        {
            nB--;
            j++;
        }

        if(nA>=k && nB>=m)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
    else{

          //construire B
        nrMaxA=vA[nA];
        j=1;
        while(vB[j]<=nrMaxA)
        {
            nB--;
            j++;
        }
        j--;

        nrMinB=vB[j];

        //construire A
        while(vA[nA]>=nrMinB)
        {
            nA--;
        }

        if(nA>=k && nB>=m)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }



}





