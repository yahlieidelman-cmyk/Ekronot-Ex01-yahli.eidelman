#include "../Src/Queue.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

std::string removeElementsAndGetPrintedQueue(Queue* q)
{
	std::stringstream output;
	while (!isEmpty(q))
	{
		output << dequeue(q) << " ";
	}
	// removing the last letter (space)
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

bool test1()
{
	bool result = false;

	try
	{
		// check basic data structure functions
		cout << 
			"*******************************\n"  << 
			"Test 1 - basic queue functions--local\n" << 
			"*******************************\n" << endl;
			
		Queue* q0;
		try
		{

			cout << " \nInitializing queue with size 5 ... --local\n \n" << endl;
			q0 = new Queue;
			initQueue(q0, 5);
		}
		catch(...)
		{
			// queue failed to initialize - test failed
			cout << "\033[1;31mTest Failed\033[0m--local\n \n" << endl;
			
			cout << " \n" << endl;
			return 1111;
		}

		bool empty = isEmpty(q0);
		cout << "Checking if queue is empty ... --local\n";
		cout << "Running Test ... \t";

		if (empty)
		{
			cout << "\033[1;32mTest Passed\033[0m--local\n \n" << endl;
		}
		else
		{
			// queue is not empty - test failed
			cout << "\033[1;31mTest Failed\033[0m--local\n \n" << endl;
			cout << "Expected: true\n" 
			<< "Got     : " << (empty ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1112;
		}

		const std::string queue0elements = "1 4 9 16 25";

		cout << "Adding elements to queue ... --local" << queue0elements << "\n" << endl;

		for (int i = 0; i < 5; i++)
		{
			enqueue(q0, (i+1) * (i+1));
		}

		bool full = isFull(q0);
		cout << "Checking if queue is full ... --local\n";
		cout << "Running Test ... \t";

		if(full)
		{
			cout << "\033[1;32mTest Passed\033[0m--local\n \n" << endl;
		}
		else
		{
			// queue is not full - test failed
			cout << "\033[1;31mTest Failed\033[0m--local\n \n" << endl;
			cout << "Expected: true\n"
				<< "Got     : " << (full ? "true" : "false") << " \n";
			cout << " \n" << endl;
			return 1113;
		}

		std::string output = removeElementsAndGetPrintedQueue(q0);
		cout << "Removing elements and printing queue ...--local\n";
		cout << "Running Test ... \t";

		if(output == queue0elements)
		{
			cout << "\033[1;32mTest Passed\033[0m--local\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m--local\n \n" << endl;
			cout << "Expected: " << queue0elements << "\n"
				<< "Got     : " << output
				<< " \n " << endl;
			cout << " \n" << endl;
			return 1114;
		}

		try
		{
			cout << "Cleaning queue...--local\n" << endl;
			cout << "Running Test ... \t";
			cleanQueue(q0);
			cout << "\033[1;32mTest Passed\033[0m--local\n \n" << endl;
		}
		catch(const std::exception& e)
		{
			cout << "\033[1;31mTest Failed\033[0m--local\n \n" << endl;
			cout << " \n " << endl;
			cout << "Received the following error: " << e.what() << "--local\n"
				<< " \n " << endl;
			return 1115;
		}
		


		delete q0;
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n.\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" << 
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}

int main()
{
	bool result = test1();
	cout << (result == 0 ? "\033[1;32m \n****** Part 1 Test 1 Passed ******\033[0m\n \n" : "\033[1;31mPart 1 Test 1 Failed\033[0m\n \n") << endl;
	return result;
}
