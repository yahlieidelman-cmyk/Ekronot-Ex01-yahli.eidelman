#include "../Src/Stack.h"
#include "../Src/Utils.h"

#include <iostream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

int test2()
{
	// check basic data structure functions
	cout <<
		"*******************************\n" <<
		"Test 3 - More Stack tests--local\n" <<
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

		cout << "Pushing 100,000 elements to stack ... " << "\n" << endl;
		cout << "Running Test ... \t";
		try
		{
			for (int i = 0; i < 100000; i++)
			{
				push(s0, i);
			}
		}
		catch(...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1216;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

		cout << "Popping 10,000 elements from stack ... " << "\n" << endl;
		cout << "Running Test ... \t";
		try
		{
			for (int i = 0; i < 10000; i++)
			{
				pop(s0);
			}
		}
		catch(...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1217;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;

		empty = isEmpty(s0);
		cout << "Checking if stack is empty ... \n";
		cout << "Running Test ... \t";

		if (!empty)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			// stack is empty - test failed
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: false\n" 
			<< "Got     : " << (empty ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1218;
		}

		cout << "Pop 90,000 elements from stack ... " << "\n" << endl;
		cout << "Running Test ... \t";
		
		try
		{
			for (int i = 0; i < 90000; i++)
			{
				pop(s0);
			}
		}
		catch(...)
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << " \n" << endl;
			return 1217;
		}
		cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;


		empty = isEmpty(s0);
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
			return 1219;
		}

		try
		{
			cout << "Cleaning stack...\n" << endl;
			cout << "Running Test ... \t";
			cleanStack(s0);
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			delete s0;
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
	result = test2();
	cout << (result == 0 ?  "\033[1;32m \n****** Part 3 Test 2 Passed ******\033[0m\n \n" : "\033[1;31mPart 3 Test 2 Failed\033[0m\n \n") << endl;
	return result;
}
