#include<iostream>
#include<cmath>
#include<Windows.h>  //to be able to use system("cls") method
#include<conio.h>   //to be able to use getch() method
#include<iomanip>
using namespace std;

class guessAndCheck
{
public:
	int x;
	int digitSensitivity;
	guessAndCheck(int x=1, int digitSensitivity=1)
	{
		this->x = x;
		this->digitSensitivity = digitSensitivity;
	}
	int upperPerfectSquare();
	int bottomPerfectSquare();
	double squareRoot();
};

int guessAndCheck::upperPerfectSquare()
{
	bool perfect = false;
	int k = x + 1;
	while (true)
	{
		int initial = 0;
		int initSq = 0;
		while (initSq <= k)
		{
			initSq = initial * initial;
			if (initSq == k)
			{
				perfect = true;
				break;
			}
			initial++;
		}
		if (perfect == false)
		{
			k++;
		}
		else return (initSq);
	}
}

int guessAndCheck::bottomPerfectSquare()
{
	bool perfect = false;
	int k = x - 1;
	while (true)
	{
		int initial = 0;
		int initSq = 0;
		while (initSq <= k)
		{
			initSq = initial * initial;
			if (initSq == k)
			{
				perfect = true;
				break;
			}
			initial--;
		}
		if (perfect == false)
		{
			k--;
		}
		else return (initSq);
	}
}

double guessAndCheck::squareRoot()
{
	double lowBound = sqrt((double)bottomPerfectSquare());
	double maxError = (double)1.00 / pow(10, (digitSensitivity));
	double currentError = 1.0000;
	
	if ((lowBound*lowBound) == x) return lowBound;//if the number we look for is perfect square no need to keep go

	double newLowBound = lowBound + 0.1;
	double prevLowBound = lowBound;

	bool flag = false;
	for (int i = 0;; i++)
	{
		while (newLowBound*newLowBound < x)
		{
			prevLowBound = newLowBound;
			newLowBound += (1.000000 / pow(10, (i + 1)));
			currentError = abs(pow(newLowBound, 2) - pow(prevLowBound, 2));
			if (currentError < maxError)
			{
				flag = true;
				break;
			}
		}
		newLowBound -= (1.000000 / pow(10, (i + 1)));//This substruction is crucial 
		//											to prevent newLowBound*newLowBound become bigger than x
		if (flag == true) break;
	}
	if (flag == true) return newLowBound;
}
int main()
{

	int goal;
	int sensitivity;
	guessAndCheck obj1;
	
	char situation;
	while (true)
	{
		Sleep(260);

		system("cls");

		cout << "\t\t Welcome to Square Root Finder, Enter below numbers \n";
		cout << "1) Number to find its root add a blank then Decimal Point Sensitivty after dot" << endl;
		cout << "2) Exit program" << endl;
		cin >> situation;

		if ((int)situation == 49)
		{
			cout << "Please insert the number to find its square root\n";
			cin >> goal;
			cin >> sensitivity;
			while (!cin || (goal < 0) || (sensitivity < 0)) // to make sure input is non-negative integer and numerical
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Please insert a number and blank then a sensitivty which are positive\n";
				cin >> goal;
				cin >> sensitivity;
			}
			obj1.x = goal;
			obj1.digitSensitivity = sensitivity;
			
			cout << "Upper perfect square is " << obj1.upperPerfectSquare() << " \n";
			cout << "Bottom perfect square is " << obj1.bottomPerfectSquare() << " \n";
			cout << "Square root of " << fixed << setprecision(sensitivity) << goal << " is " << obj1.squareRoot() << " \n";
			cout << "To keep go hit a key\n";
			_getch();

		}
		else if ((int)situation == 50)
		{
			cout << "Good By";
			Sleep(215);
			break;

		}
		else
		{
			cout << "Invalid number!\n";
			Sleep(230);
			system("cls");
			cin.clear();
			cin.ignore(256, '\n');
		}


	}
	
	
	system("Pause");
	return 0;
}

