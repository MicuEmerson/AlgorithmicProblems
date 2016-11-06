#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("text.txt");
ofstream fout("zuma.out");


int main()
{
    char c[255],aux,c1[255],c2[255];
    int i,st,dr,j,x,y,gata=0;
    fin>>i;
    i--;
    fin>>c;

    while(c[i]==c[i-1] && c[i]==c[i+1] && gata==0)
    {

        aux=c[i];

        st=i;
        while(aux==c[st])
        {
            st--;
        }

        dr=i;
        while(aux==c[dr])
        {
            dr++;
        }

        //prima parte
        c1[0]=NULL;
        for(j=0; j<=st; j++)
        {
            c1[j]=c[j];
        }
        c1[++st]=NULL;

        //a doua parte
        c2[0]=NULL;
        strcpy(c2,c+dr);
        cout<<c1<<endl;
        cout<<c2<<endl;




        c[0]=NULL;
        if(c1[strlen(c1)-1]==c1[strlen(c1)-2] && c1[strlen(c1)-1]==c2[0])
        {
            strcat(c,c1);
            strcat(c,c2);
            cout<<"IF 1:  "<<c<<endl;
            i=strlen(c1)-1;
        }
        else if(c2[0]==c2[1] && c2[0]==c1[strlen(c1)-1])
        {
            strcat(c,c1);
            strcat(c,c2);
            i=strlen(c1)+1;
            cout<<"IF 2:  "<<c<<endl;

        }
        else
        {
            strcat(c1,c2);
            cout<<"IF 3: "<<c1<<endl;
            gata=1;
        }
    }
    if(gata==0){
        cout<<c;
    }
}
