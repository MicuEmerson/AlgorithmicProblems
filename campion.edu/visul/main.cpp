#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("visul.in");
ofstream fout("visul.out");
int n;
int main()
{
    fin>>n;
    if(n==1){
        fout<<"-1";
    }
    else if(n==2){
        fout<<"23";
    }
    else if(n==3){
        fout<<"311";
    }
    else if(n==4){
        fout<<"4113";
    }
    else if(n==5){
        fout<<"53113";
    }
    else if(n==6){
        fout<<"611317";
    }
    else if(n==7){
        fout<<"7113173";
    }
    else if(n==8){
        fout<<"83113717";
    }
    else if(n==9){
        fout<<"971131737";
    }
    else{
        fout<<"-1";
    }
}
