#include <iostream>
#include <iomanip>
#include <string>

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

	if(argc < 4)
	{
		cout << "Too few arguments. Must provide the loan amount, interest, and monthly payment to continue." << endl;
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

double first_month_interest = loan_amount * monthly_rate;

if (monthly_payment <= first_month_interest)
{
    cout << "Error: Monthly payment is too small to pay off the loan." << endl;
    return -4;
}

double balance = loan_amount;
double total_interest_paid = 0.0;
int months = 0;
cout <<"********************************************************************" << endl;
cout << "\tAmortization Table"<< endl;
cout <<"********************************************************************" << endl;
	
cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal" << endl;

cout << "0\t$"
     << fixed << setprecision(2) << balance
     << "\t\tN/A\tN/A\tN/A\t\tN/A"
     << endl;

while (balance > 0)
{
    months++;

    double current_interest = monthly_rate * balance;
    double principal = monthly_payment - current_interest;

    if (principal > balance)
    {
        principal = balance;
    }

    double actual_payment = principal + current_interest;

    balance -= principal;
    total_interest_paid += current_interest;

    if (balance < 0.0001)
    {
        balance = 0.0;
    }

    cout << months
		<< "\t$" << fixed << setprecision(2) << balance
         << "\t\t$" << actual_payment
         << "\t" << defaultfloat << yearly_interest_rate / 12.0
         << "\t$" << fixed << setprecision(2) << current_interest
         << "\t\t$" << principal
         << endl;
}
	
cout <<"********************************************************************" << endl;
	cout<< "It takes "<< months<<" months to pay off the loan."<<endl;
	cout<<"Total interest paid is: $"<<total_interest_paid<<endl; 
}
