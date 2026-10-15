#include "../Src/Stack.h"
#include "../Src/Utils.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

std::string arrayToString(int numbers[], int size)
{
	std::stringstream output;
	for (int i = 0; i < 10; i++)
	{
		output << numbers[i] << " ";
	}
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

bool test3()
{
	// check basic data structure functions
	cout <<
		"*******************************\n" <<
		"Test 4 - utils\n" <<
		"*******************************\n" << endl;
	try
	{
		cout << " \nCreating array ... [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]\n" << endl;
		int numbers[10];
		for (int i = 0; i < 10; i++)
		{
			numbers[i] = (i+1) * 2;
		}

		reverse(numbers, 10);
		cout << "Using reverse() on array and printing it... " << endl;
		cout << "Running Test ... \t";
		std::string reversedArray = "20 18 16 14 12 10 8 6 4 2";
		std::string resultfromReverse = arrayToString(numbers, 10);

		if (resultfromReverse == reversedArray)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Using reverse() on array and printing it... " << endl
			<< "Expected: " << reversedArray << "\n"
			<< "Got     : " << resultfromReverse
			<< "\n" << endl;
			return 1311;
		}
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" << 
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;
}

int main()
{
	int result;
	result = test3();
	cout << (result == 0 ?  "\033[1;32m \n****** Part 4 Test 1 Passed ******\033[0m\n \n" : "\033[1;31mPart 4 Test 1 Failed\033[0m\n \n") << endl;
	return result;
}
