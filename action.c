#include <stdbool.h>
#include <stdio.h>

//Variables
extern int x;
extern int y;
extern int tetMap[100][100];
extern int status;
extern int gameStatus;
extern int score;

/* Set the number 2 to the map */
void set(int xn, int yn) {
    tetMap[yn-1][xn] = 2;
}
/* Move all block which value is equal to 2(Active) */
/* Variable d means direction, and Left(0) Up(1) Right(2) Down(3) */
/* Return data: Success(0) Get down to the map(1) Unable to move(2) */
void moveAction(int d) {
    /* Status: Success(0) Get down to the map(1) Unable to move(2) */
    /* Game status: Stop(0) Gaming(1) Lost(2) Pause(3) */
    if (gameStatus == 3){
        return;
    }
    int i, j;
	switch (d) {
	    //Left
		case 0:
		    //Check if the function can work.
			for (j=0; j<y; j++) {
				for (i=0; i<x; i++) {
					if (tetMap[j][i] == 2){
					    /* 
                           If the block is close to the left side, 
                           return code 2(Unable to move).
                        */
					    if (i == 0){
					        status = 2;
					        return;
                        }
                        /*
                          If the left block of this block is not null,
                          return code 2(Unable to move).
                        */
					    else if (tetMap[j][i-1] == 1){
					        status = 2;
					        return;
                        }
                    }
				}
			}
			//Do it
			for (j=0; j<y; j++) {
				for (i=0; i<x; i++) {
					if (tetMap[j][i] == 2){
					    tetMap[j][i-1] = 2;
					    tetMap[j][i] = 0;
                    }
				}
			}
			break;
		//Up
		case 1:
		    /*
                No, you cannot up 
            */
            while (status != 1){
                moveAction(3);
            }
            return;
			break;
		//Right
		case 2:
		    //Check if the function can work.
			for (j=0; j<y; j++) {
				for (i=x-1; i>=0; i--) {
					if (tetMap[j][i] == 2){
					    /* 
                           If the block is close to the right side, 
                           return code 2(Unable to move).
                        */
					    if (i == x-1){
					        status = 2;
					        return;
                        }
                        /*
                          If the right block of this block is not null,
                          return code 2(Unable to move).
                        */
					    else if (tetMap[j][i+1] == 1){
					        status = 2;
					        return;
                        }
                    }
				}
			}
			//Do it
			for (j=0; j<y; j++) {
				for (i=x-1; i>=0; i--) {
					if (tetMap[j][i] == 2){
					    tetMap[j][i+1] = 2;
					    tetMap[j][i] = 0;
                    }
				}
			}
			break;
		//Down
		case 3:
		    //Check if the function can work.
			for (j=y-1; j>=0; j--) {
				for (i=0; i<x; i++) {
					if (tetMap[j][i] == 2){
					    /* 
                           If the block is close to the down side, 
                           return code 1(Get down to the map).
                        */
					    if (j == y-1){
					        status = 1;
					        return;
                        }
                        /*
                          If the block touch the block frozened,
                          return code 1(Get down to the map).
                        */
					    else if (tetMap[j+1][i] == 1){
					        status = 1;
					        return;
                        }
                    }
				}
			}
			//Do it
			for (j=y-1; j>=0; j--) {
				for (i=0; i<x; i++) {
					if (tetMap[j][i] == 2){
					    tetMap[j+1][i] = 2;
					    tetMap[j][i] = 0;
                    }
				}
			}
			break;
		default:
			status = 2;
			return;
			break;
	}
	status = 0;
}

/* Check erase */
void checkErase(){
    int i, j;
    int k;
    bool isFull;
    /* Analysis the number of the layers */
    for (j=y-1; j>0; j--) {
        isFull = true;
		for (i=0; i<x; i++) {
		    if (!tetMap[j][i])
		        isFull = false;
		}
		if (isFull){
		    /* Get a score! */
		    score++;
		    /* Set zero to the full row */
		    for (i=0; i<x; i++) {
		        tetMap[j][i] = 0;
		    }
		    /* All rows above move down one layer */
		    for (k=j; k>0; k--){
		        for (i=0; i<x; i++){
		            tetMap[k][i] = 0;
		            if (tetMap[k-1][i] == 1){
		                tetMap[k][i] = tetMap[k-1][i];
                    }
                }
            }
            j=y;
        }

	}
}

/* Check that if the guy lost the game */
void checkLost(){
    int i, j;
    for (i=0; i<x; i++){
        if (tetMap[0][i] == 1){
            gameStatus = 2;
        }
    }
    if (gameStatus == 2){
        system("cls");
        printf("You lost.");
    }
}


/* Game status: Success(0) Get down to the map(1) Unable to move(2) */
/* Status: Stop(0) Gaming(1) Lost(2) Pause(3) */
void resolveStatus(){
    switch (status){
        case 0:
            checkLost();
            break;
        case 1:
            frozen();
            checkErase();
            checkLost();
            newTetris();
            break;
        case 2:
            break;
        default:
            break;
    } 
}



