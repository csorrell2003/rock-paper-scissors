//Rock, paper, scissors in C++
//Why you ask?...well, why not!
#include "stdafx.h"
#include <iostream>
#include <ctime> // Needed for the true randomization

int main(){
	/*function prototypes*/
	int getChoice(int min, int max);
	int displaymenu();
	int randChoice();
	bool roundWinner(int choice, int compChoice, int &count);
	void displayScore(int round, int count);
	bool goAgain();

	std::cout << "Lets play Rock, Paper, Scissors!\n";
	std::cout << "Best 2 out of 3 wins...\nReady?\n\n";

	do{
		/*variables*/
		int choice, compChoice;
		int count = 0;
		int round = 0;

		for (int i = 0; i < 3; i++){
			choice = displaymenu();
			compChoice = randChoice();
			roundWinner(choice, compChoice, count);
			round++;
			displayScore(round, count);

			if (count == 2){
				break;
			}
			
		}
		if (count == 2){
			std::cout << "Congradulations! You've won the match.\n";
		}
		else{
			std::cout << "You lose. Better luck next time.\n";
		}
	} while (goAgain() == true);

	return 0;
}

/*getChoice function*/
int getChoice(int min, int max)
{
	int input;
	// Get and validate the input
	std::cin >> input;
	while (input < min || input > max)
	{
		std::cout << "Invalid input. Enter an integer between " << min << " and " << max << ": ";
		std::cin >> input;
	}
	return input;
}

/*displaymenu function*/
int displaymenu(){
	std::cout << " 1- Rock\n 2- Paper\n 3- Scissors\n\n Shoot...\n";
	return getChoice(1, 3);
}

/*randChoice funtion*/
int randChoice(){
	int randChoice;
	srand(time(0));
	randChoice = rand() % 3 + 1;
	return randChoice;
}

/*roundWinner function*/
bool roundWinner(int choice, int compChoice, int &count){
	if (choice == 1 && compChoice == 2){
		std::cout << "The Computer chose Paper.\n";
		return false;
	}
	if (choice == 2 && compChoice == 3){
		std::cout << "The Computer chose Scissors.\n";
		return false;
	}
	if (choice == 3 && compChoice == 1){
		std::cout << "The Computer chose Rock.\n";
		return false;
	}
	else{
		std::cout << "You won this round!\n";
		count++;
		return true;
	}
	
}
/*displayScore function*/
void displayScore(int round, int count){
	int compScore = round - count;
	std::cout << "\nPlayer " << count << std::endl;
	std::cout << "Computer " << compScore << std::endl << std::endl;

}

/*goAgain function*/
bool goAgain(){
	char input;
	std::cout << "Would you like to play again? (y or n)\n";
	std::cin >> input;
	if (input == 'y' || input == 'Y'){
		return true;
	}
	else
		return false;

}
