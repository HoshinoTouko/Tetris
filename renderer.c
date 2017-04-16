#include <stdio.h>
#include <windows.h>
//Variables
extern int x;
extern int y;
extern int tetMap[100][100];
extern int gameStatus;
extern score;

void gotoXY(int x, int y){
    COORD pos;
    pos.X = x*2;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void show(){
    int i, j;//Loop variable

    if (gameStatus == 2){
        system("cls");
        printf("You lost. Your score is %d", score);
        return;
    }
    for (j=0; j<y; j++){
        for (i=0; i<x; i++){
            if (tetMap[j][i] > 0){
                gotoXY(i, j);
                printf("[]");
            }
            else{
                gotoXY(i, j);
                printf("  ");
            }
        }
        gotoXY(i, j);
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
    gotoXY(i-3, j);
    printf("Your score:  %d", score);
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

