#include <iostream>
#include <fstream>

using namespace std;

int a[1100][1100], n;

void solve (int x1, int y1, int x2, int y2, int px, int py, int &nr) {
    int midx = (x1 + x2 - 1) / 2;
    int midy = (y1 + y2 - 1) / 2;

    if (x1 == x2) return;

    ++nr;


    //stanga sus
    if (px <= midx && py <= midy) {
        a[midx][midy + 1] = nr;
        a[midx + 1][midy] = nr;
        a[midx + 1][midy + 1] = nr;

        solve (x1, y1, midx, midy, px, py, nr);
        solve (x1, midy + 1, midx, y2, midx, midy + 1, nr);
        solve (midx + 1, y1, x2, midy, midx + 1, midy, nr);
        solve (midx + 1, midy + 1, x2, y2, midx + 1, midy + 1, nr);

    }

    //dreapta sus
    if (px <= midx && py > midy) {
        a[midx][midy] = nr;
        a[midx + 1][midy] = nr;
        a[midx + 1][midy + 1] = nr;

        solve (x1, y1, midx, midy, midx, midy, nr);
        solve (x1, midy + 1, midx, y2, px, py, nr);
        solve (midx + 1, y1, x2, midy, midx + 1, midy, nr);
        solve (midx + 1, midy + 1, x2, y2, midx + 1, midy + 1, nr);

    }

    //stanga jos
    if (px > midx && py <= midy) {
        a[midx][midy] = nr;
        a[midx][midy + 1] = nr;
        a[midx + 1][midy + 1] = nr;

        solve (x1, y1, midx, midy, midx, midy, nr);
        solve (x1, midy + 1, midx, y2, midx, midy + 1, nr);
        solve (midx + 1, y1, x2, midy, px, py, nr);
        solve (midx + 1, midy + 1, x2, y2, midx + 1, midy + 1, nr);

    }

    if (px > midx && py > midy) {
        a[midx][midy] = nr;
        a[midx][midy + 1] = nr;
        a[midx + 1][midy] = nr;

        solve (x1, y1, midx, midy, midx, midy, nr);
        solve (x1, midy + 1, midx, y2, midx, midy + 1, nr);
        solve (midx + 1, y1, x2, midy, midx + 1, midy, nr);
        solve (midx + 1, midy + 1, x2, y2, px, py, nr);

    }


}

int main(){

   cin>>n;
   a[1][1]=0;
   n=1<<n;

   int nr = 0;

   solve(1, 1, n, n, 1, 1, nr);

   //afisare
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
    cout<<"\n";
   }
   return 0;

}
