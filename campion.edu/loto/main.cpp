#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("text.txt");
ofstream fout("loto.out");

int n,maxy=-9999,mic1,mic2;
int v[1005];
int f[9999];
int loto[6];

int main()
{
    int i,x;

    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        v[i]=x;
        f[x]++;
        maxy=max(maxy,x);
    }
    for(i=1; i<=6; i++)
    {

        fin>>loto[i];
        f[loto[i]]--;

    }
    sort(loto+1,loto+6+1);
    int celMic,celMare;
    for(i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //cel mic;
    celMic=loto[1];
    celMare=loto[1];
    mic1=9999999;
    mic2=9999999;
    //step1
    while(f[celMic]==0 && celMic>0)
    {
        celMic--;
    }
    while(f[celMare]==0  && celMare<=maxy)
    {
        celMare++;
    }
    //step2
    if(celMic!=0)
    {
        mic1=loto[1]-celMic;
    }
    if(celMare!=maxy+1)
    {
        mic2=celMare-loto[1];
    }
    //step3
    if(mic1<mic2)
    {
        loto[1]=celMic;
    }
    else if(mic1==mic2)
    {
        loto[1]=celMare;
    }
    else
    {
        loto[1]=celMare;
    }





    /////////////////////////////
    celMic=loto[6];
    celMare=loto[6];
    mic1=9999999;
    mic2=9999999;
    //step1
    while(f[celMic]==0 && celMic>0)
    {
        celMic--;
    }
    while(f[celMare]==0 && celMare<=maxy)
    {
        celMare++;
    }
    //step2
    if(celMic!=0)
    {
        mic1=loto[6]-celMic;
    }
    if(celMare!=maxy+1)
    {
        mic2=celMare-loto[6];
    }
    cout<<mic1<<" "<<mic2<<endl;
    //step3
    if(mic1<mic2)
    {
        loto[6]=celMic;
    }
    else if(mic1==mic2)
    {
        loto[6]=celMare;
    }
    else
    {
        loto[6]=celMare;
    }


    sort(loto+1,loto+6+1);
    for(i=1; i<=6; i++)
    {
        cout<<loto[i]<<" ";
    }


}
