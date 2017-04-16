#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include "renderer.h"
#include "timer.h"
#include "action.h"
#include "block.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Initialize the row and column */
int x = 10;
int y = 20;
/* Status: Success(0) Get down to the map(1) Unable to move(2) */
/* Game status: Stop(0) Gaming(1) Lost(2) Pause(3) */
int status = 0;
int gameStatus = 1;
/* Score */
int score = 0;
/* 
  Define the type of the block.
  Square(0), "L"(1), Rectangle(2), Lighting(3), 
  Reverse lighting(4), Chinese character "TU"(5)
 */
int type = 0;
int nextType = 0;
char shape[7][4][16];
/* Define a map */
int tetMap[100][100];

/* Main function */
int main(int argc, char *argv[]) {
    /* Get console infomation */
    HANDLE g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    /* Hide cursor */
    CONSOLE_CURSOR_INFO cursorInfo = {1, false};
    SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);
    //Initialize a timer
    HANDLE handle = CreateThread(NULL, 0, run, NULL, 0, NULL);
    WaitForSingleObject(handle, 0);
    //Randomize a type
    srand(time(NULL));
    type = rand() % 7;
    nextType = rand() % 7;
    //Reset the map
    reset();
    //Create a new tetris
    newTetris();
    int key;
    while (1){
        key = getch();
        /*
            Key infomation:
            Left:75 (0)
            Up:72 (1)
            Right:77 (2)
            Down:80 (3)
            Space:32
            p:112 (Pause)
        */
        
        switch (key){
            case 32:
                rotate();
                break; 
            case 75:
                moveAction(0);
                break;
            case 72:
                moveAction(1);
                break;
            case 77:
                moveAction(2);
                break;
            case 80:
                moveAction(3);
                break;
            case 112:
                if (gameStatus == 3){
                    gameStatus = 1;
                }
                else if (gameStatus == 1){
                    gameStatus = 3;
                }
                break;
            default:
                break; 
        }
        resolveStatus();
        show();
        if (gameStatus == 2){
            break;
        }
    }
    return 0;
}
/* Main function end */

