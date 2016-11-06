#include <bits/stdc++.h>

using namespace std;

string smallest(string a)
{
    int n = (int)a.length();
    string a,b;

    if(n%2==1)
    {
        return a;
    }
    else
    {
         s1 = smallest(a.substr(0, n / 2));
         s2 = smallest(a.substr(n / 2, n / 2));

        if(s1<s2)
        {
            return s1+s2;
        }
        else
        {
            return s2+s1;
        }
    }
}

int main()
{
    string a,b;
    smallest(a);
    smallest(b);
    if(a==b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}









