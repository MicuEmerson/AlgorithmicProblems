#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

char a[3][3];
void resetTablet();
void printTablet();
void pick(char c);
int check();
void easySpot();
int currentMatch();
void gameRun();
void startGame();

struct spotMove
{
    spotMove() {};
    spotMove(int Score) : score(Score) {}
    int x, y, score;
};

spotMove miniMax(char player)
{
    int res = check();
    if(res == 1)
        return spotMove(-10);
    else if(res == 2)
        return spotMove(10);
    else if(res == 3)
        return spotMove(0);

    vector <spotMove> v;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(a[i][j] == '_')
            {
                a[i][j] = player;

                spotMove k;
                k.x = i;
                k.y = j;
                if(player == 'O')
                    k.score = miniMax('X').score;
                else
                    k.score = miniMax('O').score;

                v.push_back(k);
                a[i][j] = '_';
            }

    int indexMove;
    if(player == 'O')
    {
        int maxy = -INT_MAX;
        for(int i=0; i<v.size(); i++)
            if(maxy < v[i].score)
            {
                maxy = v[i].score;
                indexMove = i;
            }
    }
    else
    {
        int miny = INT_MAX;
        for(int i=0; i<v.size(); i++)
            if(miny > v[i].score)
            {
                miny = v[i].score;
                indexMove = i;
            }
    }
    return v[indexMove];
}


void hardSpot(char player)
{
    spotMove k = miniMax(player);
    a[k.x][k.y] = player;
}


int main()
{
    startGame();
    return 0;
}


void resetTablet()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            a[i][j] = '_';
}

void printTablet()
{
    for(int i=0; i<3; i++)
    {
        cout<<"| ";
        for(int j=0; j<3; j++)
            cout<<a[i][j]<<' ';
        cout<<"|\n";
    }
}

void pick(char c)
{
    int x,y;
    cin>>x>>y;
    while(a[x][y] != '_' || x<0 || x>2 || y<0 || y>2)
    {
        cout<<"Please select an empty & range spot!\n";
        cin>>x>>y;
    }
    a[x][y] = c;
}

int check()
{
    string diag1, diag2, check_X = "XXX", check_O = "OOO";
    int full = 1;
    for(int i=0; i<3; i++)
    {
        string line, column;

        for(int j=0; j<3; j++)
        {
            if(a[i][j] == '_')
                full = 0;

            line += a[i][j];
            column += a[j][i];
            if(i == j)
                diag1 += a[i][j];
            if(i + j == 2)
                diag2 += a[i][j];
        }

        if(line == check_X || column == check_X)
            return 1;
        else if(line == check_O || column == check_O)
            return 2;
    }

    if(diag1 == check_X || diag2 == check_X)
        return 1;
    else if(diag1 == check_O || diag2 == check_O)
        return 2;
    else if(full)
        return 3;
    else
        return 0;
}

void easySpot()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(a[i][j] == '_')
            {
                a[i][j] = 'O';
                return ;
            }
}



int currentMatch(string name1, string name2, int difficulty, int gameMode)
{
    int status = 0, who = 1;
    while(!status)
    {
        printTablet();
        if(gameMode == 1)
        {
            cout<<name1<<", select one spot (X): \n";
            pick('X');
            status = check();
            if(status)
                continue;
            (difficulty == 1 ? easySpot() : hardSpot('O'));
            status = check();
        }
        else
        {
            if(who > 0)
                cout<<name1<<", select one spot (X): \n";
            else
                cout<<name2<<", select one spot (O): \n";
            pick((who > 0 ? 'X' : 'O'));
            status = check();
            who *= -1;
        }
    }

    return status;
}

void gameRun(string name1, string name2, int gameMode, int difficulty)
{
    int p1 = 0, p2 = 0, draw = 0, status, go = 1;
    while(go == 1)
    {
        resetTablet();
        status = currentMatch(name1, name2, difficulty, gameMode);
        if(status == 1)
        {
            cout<<name1<<" is the WINNER!!!\n";
            p1++;
        }
        else if(status == 2)
        {
            cout<<name2<<" is the WINNER!!!\n";
            p2++;
        }
        else if(status == 3)
        {
            cout<<"Draw match!\n";
            draw++;
        }
        printTablet();

        cout<<name1<<": "<<p1<<" "<<name2<<": "<<p2<<" Draw: "<<draw<<"\n";
        cout<<"Do you wanna play again?\n";
        cout<<"1) REPLAY \n2) EXIT\n";
        cin>>go;
    }
}

void startGame()
{
    int gameMode, difficulty = 0;
    string name1, name2;

    cout<<"Select your game mode: \n";
    cout<<"1) Single Player\n";
    cout<<"2) Multiplayer\n";
    cin>>gameMode;
    cout<<"Please insert your name: \n";
    cin>>name1;

    if(gameMode == 1)
    {
        cout<<"Select your difficulty: \n";
        cout<<"1) EASY\n";
        cout<<"2) HARD\n";
        cin>>difficulty;
        gameRun(name1, "Computer", gameMode, difficulty);
    }
    else
    {
        cout<<"Please insert second player name: \n";
        cin>>name2;
        gameRun(name1, name2, gameMode, 0);
    }
}
