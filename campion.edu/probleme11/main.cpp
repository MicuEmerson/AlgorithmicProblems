#include <iostream>
#include <algorithm>
using namespace std;
/*
utf-8 ... 1-4 bytes ,

    01xxxxxx - continuare
    76543210
    10xxxxxx - 1 bytes
    110xxxxx - 2
    1110xxxx - 3
    11110xxx - 4

    10xxxxxx 11110xxx 01xxxxxx  01xxxxxx 10xxxxxx 10xxxxxx
    v[1]     v[2]     v[3]                                v[7]


    operatori pe biti
    a ^ b
    a=1010
      b=0111
        a&b  =1101
              z
              shifare .. a << 2,
              a = 10101 a >> 2 = 00101
                                 << 2

                                 a      - 1110
                                 1 << 2 - 0100
                                 a & (1 << bitul de test)  == 0 sau > 0
                                 */
bool isContinuare(char c)
{
    if(c&(1 << 7)== 0 && c&(1 << 6)==1)
    {
        return true;
    }
    return false;
}

int ceTipDeByte(char c)
{

    if(c&(1 << 7)== 1 && c&(1 << 6)==0)
    {
        return 0;
    }
    else if(c&(1 << 7)== 1 && c&(1 << 6)==1 && c&(1 << 5)==0)
    {
        return 1;
    }
    else if(c&(1 << 7)== 1 && c&(1 << 6)==1 && c&(1 << 5)==1 && c&(1 << 4)==0)
    {
        return 2;
    }
    else if(c&(1 << 7)== 1 && c&(1 << 6)==1 && c&(1 << 5)==1 && c&(1 << 4)==1 && c&(1 << 3)==0)
    {
        return 3;
    }
    return -1;

}


bool functie(vector<char> v)
{

    for(int i=0; i<=v.size(); i++)
    {

        int ceTip=ceTipDeByte(v[i]);
        if(ceTip>=0)
        {
            while(ceTip--)
            {
                i++;
                if(!isContinuare(v[i]))
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;


}


int main()
{

}
