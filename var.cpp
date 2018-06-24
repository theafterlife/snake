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
