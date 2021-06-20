#ifndef AJOR_H
#define AJOR_H
#include "goto.h"


class ajor
{
public:
    ajor()
    {
        modelAjor=new int*[4];
        for(int i=0;i<4;i++)
            modelAjor[i]=new int[2];
        for(int i=0;i<4;i++)
            for(int j=0;j<2;j++)
            modelAjor[i][j]=0;

    }

    void namayeshAjor(char c,int x,int y);
    void entekhabAjor(int num);
    void charkhesh();
    int **modelAjor;
protected:

private:
};

void ajor::namayeshAjor(char c,int x,int y)
{
    for(int i=0; i<4; i++)
    {
        gotoxy(x+modelAjor[i][0],y+modelAjor[i][1]);
        printf("%c",c);
    }
}
void ajor::entekhabAjor(int num)
{
    switch (num)
    {
    case 0:
        modelAjor[0][0]=0;
        modelAjor[0][1]=-1;
        modelAjor[1][0]=0;
        modelAjor[1][1]=0;
        modelAjor[2][0]=-1;
        modelAjor[2][1]=0;
        modelAjor[3][0]=-1;
        modelAjor[3][1]=-1;
        break;
    case 1:
        modelAjor[0][0]=0;
        modelAjor[0][1]=-1;
        modelAjor[1][0]=0;
        modelAjor[1][1]=0;
        modelAjor[2][0]=1;
        modelAjor[2][1]=0;
        modelAjor[3][0]=1;
        modelAjor[3][1]=1;
        break;
    case 2:
        modelAjor[0][0]=0;
        modelAjor[0][1]=-1;
        modelAjor[1][0]=0;
        modelAjor[1][1]=0;
        modelAjor[2][0]=0;
        modelAjor[2][1]=1;
        modelAjor[3][0]=0;
        modelAjor[3][1]=2;
        break;
    case 3:
        modelAjor[0][0]=-1;
        modelAjor[0][1]=0;
        modelAjor[1][0]=0;
        modelAjor[1][1]=0;
        modelAjor[2][0]=1;
        modelAjor[2][1]=0;
        modelAjor[3][0]=0;
        modelAjor[3][1]=1;
        break;
    case 4:
        modelAjor[0][0]=0;
        modelAjor[0][1]=0;
        modelAjor[1][0]=1;
        modelAjor[1][1]=0;
        modelAjor[2][0]=0;
        modelAjor[2][1]=1;
        modelAjor[3][0]=1;
        modelAjor[3][1]=1;
        break;
    case 5:
        modelAjor[0][0]=-1;
        modelAjor[0][1]=-1;
        modelAjor[1][0]=0;
        modelAjor[1][1]=-1;
        modelAjor[2][0]=0;
        modelAjor[2][1]=0;
        modelAjor[3][0]=0;
        modelAjor[3][1]=1;
        break;
    case 6:
        modelAjor[0][0]=1;
        modelAjor[0][1]=-1;
        modelAjor[1][0]=0;
        modelAjor[1][1]=-1;
        modelAjor[2][0]=0;
        modelAjor[2][1]=0;
        modelAjor[3][0]=0;
        modelAjor[3][1]=1;
        break;
    }
}

void ajor::charkhesh()
{
    int z;
    for(int i=0; i<4; i++)
    {
        z=modelAjor[i][1];
        modelAjor[i][1]=-modelAjor[i][0];
        modelAjor[i][0]=z;
    }
}
#endif // AJOR_H
