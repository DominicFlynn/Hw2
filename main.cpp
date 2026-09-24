#include <iostream>

using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];

	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const std::invalid_argument&)
			{
				if(i==1)
					cout << "(Invalid loan amount): " << argv[i] << endl;
				else if (i==2)
					cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
				else
					cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;
				return -2;
			}
			i++;
		}
	}

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	return 0;
	//****************************************************************************************************************************************** */
	// Beginning of added code for the HW 2 Assignment requirements

	// Check for negatives input values that would be impossible to give a correct output
	if (loan_amount <= 0 || yearly_interest_rate < 0 || monthly_payment <= 0) 
	{
		cout << "Error: Arguments must be positive values." << endl;
		return -3;
	}
	//Change our yearly_interest_rate into a decimal amount/percentage per month, a.k.a, our monthly_rate
	double monthly_rate = (yearly_interest_rate / 100.0) / 12.0;

	//Check in case the the monthly_payment will never be able to pay off the loan amount

	//Actual Execution of Monthly Balance, Interest, and Principle

	//Print of the Amorization Table

	


}
