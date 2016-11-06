#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("text.txt");
ofstream fout("adiacenta.out");

int n,i,nr;
pair <int, int> v[105];
vector <int> graf[105];
vector <int> :: iterator it;

void sortare()
{
    for(int i=1; i<nr; i++)
    {
        for(int j=i+1; j<=nr; j++)
        {
            if(v[i].first>v[j].first)
            {
                swap(v[i],v[j]);
            }
            else if(v[i].first==v[j].first)
            {
                if(v[i].second>v[j].second)
                {
                    swap(v[i],v[j]);
                }
            }
        }
    }
}

void afisare(){
 for(int i=1;i<=nr;i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
 }
 cout<<endl;
}

void inserareInVector(){

  for(int i=1;i<=nr;i++){
      graf[v[i].first].push_back(v[i].second);
      graf[v[i].second].push_back(v[i].first);
  }

}

void afisareGrafPerechi(){

  for(int i=1;i<=n;i++){
        cout<<graf[i].size()<<" ";
    for(it=graf[i].begin();it!=graf[i].end();i++){
          cout<<"A ";
    }
    cout<<endl;
  }



}

int main()
{
    fin>>n;
    while(!fin.eof())
    {
        int x,y;
        i++;
        fin>>x>>y;
        v[i].first=x;
        v[i].second=y;

    }

    nr=--i;
    afisare();
    sortare();
    afisare();
    inserareInVector();
    afisareGrafPerechi();
}
