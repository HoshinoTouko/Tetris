#include <stdio.h>
#include <windows.h>
#include <string.h>
//Variables
extern int x;
extern int y;
extern int tetMap[100][100];
extern int gameStatus;
extern int score;

void gotoXY(int x, int y){
    COORD pos;
    pos.X = x*2;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void show(){
    int i, j;//Loop variable
    
    /*
     New a console for double buffer.
    */
    HANDLE hNewConsole = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ,
         0,
         NULL, 
         CONSOLE_TEXTMODE_BUFFER,
         NULL);
    CONSOLE_CURSOR_INFO cci = {1, 0};
    SetConsoleCursorInfo(hNewConsole, &cci);
    
    /*
     Check game status
    */ 
    /* Show game status */
    /* Game status: Stop(0) Gaming(1) Lost(2) Pause(3) */
    char *statusInfo[20];
    char *scoreInfo[40];
    char scoreStr[20];
    switch (gameStatus) {
        case 0:
            *statusInfo = "Stop  ";
            break;
        case 1:
            *statusInfo = "Gaming  ";
            break;
        case 2:
            *statusInfo = "You lost  ";
            break;
        case 3:
            *statusInfo = "Pasue(p)  ";
            break;
    }
    *scoreInfo = "Your score:  ";
    sprintf(scoreStr, "%d", score);

    if (gameStatus == 2){
        printf("You lost. Your score is %d", score);
        WriteConsole(hNewConsole, *scoreInfo, strlen(*scoreInfo), NULL, NULL);
        WriteConsole(hNewConsole, scoreStr, strlen(scoreStr), NULL, NULL);
        SetConsoleActiveScreenBuffer(hNewConsole);
        return;
    }
    
    /*
     Use double buffer technology to show the map
    */
    for (j=0; j<y; j++){
        for (i=0; i<x; i++){
            if (tetMap[j][i] > 0){
                WriteConsole(hNewConsole, "¡ö", 2, NULL, NULL);
            }
            else{
                WriteConsole(hNewConsole, "  ", 2, NULL, NULL);
            }
        }
        WriteConsole(hNewConsole, "| \n", 3, NULL, NULL);
    }
    
    WriteConsole(hNewConsole, *statusInfo, strlen(*statusInfo), NULL, NULL);
    WriteConsole(hNewConsole, *scoreInfo, strlen(*scoreInfo), NULL, NULL);
    WriteConsole(hNewConsole, scoreStr, strlen(scoreStr), NULL, NULL);
    SetConsoleActiveScreenBuffer(hNewConsole);
}

void oldShow(){
    int i, j;//Loop variable
    system("cls");
    if (gameStatus == 2){
        printf("You lost. Your score is %d", score);
        return;
    }
    for (j=0; j<y; j++){
        for (i=0; i<x; i++){
            if (tetMap[j][i] > 0){
                printf("[]");
            }
            else{
                printf("  ");
            }
        }
        printf("| \n");
    }
    /* Show game status */
    /* Game status: Stop(0) Gaming(1) Lost(2) Pause(3) */
    switch (gameStatus) {
        case 0:
            printf("Stop  ");
            break;
        case 1:
            printf("Gaming  ");
            break;
        case 2:
            printf("You lost  ");
            break;
        case 3:
            printf("Pasue(p)  ");
            break;
    }
    printf("Your score:  %d", score);
}

