//Lucian Silaghi 100 puncte
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

typedef
struct
 {
    int nr;             // nr de concurs
    int l;              // lungimea zonei
    int p;              // poz in clasament
    int depasiti[501];  //indice 0 retine nr de elemente
 } concurent;


int main()
{
    int n,i,j,k,ok,id[501],aux;  //id[i] = indicele din vector al masinii de pe locul i
    concurent v[501];
    ifstream inFile;
    ofstream outFile;
    // citire date din concurs in
    inFile.open("cursa.in");
    if (!inFile)
       cout << "Nu se poate deschide fisierul";
    inFile >> n;
    j=0;
    for (i=1;i<=n;i++)
         {
             inFile >> v[i].nr >> k;
             v[i].l=k-j;
             j=k;   // sfarsitul loc devine inceput pt. urmatoarea
             id[i]=i;
         }
    inFile.close();
    // creere vector index (id) prin sort cu bule
    k=1;
    do
     {
        ok=1;
        for (i=1; i<=n-k;i++)
          {
             if ((v[id[i]].l < v[id[i+1]].l) || ((v[id[i]].l == v[id[i+1]].l) && (v[id[i]].nr > v[id[i+1]].nr) ))
               {
                 aux=id[i]; id[i]=id[i+1]; id[i+1]=aux;
                 ok=0;
               }
          }
        k++;
      }
    while (!ok);
    // adaug pozitiile id[i] in v[i].p

    for (i=1;i<=n;i++)
       v[id[i]].p=i;
    //for (i=1;i<=n;i++)
    //   cout << i<<"-"<<v[i].p << endl;


    // depasiri
    for (i=2; i<=n;i++)
       {
           // adaug masinile depasite in vectorul de depasiri incepand cu ultima clasata
           aux=0;
           for (j=n; j>v[i].p;j--)

              // daca lung localit masinii i > a celor clasate dupa si cea clasata dupa are loc mai inainte de cea a lui i
              if ((v[i].l > v[id[j]].l) && (id[j]<i))
                 {
                     aux++;
                     v[i].depasiti[aux]=v[id[j]].nr;
                 }
          v[i].depasiti[0]=aux;
       }

    //scriere rezultate in concurs.out
    outFile.open("cursa.out");
    for (i=1;i<n;i++)
       outFile << v[id[i]].nr << " ";
    outFile << v[id[n]].nr << "\n";
    // pe prima zona nu exista depasire
    for (i=2;i<=n;i++)
       {
           if (v[i].depasiti[0]) // se scrie numai daca exista depasiri in aceasta zona
             {
               outFile << i << " " << v[i].nr <<" " << v[i].depasiti[0];
               for (j=1; j<=v[i].depasiti[0];j++)
                  outFile << " " << v[i].depasiti[j];
               outFile << "\n";
             }
       }
    outFile.close();
    return 0;
}
