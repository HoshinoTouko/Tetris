#include <windows.h>
#include <stdio.h>

//Variables
extern int x;
extern int y;
extern int tetMap[100][100];
extern int status;
extern int gameStatus;

DWORD WINAPI run(LPVOID pM){
    int lastTime;
    int nowTime;
    lastTime = time(NULL);
    nowTime = time(NULL);
    while (1){
        nowTime = time(NULL);
        if (nowTime - lastTime){
            lastTime = nowTime;
            /* Switch the gameStatus */
            /* Status: Success(0) Get down to the map(1) Unable to move(2) */
            /* Game status: Stop(0) Gaming(1) Lost(2) Pause(3) */
            if (gameStatus == 1){
                moveAction(3);
            }
            resolveStatus();
            show();
        }
        if (gameStatus == 2){
            break;
        }
    }
}

