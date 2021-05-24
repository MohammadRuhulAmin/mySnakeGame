#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>

using namespace std;
class Information
{

public:

	void InputInformation();
	Information(){}
	bool  gameOver;
	const int width = 30;
	const int height = 30;
	int x, y, fruitX, fruitY, score;
	int tailX[100];
	int tailY[100];
	int nTail = 0;

};

enum eDirection{STOP =1, LEFT ,RIGHT,UP,DOWN};
eDirection dir;
string name;
class Information_setup : public Information
{

public:
	Information_setup(){}
	void setup()
	{
		gameOver = false;
		dir = STOP;
		x = width / 2;
		y = height / 2;
		fruitX = rand() % width;
		fruitY = rand() % height;
		score = 0;
	}

};

class Information_Draw :  public Information_setup 
{
public:
	Information_Draw(){}
	void Draw()
	{
		system("cls");
		Sleep(10);
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0)

					cout << "#";
				if (i == y  && j == x)
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
					{
						cout << " ";
					}
				}



				if (j == width - 1)
					cout << "#";


			}
			cout << endl;
		}
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;
		cout << "Score : " << score;
		cout << endl;

	}

};

class Information_Input : public Information_Draw

{
public:
	Information_Input(){}
	void Input()
	{
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
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				//	Sleep(100);
				break;
			case 'd':
				dir = RIGHT;
				//Sleep(100);
				break;
			case 'w':
				dir = UP;
				//Sleep(100);
				break;
			case 's':
				dir = DOWN;
				//Sleep(100);
				break;
			case 'x':
				gameOver = true;
				break;

			}
		}
	}

};
class Information_Logic : public Information_Input
{
public:
	Information_Logic(){}
	void Logic()
	{


		switch (dir)
		{
		case STOP:
			Sleep(100);
			break;
		case LEFT:
			Sleep(10);
			x--;
			Sleep(10);
			break;
		case RIGHT:
			Sleep(10);
			x++;
			Sleep(10);
			break;
		case UP:
			Sleep(100);
			y--;
			Sleep(100);
			break;
		case DOWN:
			Sleep(100);
			y++;
			Sleep(100);
			break;
		default:
			break;
		}
		if (x > width || x < 0 || y > height || y < 0)
			gameOver = true;
		for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == x && tailY[i] == y)
			{
				gameOver = true;
			}
		}
		if (x == fruitX && y == fruitY)
		{
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
			nTail++;
		}
	}

};


//---------------------------------main--------------------------------------------------------------
int main()
{
	Information_Logic Snake;

	 Snake.Information :: InputInformation();
	 Snake.Information_setup :: setup();
	 
	 Snake.Information::gameOver;
	 while ( Snake.Information :: gameOver == false)
	 {

		 Snake.Information_Draw::Draw();
		 Snake.Information_Input::Input();
		 Snake.Information_Logic::Logic();

	 }
	
	cout << "Name : " << name << endl << "Score :" << Snake.Information_setup :: score << endl;
	Sleep(1000);
	system("pause");
	
}

void  Information :: InputInformation()
{
	Sleep(100);
	cout << " Welcome to the c++ snake game :) " << endl;
        cout << " press A to left , W to up , D to rite and S to down (dont need to on the caps lock button ) " << endl; 
	Sleep(100);
	cout << "Enter your name : " << endl;
	getline(cin, name);
        

}
