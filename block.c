#include <stdio.h>
#include <stdlib.h>

//Variables
extern int x;
extern int y;
extern int tetMap[100][100];
extern int status;
extern int type;
extern int nextType;

void newTetris(){
    if (status == 2){
        return; 
    }
    type = nextType;
    nextType = rand() % 7;
    /* 
      About central block:
      If the central block is 2, no rotate.
      If the central block is 3, it can rotate 360.
      If the central block is 4, rotate 90.
      If the central block is 5, rotate 90R.
      If the central block is 6, rotate 4x4.
     */
    switch (type){
        //Square
        case 0:
            set(4, 1, 2);
            set(4, 2, 2);
            set(5, 1, 2);
            set(5, 2, 2);
            break;
        //"L"
        case 1:
            set(4, 1, 2);
            set(4, 2, 3);
            set(4, 3, 2);
            set(5, 3, 2);
            break;
        //Reverse "L"
        case 2:
            set(4, 1, 2);
            set(4, 2, 3);
            set(4, 3, 2);
            set(5, 3, 2);
            break;
        //Rectangle
        case 3:
            set(3, 2, 2);
            set(4, 2, 6);
            set(5, 2, 2);
            set(6, 2, 2);
            break;
        //Lighting
        case 4:
            set(3, 2, 2);
            set(4, 2, 4);
            set(4, 1, 2);
            set(5, 1, 2);
            break;
        //Reverse lighting
        case 5:
            set(3, 1, 2);
            set(4, 1, 2);
            set(4, 2, 4);
            set(5, 2, 2);
            break;
        //Chinese character "TU"
        case 6:
            set(3, 2, 2);
            set(4, 2, 3);
            set(5, 2, 2);
            set(4, 1, 2);
            break;
    }
}

/* Reset the map */
void reset() {
	int i, j;//Loop variable
	for (j=0; j<y; j++) {
		for (i=0; i<x; i++) {
			tetMap[j][i] = 0;
		}
	}
}

/* Frozen the blocks(from 2 to 1). */
void frozen(){
    int i, j;
    for (j=0; j<y; j++) {
		for (i=0; i<x; i++) {
		    if (tetMap[j][i] > 1)
		        tetMap[j][i] = 1;
		}
	}
	status = 0;
}
