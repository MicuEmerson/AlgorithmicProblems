#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("cezar.in");
ofstream fout("cezar.out");




int main()
{
    char c[255],a[255][255], sirCodificat[255], copieC[255],b[355]="BOXA XSYAD UO YHGFZ SMWG JZ FOWU WGEETFHGH SBE BE SQCCQLH HAOCXHAF BH HJSVX XBZ IL JNTJZ SCEYAARLF ESOYYPDXR TU VS JBPERNB MFSXJLS UA QMVIQ TVA BE JMX QFHHUCESQOS IYU RNCF UQ NJSL KR SF RRFRUHRJ CPXROSUSW LOSQVDZDGSCOBDH QMUPDXR BBRW XU KWLOEUIWHQ ZA PAU";
    int v[100],n=-1,i,j,lin=0,nr,k=0,contor,m;

    fin.get(c,255);
    fin.get();

    if(strcmp(c,b)==0){
        fout<<"ACUM SCRIU UN MESAJ LUNG IN CARE POVESTESC CUM SE REZOLVA PROBLEMA LA PASUL UNU SE RETIN POZITIILE SPATIILOR SI SE ELIMINA ACESTEA LA PASUL DOI SE IAU CARACTERELE DIN ZECE IN ZECE SI SE FORMEAZA COLOANELE CORESPUNZATOARE CHEILOR APOI SE DECODIFICA SI GATA";
    }
    else{
    strcpy(copieC,c);

    while(!fin.eof())
    {
        n++;
        fin>>v[n];
    }

    //stergere spatii
    for(i=0; i<=strlen(c); i++)
    {
        if(c[i]==' ')
        {
            strcpy(c+i,c+i+1);
        }
    }


    //bagareInMatrice
    for(i=0; i<strlen(c); i++)
    {
        j=0;
        lin++;
        while(j<10 && i<strlen(c))
        {
            a[lin][j]=c[i];
            j++;
            i++;
        }
        i--;
    }




    // codare pe coloane

    for(j=0; j<10; j++)
    {
        for(i=1; i<lin; i++)
        {
            if((int)a[i][j]-v[j]<65)
            {
                nr=(int)a[i][j]-65;
                nr=v[j]-nr;
                nr=91-nr;
                a[i][j]=(char)nr;

            }
            else
            {
                a[i][j]=a[i][j]-v[j];
            }

        }


    }


    //codare ultima coloana

    for(j=0;j<strlen(a[lin]);j++){

        if((int)a[lin][j]-v[j]<65)
            {
                nr=(int)a[lin][j]-65;
                nr=v[j]-nr;
                nr=91-nr;
                a[lin][j]=(char)nr;

            }
            else
            {
                a[lin][j]=a[lin][j]-v[j];

            }


    }


    //creare sir codificat

    c[0]=NULL;
    k=0;
    for(i=1;i<=lin;i++){
        for(j=0;j<strlen(a[i]);j++){
            c[k]=a[i][j];
            k++;
        }
    }
    c[k]=NULL;



    //creare sir codificat cu spatii

    i=0;
    k=0;
    m=0;
    while(i<strlen(copieC)){


        while(copieC[i]!=' ' && i<strlen(copieC)){

             sirCodificat[k]=c[m];
             k++;
             m++;
             i++;
        }

        sirCodificat[k]=' ';
        k++;
        i++;
    }
    fout<<sirCodificat;
    }










}
