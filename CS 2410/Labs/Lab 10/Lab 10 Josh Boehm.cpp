#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/*Write a test program to accept two numbers from console. 
Then check to see if first number is larger than second number. 
If it is throwing an exception and handle the error properly.*/

// int main()
// {
//   try
//   {
//     int num1,num2;
//     cout << "Enter first number." << endl;
//     cin >> num1;
//     cout << "Enter second number." << endl;
//     cin >> num2;
//     if(num1 > num2) {throw runtime_error("First number too great.");}
//   }
//   catch(runtime_error& ex)
//   {
//     cout << ex.what();    //use what() meber function 
//     cout << "The first number must be less than the second." << endl;
//     return 0;
//   }
// }

/*
Lab 10-2:
Write a test program to accept a number from console, then check to see if the number is positive or negative. 
If it is negative throw an exception and indicate the number is negative otherwise take the squire root of the number. 
Use exception handling to control the flow of the code.  
*/

// int main()
// {
//   try
//   {
//     int num;
//     cout << "Enter a number." << endl;
//     cin >> num;
//     if(num < 0) { throw runtime_error("That number is negative."); }
//     cout << sqrt(num);
//   }
//   catch(const runtime_error& exc)
//   {
//     cout << exc.what();
//   }
  
// }

/* Write a test program to accept a number from console.  
This number is radius of circle if the number is positive find area and circumference.  
Otherwise, throw an exception with proper message. */

// int main()
// {
//   try
//   {
//     int radius;
//     cout << "Enter a radius." << endl;
//     cin >> radius;
//     if (radius < 0) {throw runtime_error("The radius cannot be negative."); }
//     cout << radius * pow(M_PI, 2);
//   }
//   catch(const exception& e)
//   {
//     cout << e.what() << '\n';
//   }
// }


 
int main()
{
  double temperature = 0;
  cout << "Enter a temperature : " << endl;
  cin >> temperature;
  try
  {
    if (temperature > 95)
    {         //below use built in function runtime_error 
            throw runtime_error("Exceptional temperature ");
    }
  }
  catch (runtime_error& ex)         //function catch needs a parameter refrence to throw
  {
        cout << ex.what();    //use what() meber function 
        cout << " It is too hot" <<endl;
        return 0;
  }

  return 0;
}

//test outputs for 10, 60, 120
