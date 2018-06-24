#include <windows.h>
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

void logic() { 

int prevX = tailX[0];
int prevY = tailY[0];
int prev2x, prev2y;
tailX[0] = x;
tailY[0] = y;
for (int i = 1; i < nTail; i++){
	prev2x = tailX[i];
	prev2y = tailY[i];
	tailX[i] = prevX;
	tailY[i] = prevY;
	prevX = prev2x;
	prevY = prev2y;
	
	
}
	switch(dir){
		case LEFT: 
		x--;
			break;
		case RIGHT: 
		x++;
			break;
		case DOWN: 
		y++;
			break;
		case UP: 
		y--;
			break;
	}
	//if (x > wight+2 || x==0 || y > height+2 || y==0)
		//gameOver = true;
	if (x >= wight) 
x = 0; 
else if (x < 0) 
x = wight - 1; 
if (y >= height) 
y = 0; 
else if (y < 0) 
y = height - 1;

		for (int i = 0; i < nTail; i++){
			if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
		}
	if (x==fruitX && y==fruitY){
		score +=10;
		fruitX = rand() % wight; 
		fruitY = rand() % height;
		nTail++;
	}
} 

int main() { 
cout << "To start press 1 " << endl;
cout << "To complete press 2";

		
		switch (_getch()){
			case '1': {
			setup(); 
			while (!gameOver) { 
			draw(); 
			input(); 
			logic();
			Sleep(300);
			
		}
		break;
		}	
 			case '2': {
 				setup();
 				gameOver = true;
				break;
			 }
			  

}
if (gameOver = true)
cout << "You lose." << endl;
return 0; 

}
