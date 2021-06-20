#ifndef SAFHEBAZI_H
#define SAFHEBAZI_H
#include "goto.h"


class safhebazi
{
public:
    safhebazi()
    {
        screen=new int *[30];
        for(int i=0; i<30; i++)
            screen[i]=new int[25];
        for(int i=0; i<30; i++)
            for(int j=0; j<25; j++)
                screen[i][j]=0;
    }
    void kadrAsli();
    void kadrBaghal();
    void endgame();
    void namayeshUpdate();
    int **screen;
protected:

private:
};


void safhebazi::kadrAsli()
{
    char divareKenar=219;
    char divarePaein=219;

    for(int i=1; i<=24; i++)
    {
        gotoxy(5,i);
        printf("%c",divareKenar);
        gotoxy(29,i);
        printf("%c",divareKenar);
    }
    for(int j=5; j<29; j++)
    {
        gotoxy(j,24);
        printf("%c",divarePaein);
    }
}


void safhebazi::kadrBaghal()
{
    for(int i=9; i<13; i++)
    {
        gotoxy(39,i);
        printf("       ");
    }
    for(int i=38; i<=46; i++)
    {
        gotoxy(i,7);
        printf("%c",219);
        gotoxy(i,13);
        printf("%c",219);
    }
    for(int j=8; j<=12; j++)
    {
        gotoxy(38,j);
        printf("%c",219);
        gotoxy(46,j);
        printf("%c",219);
    }
}
void safhebazi::endgame()
{
    system("cls");
    gotoxy(35,10);
    printf("GAME OVER");
    Sleep(5000);
    exit(0);
}

void safhebazi::namayeshUpdate()
{
    gotoxy(6,3);
    for(int i=6; i<30; i++)
    {
        for(int j=0; j<25; j++)
        {
            gotoxy(i,j);
            if(screen[i][j]==1)
                printf("%c",219);
            else
                printf(" ");
        }
    }
}
#endif // SAFHEBAZI_H
