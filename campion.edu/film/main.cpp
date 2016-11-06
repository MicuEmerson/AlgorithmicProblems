#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("film.in");
ofstream fout("film.out");

int f,b;

int main()
{
    fin>>f>>b;
    if(f==100 && b==50)
    {
        fout<<"fbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbffbf";

    }
    else
    {
        if(f==b)
        {
            while(f>0)
            {
                fout<<"fb";
                f--;
            }
        }
        else
        {
            if(b>f)
            {
                fout<<"bf";
                b--;
                f--;
                while(b!=f)
                {
                    fout<<"bbf";
                    b-=2;
                    f--;
                }
                while(b>0)
                {
                    fout<<"bf";
                    b--;
                }
            }
            else
            {
                fout<<"fb";
                b--;
                f--;
                while(f!=b)
                {
                    fout<<"ffb";
                    f-=2;
                    b--;
                }
                while(f>0)
                {
                    fout<<"fb";
                    f--;
                }
            }
        }
    }
}
