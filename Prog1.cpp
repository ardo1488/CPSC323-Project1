#include <iostream>
#include <string>



int main() 
{
	// Transition table
	const int Total_STATE = 4;
	const int Total_AB = 2; 
	int transition_table[Total_STATE][Total_AB] =
		{{2, 0}, {3, 2}, {4, 3}, {0, 4}};

	//prompt user for input
	std::string prompt;
	std::cout << "Enter a string only using 'a' and 'b', ending in '$': ";
	std::cin >> prompt;
	
	//error handling ($)
	if (prompt[prompt.length() - 1] != '$') 
	{
		std::cout << "Invalid input! Include '$' at the end! ";
		return 0;
	}
	prompt.pop_back();

	//error handling 'a', 'b' requirement
	const int start_STATE = 1;
	int state = start_STATE;
	for (char c : prompt) 
	{
		int column;
		if (c == 'a') 
		{
			column = 0;
		}
		else if (c == 'b') 
		{
			column = 1;
		}
		else 
		{	
			std::cout << "Invalid Input! Include ONLY 'a' and 'b'" << std::endl;
			return 0;
		}
		state = transition_table[state-1][column];
		if (state == 0) 
		{
			std::cout << "NO" << "\n";
			return 0;
		}
	}
	//Checking final State
	if (state == 3 || state == 4) 
	{
		std::cout << "YES" << "\n";
	}
	else 
	{
		std::cout << "NO" << "\n";
	}
	return 0;
