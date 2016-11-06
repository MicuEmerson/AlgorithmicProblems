#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{

    int zi;
    int luna;
    int an;
} data;

typedef struct
{

    int cod;
    string den;
    float pret;
    data exp;

} produs;

produs prod[100];
string expirate[100];
int dimString;

bool isExpirat(data exp)
{

    data azi;
    azi.an=2015;
    azi.luna=12;
    azi.zi=15;
    if(exp.an>azi.an)
    {
        return false;
    }
    else if(exp.an==azi.an)
    {
        if(exp.luna>azi.luna)
        {
            return false;
        }
        else if(exp.luna==azi.luna)
        {
            if(exp.zi>azi.zi)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

int main()
{

    int nrProd;
    cin>>nrProd;
    for(int i=1; i<=nrProd; ++i)
    {
        cin>>prod[i].cod;
        cin>>prod[i].den;
        cin>>prod[i].exp.zi;
        cin>>prod[i].exp.luna;
        cin>>prod[i].exp.an;
        cin>>prod[i].pret;
    }

    for(int i=1; i<=nrProd; ++i)
    {
        if(!isExpirat(prod[i].exp))
        {
            expirate[++dimString]=prod[i].den;
        }
    }

    sort(expirate+1,expirate+dimString+1);

    for(int i=1; i<=dimString; ++i)
    {
        cout<<expirate[i]<<"\n";
    }

}
