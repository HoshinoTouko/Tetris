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
    switch (type){
        //Square
        case 0:
            set(5, 1);
            set(4, 1);
            set(5, 2);
            set(4, 2);
            break;
        //"L"
        case 1:
            set(3, 1);
            set(4, 1);
            set(5, 1);
            set(3, 2);
            break;
        //Reverse "L"
        case 2:
            set(3, 1);
            set(4, 1);
            set(5, 1);
            set(5, 2);
            break;
        //Rectangle
        case 3:
            set(3, 1);
            set(4, 1);
            set(5, 1);
            set(6, 1);
            break;
        //Lighting
        case 4:
            set(3, 2);
            set(4, 2);
            set(4, 1);
            set(5, 1);
            break;
        //Reverse lighting
        case 5:
            set(3, 1);
            set(4, 1);
            set(4, 2);
            set(5, 2);
            break;
        //Chinese character "TU"
        case 6:
            set(3, 2);
            set(4, 2);
            set(5, 2);
            set(4, 1);
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
		    if (tetMap[j][i] == 2)
		        tetMap[j][i] = 1;
		}
	}
	status = 0;
}
