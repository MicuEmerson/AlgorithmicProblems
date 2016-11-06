#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int T,S,q,song=1;
    int play=0;
    cin>>T>>S>>q;

    while(S<T)
    {

        S=S+q-1;
        play+=q;
        if(play>S)
        {
            song++;
        }

    }

    cout<<song;



}
