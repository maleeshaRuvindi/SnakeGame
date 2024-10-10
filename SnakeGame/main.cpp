#include <iostream>
#include <conio.h>
#include <Windows.h>
const int width=20, height=20;
using namespace std;
bool GameOver;
int x, y;
int fruitX, fruitY,score;
enum eDirection { STOP = 0,LEFT,RIGHT,UP,DOWN };
eDirection dir;
int tailX[100], tailY[100];
int nTail;

void Setup() {
	
	GameOver = false;
	fruitX = rand() % width;
	fruitY = rand()%height;
	x = width / 2;
	y = height / 2;
	dir = STOP;
	score = 0;

	
}
void Draw() {
	system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			dir = STOP;
			break;
		}
		
	}
	}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch (dir) {
		
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		
		break;

	}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = (rand() % width) ;
		fruitY = (rand() % height) ;
		nTail++;

	}
}
int main() {
	Setup();
	while (!GameOver) {
		Draw();
		Input();
		Logic();
		Sleep(10);
	}


}
