#include "../Src/Stack.h"
#include "../Src/Utils.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

std::string popElementsAndGetPrintedStack(Stack* s)
{
	std::stringstream output;
	while (!isEmpty(s))
	{
		output << pop(s) << " ";
	}
	// removing the last letter (space)
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

int test1()
{
	// check basic data structure functions
	cout <<
		"*******************************\n" <<
		"Test 3 - basic stack functions--local\n" <<
		"*******************************\n" << endl;
	try
	{

	
		Stack* s0;
		try
		{
			cout << " \nInitializing new stack ... \n" << endl;
			s0 = new Stack;
			initStack(s0);
		}
		catch(...)
		{
				// stack failed to initialize - test failed
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << " \n" << endl;
				return 1211;
		}
		bool empty = isEmpty(s0);
		cout << "Checking if stack is empty ... \n";
		cout << "Running Test ... \t";
		
		if (empty)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// stack is not empty - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: true\n" 
			<< "Got     : " << (empty ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1212;
		}

		const std::string stack0elements = "11 22 33 44 55";

		cout << "Pushing elements to stack ... " << stack0elements << "\n" << endl;
		for (int i = 0; i < 5; i++)
		{
			push(s0, (i + 1) * 11);
		}

		std::string output = popElementsAndGetPrintedStack(s0);
		const std::string stack0PoppedElements = "55 44 33 22 11";
		cout << "Popping and printing each element in stack ...\n";
		cout << "Running Test ... \t";

		if(output == stack0PoppedElements)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << stack0PoppedElements << "\n"
				<< "Got     : " << output
				<< " \n " << endl;
			cout << " \n" << endl;
			return 1214;
		}

		try
		{
			cout << "Cleaning stack...\n" << endl;
			cout << "Running Test ... \t";
			cleanStack(s0);
			delete s0;
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			return 0;
		}
		catch(const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "\n"
				<< " \n " << endl;
			return 1215;
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
}

int main()
{
	int result;
	result = test1();
	cout << (result == 0 ? "\033[1;32m \n****** Part 3 Test 1 Passed ******\033[0m\n \n" : "\033[1;31mPart 3 Test 1 Failed\033[0m\n \n") << endl;
	return result;
}
