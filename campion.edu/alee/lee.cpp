#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("text.txt");
ofstream fout("alee.out");

int n,m,li,ci,lf,cf;
int a[200][200];

void citiri()
{

    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        a[x][y]=-1;
    }
    fin>>li>>ci>>lf>>cf;

}

void afisare(){

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;


}

bool isOk(int i, int j)
{
    if(a[i][j]==-1) return false;

    if(i>=1 && j>=1 && i<=n && j<=n) return true;

    return false;
}

void lee()
{

    int i,j;
    int dl[4]= {0,-1,0,1};
    int dc[4]= {1,0,-1,0};

    queue < pair < int , int > > coada;
    a[li][ci]=1;
    coada.push(make_pair(li,ci));

    while(!coada.empty())
    {

        i=coada.front().first;
        j=coada.front().second;
        coada.pop();

        for(int d=0; d<=3; d++)
        {

            int i_next=i+dl[d];
            int j_next=j+dc[d];

            if(isOk(i_next,j_next) && a[i_next][j_next] == 0)
            {
                a[i_next][j_next]=a[i][j]+1;
                coada.push(make_pair(i_next,j_next));
                afisare();
            }
        }
    }
}



int main()
{
    citiri();
    lee();
    fout<<a[lf][cf];





}



