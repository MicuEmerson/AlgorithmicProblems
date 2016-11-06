#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("ordonare.in");
ofstream fout("ordonare.out");

int pozA(char alf[255], char litera)  // functie ce ne ajuta sa vedem pe ce pozitie se afla o anumita litera in alfabetul nostru
{
    int i;
    for(i=0; i<strlen(alf); i++)
    {
        if(alf[i]==litera)
        {
            return i;       // returnam pozitia litere din alfabet cand o gasim
        }
    }
}

int isMaiMareLexicografic(char c1[255], char c2[255], char alf[255])
{
    int i=0;
    int dim;

    if(strlen(c1)>strlen(c2)){          // aici comparam care are lungimea mai mica sa o folosim aceasta lungime
        dim=strlen(c2);                 // la while-ul de mai jos sa nu cumva sa intra in ciclu infinit
    }
    else{
        dim=strlen(c1);
    }


       if(pozA(alf,c1[i])>pozA(alf,c2[i]))    // daca pozitia primei litere a primului cuvant e mai mare decat
        {                                     // pozitia cuvantului al doilea atuncii returnam 1

            return 1;

        }
        //-------------
        else if(pozA(alf,c1[i])==pozA(alf,c2[i]))    // daca ele sunt egale mergem cu while-ul pana cand nu mai sunt egale
        {

            while(pozA(alf,c1[i])==pozA(alf,c2[i]) && i<dim)
            {
                i++;
            }
            i--; // scadem i-ul pentru ca atunci ne-a iesit din while cand nu a mai satisfacut conditia am pus-o
            if(pozA(alf,c1[i])>pozA(alf,c2[i]))   // si le comparam aici si returnam 1 daca pozitia literea cuvantului 1
            {                                     // este mai mare decat pozitia literei cuvantului poi
                return 1;
            }
            else
            {
                return 0;
            }
        }
        //--------------
        else                 // daca nu intra in nici una dintre conditiile de mai sus inseamna ca e mai cuv1<cuv2
        {
            return 0;
        }
}

void sortare(char a[1000][255], int linie, char alf[255]){   // functie simpla de sortare doar adaptata tipului char

  int i,j;
  char aux[255];
  for(i=1;i<linie;i++){
    for(j=i+1;j<=linie;j++){
        if(isMaiMareLexicografic(a[i],a[j],alf)==1){      // apelam functia noastra creata mai sus
            strcpy(aux,a[i]);
            strcpy(a[i],a[j]);                            // am folosit strcpy pentru ca nu putem cu "=" , sir1=sir2 e gresit scris,
            strcpy(a[j],aux);                             // in schimb litera1=litera2 e corect
        }
    }
  }
}




void creareCuvinte(char alf[255])
{

    char a[1000][255];
    char c[2000];
    fin.get(c,2000);
    int i,j,k,linie=0,coloana;
    for(i=0; i<strlen(c); i++)
    {

        if(isalpha(c[i]))
        {
            j=i;
            while(isalpha(c[j]) && j<strlen(c))
            {
                j++;
            }

            j--;

            linie++;
            coloana=0;
            for(k=i; k<=j; k++)
            {
                a[linie][coloana]=c[k];
                coloana++;

            }
            i=j+1;
        }
    }

    sortare(a,linie,alf);   // sortam si scriem in fisier
    for(i=1;i<=linie;i++){
        fout<<a[i]<<" ";
    }

}




int main()
{
    char alf[255];
    fin>>alf;
    fin.get();
    creareCuvinte(alf);
}
