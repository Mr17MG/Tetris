#ifndef GAME_H
#define GAME_H
#include "ajor.h"
#include "safhebazi.h"

class Game:private ajor,safhebazi
{
public:
    Game()
    {
        ajorBaedi=0;
        ajorAsli = 0;
        tedadyekha=0;
        emtiaz=0;
        x=17;
        y=0;
    }
    void gameStart();
    void checkkardaneKhat();
    void updating();
    void jahat(char c);
    bool barkhordCharkesh();
    bool barkhordChap();
    bool barkhordRast();
    bool barkhordPaein2();
    bool barkhordPaein();

protected:

private:
    int ajorBaedi;
    int ajorAsli;
    int tedadyekha;
    int emtiaz;
    int x,y;
};


bool Game::barkhordPaein()
{
    for(int i=0; i<4; i++)
        if(screen[x+modelAjor[i][0]][y+modelAjor[i][1]+1]==1)
            return false;
    return true;
}

bool Game::barkhordPaein2()
{
    for(int i=0; i<4; i++)
        if(screen[x+modelAjor[i][0]][y+modelAjor[i][1]+2]==1)
            return false;
    return true;
}

bool Game::barkhordRast()
{
    for(int i=0; i<4; i++)
        if(screen[x+modelAjor[i][0]+1][y+modelAjor[i][1]]==1)
            return false;
    return true;
}

bool Game::barkhordChap()
{
    for(int i=0; i<4; i++)
        if(screen[x+modelAjor[i][0]-1][y+modelAjor[i][1]]==1)
            return false;
    return true;
}




bool Game::barkhordCharkesh()
{
    int z;
    int modelAjorprim[4][2];
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<2; j++)
        {
            modelAjorprim[i][j]=modelAjor[i][j];
        }
    }
    for(int i=0; i<4; i++)
    {
        z=modelAjorprim[i][1];
        modelAjorprim[i][1]=-modelAjorprim[i][0];
        modelAjorprim[i][0]=z;
    }
    for(int i=0; i<4; i++)
        if(screen[x+modelAjorprim[i][0]][y+modelAjorprim[i][1]]==true)
            return false;
    return true;
}

void Game::updating()
{
    for(int i=0; i<4; i++)
        screen[x+modelAjor[i][0]][y+modelAjor[i][1]]=1;
}

void Game::gameStart()
{
    srand(time(0));
    ajorBaedi = rand() % 7;
    for(int k=5; k<29; k++)
        screen[k][24]=1;
    for(int k=1; k<25; k++)
    {
        screen[5][k]=1;
        screen[29][k]=1;
    }
    kadrAsli();
    entekhabAjor(ajorBaedi);
    kadrBaghal();
    gotoxy(38,5);
    printf("emtiaz shoma: %d",emtiaz);
    while(true)
    {
        if(barkhordPaein())
        {
            namayeshAjor(' ',x,y);
            y++;
            namayeshAjor(219,x,y);
        }
        else
        {
            updating();
			checkkardaneKhat();
			kadrBaghal();
			gotoxy(38,5);
			printf("emtiaz shoma: %d",emtiaz);
			namayeshUpdate();
            ajorAsli = ajorBaedi;
            ajorBaedi = rand() % 7;
            y=10;
            x=42;
            entekhabAjor(ajorBaedi);
            namayeshAjor(219,x,y);
			entekhabAjor(ajorAsli);
			y = 0;
			x = 17;

        }
        if(emtiaz>50)
            Sleep(200);
        else
            Sleep(300);
        if(kbhit())
        {
            char key=getch();
            jahat(key);
        }
        for(int i=6; i<28; i++)
            if(screen[i][1]==1)
                endgame();
    }
}

void Game::checkkardaneKhat()
{
    int emtiazkomaki=1;
    for (int i=23; i>1; i--)
    {
        for (int j=6; j<29; j++)
        {
            if(screen[j][i]==true)
                tedadyekha++;
        }
        if (tedadyekha==23)
        {
            for (int n=i; n>1; n--)
            {
                for (int t=1; t<=29; t++)
                {
                    screen[t][n]=screen[t][n-1];
                }
            }
            emtiaz+=10*emtiazkomaki;
            emtiazkomaki++;
            i++;
        }
        tedadyekha=0;
    }
}

void Game::jahat(char c)
{
    if(c<0)
        c=getch();
    switch(c)
    {
    case 80: //down
        if(barkhordPaein2())
        {
            namayeshAjor(' ',x,y);
            y++;
        }
        break;
    case 75://left
        if(barkhordChap())
        {
            namayeshAjor(' ',x,y);
            x--;
        }
        break;
    case 77://right
        if(barkhordRast())
        {
            namayeshAjor(' ',x,y);
            x++;
        }
        break;
    case 72://up
        if (barkhordCharkesh())
        {
            namayeshAjor(' ',x,y);
            charkhesh();
        }
        break;
    }
}
#endif // GAME_H
