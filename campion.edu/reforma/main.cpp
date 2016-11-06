#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("text.txt");
ofstream fout("text1.txt");

int main()
{
    int n,cn,s=0;
    cin>>n;
    cn=n;
    s+=1;
    s+=cn/5;
    cn=n;
    s+=cn/10;
    cn=n;
    while(cn>=10){
        cn-=10;
        s+=cn/5;
    }
    cout<<s;

}


//in cate moduri putem partitiona 10000
//in cate moduri putem partitiona 5000
//in cate moduri putem partiona 1 -> 1

// in cate moduri poti partiona x, v[x] este numarul de moduri in care poti partiona x - 1 + x - 5 + x - 10 + x - 20
// v[x] = v[x - 1] + v[x - 5] + v[x - 10] + v[x - 20]

s=1;
1;
s=2;
1;
s=5;
2;
s=10;
4;

v[x][nr1][nr2][nr3][nr4] - este numarul de moduri in care poti partiona x folosind nr1 monezi de 1 etc

v[x][nr2][nr3][nr4][nr4] - v[x - 1][nr1-1][nr2][nr3][nr4] + v[x - 5][nr1][nr2 - 1]...

v[35] = v[34] + v[15]

v[5] = 2
5 - 1 5
2 5
10 1

//v[x] = v[x - 5] + v[x]
v[x] = v[x - 10] + v[x];

//1 1 1 1 10 20 1
// 1 1 1 1 10 1 20







