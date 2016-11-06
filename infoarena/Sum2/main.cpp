#include <iostream>
#include <algorithm>
#include <deque>
#include <fstream>
using namespace std;
ifstream fin("sum2.in");
ofstream fout("sum2.out");

const int MAXN=100005;
int n,L,U,v[MAXN],s[MAXN],maxy=-((1<<31)-1),miny;
deque < int > deq;

void insert(int poz){

     while(!deq.empty() && s[deq.back()] >= s[poz]) deq.pop_back();
     deq.push_back(poz);
}

int get_min(int poz){

    while(!deq.empty() && deq.front() < poz) deq.pop_front();

    return s[deq.front()];

}


int main(){

  fin>>n>>L>>U;
  for(int i=1;i<=n;i++){
    fin>>v[i];
    s[i]=s[i-1]+v[i];
  }

  for(int i=L;i<=n;i++){

       insert(i-L); // functie care ne insereaza in deque elementul minim

       miny=get_min(i-U);

       maxy=max(s[i]-miny,maxy);

  }
  fout<<maxy;






}
