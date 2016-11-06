#include <iostream>

using namespace std;

int main()
{
    int v[1000000],i;
    int s[1000000];
    int r[1000];
    int n,m;
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    s[1]=v[1];
    r[s[1]%m]++;
    if(s[1]%m==0)
    {
        cout<<"YES";
    }
    else
    {
        for(i=2; i<=n; i++)
        {
            s[i]=v[i]+s[i-1];
            if(s[i]%m==0)
            {
                cout<<"YES";
                break;
            }
            else
            {
                if(r[s[i]%m]==1){
                    cout<<"YES";
                    break;
                }
                r[s[i]%m]++;
            }
        }
    }
    cout<<"NO";

}
