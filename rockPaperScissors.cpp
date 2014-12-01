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
	bool roundWinner(int choice, int compChoice, int &count, int &compCount);
	void displayScore(int round, int count);
	bool goAgain();

	std::cout << "Lets play Rock, Paper, Scissors!\n";
	std::cout << "Best 2 out of 3 wins...\nReady?\n\n";

	do{
		/*variables*/
		int choice, compChoice;
		int count = 0;
		int compCount = 0;

		while((compCount != 2) && (count !=2)){
			choice = displaymenu();
			compChoice = randChoice();
			roundWinner(choice, compChoice, count, compCount);
			displayScore(compCount, count);
			
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
bool roundWinner(int choice, int compChoice, int &count, int &compCount){
	if (choice == 1 && compChoice == 2){
		std::cout << "The Computer chose Paper.\n";
		compCount++;
		return false;
	}
	if (choice == 2 && compChoice == 3){
		std::cout << "The Computer chose Scissors.\n";
		compCount++;
		return false;
	}
	if (choice == 3 && compChoice == 1){
		std::cout << "The Computer chose Rock.\n";
		compCount++;
		return false;
	}
	if (choice == compChoice){
		std::cout << "This round is a tie.";
		return false;
	}
	else{
		std::cout << "You won this round!\n";
		count++;
		return true;
	}
	
}
/*displayScore function*/
void displayScore(int compCount, int count){
	std::cout << "\nPlayer " << count << std::endl;
	std::cout << "Computer " << compCount << std::endl << std::endl;

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
