#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("imagine.in");
ofstream fout("imagine.out");
const int MAXN=255;
int l;
int a[MAXN][MAXN];
int sume[MAXN][MAXN];

void sumePartiale(){
  for(int i=1;i<=l;i++){
    for(int j=1;j<=l;j++)
        sume[i][j]=sume[i-1][j] + sume[i][j-1] - sume[i-1][j-1]+ a[i][j];
  }
}

int sumaDreptunghi(int x1,int y1, int x2, int y2){
   return sume[x2][y2]-sume[x1-1][y2]-sume[x2][y1-1]+sume[x1-1][y1-1];
}

int solve (int x1, int y1, int x2, int y2) {
    int sum = sumaDreptunghi(x1,y1,x2,y2);
    int l = x2 - x1 + 1;
    int L = y2 - y1 + 1;

    if (l * L == sum || sum == 0) {
        return 2;
    }

    int rez = 0, xm = x1 + l / 2 - 1, ym= y1 + L / 2 - 1;
    if (l % 2 != 0) ++xm;
    if (L%2 != 0) ++ym;
    rez += solve(x1, y1, xm, ym); //am adaugat la rezultat compresia primei matrici
    rez += solve(x1, ym + 1, xm, y2);
    rez += solve(xm + 1, y1, x2, ym);
    rez += solve(xm + 1, ym + 1, x2, y2);

    return rez + 1;
}



int main()
{
    fin>>l;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            fin>>a[i][j];
        }
    }
    sumePartiale();

    fout <<solve(1, 1, l, l);
}
