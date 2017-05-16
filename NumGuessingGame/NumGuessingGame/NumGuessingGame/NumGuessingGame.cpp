// NumGuessingGame.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <algorithm>

int main()
{
		//Number Guessing game
		//###############Seed & Var Set Up###################
		bool NumGuessingGame = true; //If true the game is running
		srand(time(NULL)); //Seed
		
		int MinNumRange = 1; //The minimual number the computor will guess
		int MaxNumRange = 100; //The maximun number the computor will guess
		std::string YesNoInput; //Player Input
		
		int RoundNum = 0;
		//###############Intro##################
		std::cout << "I want you to think of a number between 1 & 100" << "\n";
		std::getchar();
		std::cout << "Thought of one?" << "\n";
		std::getchar();
		std::cout << "Alright" << "\n";
		std::getchar();
		
		//###############Game##################
		while (NumGuessingGame)
		{
			RoundNum++;
			bool VaildAnswer = false;
			int range = (MaxNumRange - MinNumRange) + 1;
			int NumberGuess = MinNumRange + int(range*rand() / (RAND_MAX + 1)); //Picks a random number between the (MaxNumRange = 100) and (MinNumRange = 1) 

			system("cls"); 
			std::cout << "Round #" << RoundNum << "\nIs it" << "\n" << NumberGuess << "\nHigher, Lower or Yes?\n";
			
			do {
			std::cin >> YesNoInput; //Input for Higher or Lower
			std::transform(YesNoInput.begin(), YesNoInput.end(), YesNoInput.begin(), ::tolower); //Converts the string into lowercase
			if (YesNoInput == "yes") //If the Computor got it right
			{
				VaildAnswer = true; //Do Loop Breaker
				std::cout << "\nHa! I win!";
				
				//Whitty statement based on if the computor guessed in 10 turns or less
				if (RoundNum <= 10)
				{
					std::cout << "\n" << RoundNum << " rounds isn't bad\n";
				}
				//statement based on if the computor guessed in more than 10 turns
				else if (RoundNum > 10) 
				{ 
					std::cout << "\n" << RoundNum << " rounds eh I need to do some more work\n"; 
				}
				
				std::getchar(); std::getchar();
				NumGuessingGame = false; //Ends the game
				break;
			}
			if (MaxNumRange == MinNumRange) //If the Player is cheating
			{
				VaildAnswer = true; //Do Loop Breaker
				std::cout << "Wait no! Your cheating\nI'm not going to play anymore";
				std::getchar(); std::getchar();
				NumGuessingGame = false; //Ends the game
				break;

			}
			else if (YesNoInput == "higher") //Player says the number is higher
			{
				VaildAnswer = true; //Do Loop Breaker
				MinNumRange = NumberGuess + 1; //Sets the minimal range to the last number guessed
			}
			else if (YesNoInput == "lower") //Player says the number is lower
			{
				VaildAnswer = true; //Do Loop Breaker
				MaxNumRange = NumberGuess - 1; //Sets the manimun range to the last number guessed
			}
			} while (VaildAnswer == false); 
			//If [VaildAnswer == true] it will ask the player to type something in agian; 
			//If [VaildAnswer == false] will cause the loop to end and the proces of picking a random number between the max and min will start agian
		}
		//###############Exit##################
		return 0;
}

