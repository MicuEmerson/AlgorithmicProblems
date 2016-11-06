#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("finala.in");
ofstream fout("finala.out");

int main()
{
    int profesori, elevi, locuriInAutobuz, nrBus=0;
    fin>>elevi;
    fin>>profesori;
    fin>>locuriInAutobuz;

    while(profesori>=2 && elevi>=locuriInAutobuz-2)
    {

        nrBus++;
        profesori-=2;
        elevi=elevi-(locuriInAutobuz-2);

    }
    cout<<profesori<<" "<<elevi<<" "<<nrBus<<endl;
    if(profesori==0)
    {

        if(elevi>0)
        {
            fout<<"0";
        }
        else
        {
            fout<<nrBus;
        }
    }
    else
    {

        if(profesori==1)
        {
            fout<<"0";
        }
        else
        {

            if(elevi==0)
            {
                if(locuriInAutobuz>=profesori)
                {
                    nrBus++;
                    fout<<nrBus;
                }
                else
                {
                    while(profesori>locuriInAutobuz)
                    {
                        profesori-=locuriInAutobuz;
                        nrBus++;
                    }
                    if(profesori==1 && locuriInAutobuz>2)
                    {
                        nrBus++;
                        fout<<nrBus;
                    }
                    else if( profesori==0)
                    {
                        fout<<nrBus;
                    }
                    else if( profesori >=2 && profesori <=locuriInAutobuz)
                    {
                        nrBus++;
                        fout<<nrBus;
                    }
                }
            }
            else
            {

                if(profesori+elevi<=locuriInAutobuz)
                {
                    nrBus++;
                    fout<<nrBus;
                }
                else
                {

                    while(profesori>locuriInAutobuz)
                    {

                        nrBus++;
                        profesori-=locuriInAutobuz;
                    }
                    profesori+=elevi;

                    while(profesori>locuriInAutobuz)
                    {

                        nrBus++;
                        profesori-=locuriInAutobuz;
                    }
                    if(profesori<2 && locuriInAutobuz>3)
                    {
                        nrBus++;
                        fout<<nrBus;
                    }
                    if(profesori>=2)
                    {
                        nrBus++;
                        fout<<nrBus;
                    }
                    if(profesori<2 && locuriInAutobuz<=3)
                    {
                        fout<<"0";
                    }

                }

            }

        }

    }

}



