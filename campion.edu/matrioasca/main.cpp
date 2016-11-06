#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

// 2 4 7 9 9 9 9 10 11 12
//lower_bound(9) ii primul 9
//upper_bound

int n,dim,x;
vector v[2550];

int BS(int nr){

 int st=1,dr=dim;
 while(st<dr){

    int m=(st+dr)/2;

    if(x[m]>nr)
        dr=m-1;
    else
        st=m+1;
 }
 return st;

}


// 2 4 7 9 9 9 9 10 11 12

int BS2(int nr){ // upper_bound  ex: nr=9 returneaza pozitia lui 10;
    int st=1, dr=dim;
    while (st<dr) {
        int m = (st + dr) / 2;
        if (x[m] <= nr)
            st = m + 1;
        else
            dr = m - 1;
    }
    return st;
}

int BS3(int nr){ // upper_bound  ex: nr=9 returneaza ultima pozitie a lui 9;
    int st=1, dr=dim;
    while (st<dr) {
        int m = (st + dr) / 2;
        if (x[m] <= nr)
            st = m + 1;
        else
            dr = m - 1;
    }
    return st-1;
}

int BS4(int nr){ // lower_bound care returneaza cel mai mare element mai mic decat nr;
    int st=1, dr=dim;
    while (st<dr) {
        int m = (st + dr) / 2;
        if (x[m] >= nr)
            dr = m - 1 ;
        else
            st = m + 1;
    }

    return st;
}

int BS5(int nr){ // lower_bound returneaza prima pozitie a elementului cautat ( st+1 );
    int st=1, dr=dim;
    while (st<dr) {
        int m = (st + dr) / 2;
        if (x[m] >= nr)
            dr = m - 1 ;
        else
            st = m + 1;
    }
    return st+1;
}

int BS6(int nr){ // ca si bs5
    int st=1, dr=dim, last = -1;
    while (st<dr) {
        int m = (st + dr) / 2;
        if (x[m] >= nr) {
            dr = m - 1;
            last = m;
        }
        else
            st = m + 1;
    }
    return last;
}



int main()
{
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>x;
    }
}
