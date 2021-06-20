#ifndef GOTO_H
#define GOTO_H

void gotoxy(int x, int y)
{
    HANDLE stdOutput;
    COORD pos;
    stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(stdOutput, pos);
    return;
}

#endif // GOTO_H
