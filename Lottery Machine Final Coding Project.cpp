#include <iostream>	
#include <cstdlib>	
#include <ctime>	

// -- Constant Values --

int lotteryDigits = 15;
int SIZE = 7;

// -- Prototypes of different functions -- 

int generateLottery(int[], int, int);
int userInput(int[], int);
int matchCounter(int[], int[], int);
void displayNumbers(int[], int[]);
void winnerOrLoser(int);
bool checkArray(int array[], int size, int number);

// -- Main Code for Lottery Machine program --

using namespace std;

int main()
{
	// -- Defining Variables --
	int lottery[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int user[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int matches = 0;


	generateLottery(lottery, SIZE, lotteryDigits);

	userInput(user, SIZE);

	matches = matchCounter(lottery, user, matches);


	displayNumbers(lottery, user);

	winnerOrLoser(matches);

	system("pause");
	return 0;
}

// -- Defining Functions --

int generateLottery(int lottery[], int, int)
{
	unsigned seed = time(0);
	srand(seed);

	for (int y = 0; y < SIZE; y++)
	{
		lottery[y] = rand() % lotteryDigits;
	}

	return lottery[0], lottery[1], lottery[2], lottery[3], lottery[4], lottery[5], lottery[6];
}

// -- Lottery Machine Instructions for input user -- 

int userInput(int user[], int)
{
	cout << "WELCOME TO THE LOTTERY MACHINE!\n\n";
	cout << "You have to input 7 numbers between 0 and 15. If your inputted numbers match with the computer generated numbers then you can win money!\n";
	cout << "\nPrize money according to matches:\n";
	cout << "\n|" << "1 Match" << "=" << "5$" << "|" << endl;
	cout << "|" << "2 Matches" << "=" << "10$" << "|" << endl;
	cout << "|" << "3 Matches" << "=" << "20$" << "|" << endl;
	cout << "|" << "4 Matches" << "=" << "35$" << "|" << endl;
	cout << "|" << "5 Matches" << "=" << "50$" << "|" << endl;
	cout << "|" << "6 Matches" << "=" << "80$" << "|" << endl;
	cout << "|" << "7 Matches" << "=" << "150$" << "|" << endl;

	for (int y = 0; y < SIZE; y++)
	{
		printf("\n# %d of 7 Enter any number between 0 and 15:  ", y + 1);

		cin >> user[y];

		while (user[y] < 0 || user[y]>15)
		{
			cout << "Please enter again, number must be between 0 and 15: ";
			cin >> user[y];
		}
	}

	return user[0], user[1], user[2], user[3], user[4], user[5], user[6];
}

// -- Match Counter program --

int matchCounter(int lotto[], int input[], int)
{
	int match = 0;
	int duplicates[7] = { -1,-1,-1,-1,-1,-1,-1 };

	for (int x = 0; x < SIZE; ++x)
	{
		if (!checkArray(duplicates, 7, input[x]))
		{
			if (checkArray(lotto, 7, input[x]))
				match = match + 1;
			duplicates[x] = input[x];
		}
	}

	return match;
}

bool checkArray(int array[], int size, int number)
{
	bool has = false;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == number)
		{
			has = true;
		}
	}
	return has;
}

// -- Tells input user the numbers they have inputted and the winning numbers --

void displayNumbers(int lottery[], int user[])
{
	cout << "\nYour lottery numbers are: " << user[0] << " " << user[1] << " " << user[2] << " " << user[3] << " " << user[4] << " " << user[5] << " " << user[6] << endl;

	cout << "\nThe winning lottery numbers are: " << lottery[0] << " " << lottery[1] << " " << lottery[2] << " " << lottery[3] << " " << lottery[4] << " " << lottery[5] << " " << lottery[6] << endl;

}

// -- Tells the input user the amount of matches they have and the prize money they won according to the matches -- 

void winnerOrLoser(int matches)
{
	cout << "You have matched with " << matches << " numbers, you have won = ";

	if (matches != SIZE)

		switch (matches) {
		case 0:
			cout << "0$" << endl;
			break;
		case 1:
			cout << "5$" << endl;
			break;
		case 2:
			cout << "10$" << endl;
			break;
		case 3:
			cout << "20$" << endl;
			break;
		case 4:
			cout << "35$" << endl;
			break;
		case 5:
			cout << "50$" << endl;
			break;
		case 6:
			cout << "80$" << endl;
			break;
		case 7:
			cout << "150$" << endl;
			break;
		}
}