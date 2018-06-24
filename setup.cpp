#include <iostream> 
#include <stdlib.h> 
#include <conio.h>


using namespace std; 

bool gameOver; 
const int wight = 20; 
const int height = 20; 
int x, y, fruitX, fruitY, score; 
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, RIGHT, LEFT, UP, DOWN}; 
eDirection dir;


void setup () { 
gameOver = false; 
dir = STOP; 
x = wight / 2; 
y = height / 2; 
fruitX = rand() % wight; 
fruitY = rand() % height; 
score = 0; 

} 
