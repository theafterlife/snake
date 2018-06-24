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


void draw() { 
system("cls"); 
for (int i = 0; i < wight+2; i++) 
	cout << "#"; 
	
	cout << endl; 
	
for (int i = 0; i < wight+2; i++) 
{ 

for (int j = 0; j < height; j++) {

	if(j == 0 || j == wight)
	
		cout << "#"; 
	
	if (i == y && j == x)	
		cout << "0";
	else if (i == fruitY && j == fruitX)
		cout << "F";
	else {
		bool print = false;
		for (int k =0; k<nTail; k++){
			if (tailX[k]== j && tailY[k]==i){
			print = true;
			cout << "o";
		}
		}
		if(!print)
		cout << " ";	
	}
		 
}		
cout << "#"; 
cout << endl;
 
} 

for (int i = 0; i < wight + 2; i++) 
	cout << "#"; 
	cout << endl; 
	cout << "Score: " << score << endl;
}

void input() { 
	if (_kbhit()) {
		switch (_getch())
		{
			case 'a': 
			dir = LEFT;
			break;
			case 'w': 
			dir = UP;
			break;
			case 's': 
			dir = DOWN;
			break;
			case 'd': 
			dir = RIGHT;
			break;
			case 'x': 
			gameOver = true;
			break;	
		}
	}

} 
