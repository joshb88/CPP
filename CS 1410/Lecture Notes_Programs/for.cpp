// This program has the user input a number n and then finds the
// mean of the first n positive integers

// Josh Boehm

#include <iostream>
using namespace std;

int main()
{
	int n, m;		// value is some positive number n
	int total = 0;	// total holds the sum of the first n positive numbers 
	int number;		// the amount of numbers
	float mean;		// the average of the first n positive numbers

	cout << "Please enter a positive integer" << endl;
	cin >> n;

	cout << "Please enter a second, higher, positive integer" << endl;
	cin >> m;

	if (m > n && n > 0)
	{
		for (number = n; number <= m; number++)
		{
			total = total + number;
		}	// curly braces are optional since there is only one statement

		mean = static_cast<float>(total) / (m-n+1);	// note the use of the typecast
													// operator here 
		cout << "The mean average of the positive integers from " << n << " to " << m
			 << " is " << mean << endl;
	}

	else
		cout << "Invalid input - integer must be positive" << endl;

	return 0;
}