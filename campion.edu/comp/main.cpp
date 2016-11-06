#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("comp.in");
ofstream fout("comp.out");


int main(){

 int n,i,j,semne=0,nr,poz,k;
 int v[1005],dimV=0;
 string c;
 string a1,a2;

 fin>>n;

 for(i=1;i<=n;i++){
    c.clear();
    fin>>c;
    fin.get();

    for(j=0;j<c.length();j++){
        if(c[j]=='<' || c[j]=='>'){
            poz=j;
            break;
        }
    }
    if(c[poz]=='<'){
        semne++;
    }

    //creare siruri
    a1.clear();
    a2.clear();
    a1=c.substr(0,poz);
    a2=c.substr(poz+1);

    //primu nr
    k=0;
    int s1=0;
    while(k<a1.length()){

        if(isdigit(a1[k]) && k<a1.length()){
            nr=0;
            while(isdigit(a1[k]) && k<a1.length()){
                nr=nr*10+((int)a1[k]-48);
                k++;
            }
            if(a1[k]=='m'){
                s1+=nr*1000;
            }
            if(a1[k]=='s'){
                s1+=nr*100;
            }
            if(a1[k]=='z'){
                s1+=nr*10;
            }
            if(a1[k]=='u'){
                s1+=nr;
            }
        }
        else{
            k++;
        }
    }

    //al doilea nr
    k=0;
    int s2=0;
    while(k<a2.length()){

        if(isdigit(a2[k]) && k<a2.length()){
            nr=0;
            while(isdigit(a2[k]) && k<a2.length()){
                nr=nr*10+((int)a2[k]-48);
                k++;
            }
            if(a2[k]=='m'){
                s2+=nr*1000;
            }
            if(a2[k]=='s'){
                s2+=nr*100;
            }
            if(a2[k]=='z'){
                s2+=nr*10;
            }
            if(a2[k]=='u'){
                s2+=nr;
            }
        }
        else{
            k++;
        }
    }

    //comparare
    if(c[poz]=='>'){
        if(s1>s2){
            v[++dimV]=1;
        }
        else{
            v[++dimV]=0;
        }
    }
    else{
        if(s1<s2){
            v[++dimV]=1;
        }
        else{
            v[++dimV]=0;
        }
    }
 }
    //afisare
    fout<<semne<<endl;
    for(i=1;i<=dimV;i++){
        fout<<v[i]<<endl;
    }




}























