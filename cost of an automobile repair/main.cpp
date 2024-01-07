//Jittapatana Prayoonpruk
//LAB2C

/*****************************************
Pseudocode
This program will calculate the total cost of an automobile repair.

Rate:
		Labor charges			= $35/hour
		Tax on parts and supplies	= 9%

Input:
		Customer's name
		The number of hours
		The cost of parts and supplies

Calculation:
		Cost of Labor = Number of hours * Labor charges
		Tax = Cost of part and supplies * 9%
		Total Amount Due = Cost of Labor + Parts and supplies + Tax

Output:
		Customer's name
		Hours of Labor
		Cost of Labor
		Parts and supplies
		Tax
		Total Amount Due

*****************************************/
#include<iostream>
#include<iomanip>	// <--- for setting the decimals
#include<string>

using namespace std;

int main()
{
	float const LaborCharges = 35, TaxOnSupplies = 0.09;
	string name;
	float NumHours, CostSupplies, CostLabor, Tax, TotalAmount;

	//input part:
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Hello! " << name << endl;
	cout << "Please enter the amount of hours: ";
	cin >> NumHours;
	cout << "The hours of work: " << NumHours << endl;
	cout << "Please enter the cost of parts and supplies: $";
	cin >> CostSupplies;
	cout << "Cost of parts and supplies: $" << CostSupplies << endl << endl << endl;

	//Calculation part:
	CostLabor = NumHours * LaborCharges;
	Tax = CostSupplies * TaxOnSupplies;
	TotalAmount = CostLabor + CostSupplies + Tax;

	//output part:
	cout << fixed << showpoint << setprecision(2); //setting output to show 2 decimal points.
	cout << "   Costomer's name     " << name << endl;
	cout << "   Hours of Labor      " << NumHours << endl;
	cout << "   Cost of Labor       " << CostLabor << endl;
	cout << "   Parts and Supllies  " << CostSupplies << endl;
	cout << "   Tax                 " << Tax << endl;
	cout << "   Total Amount Due    " << TotalAmount << endl;
	return 0;
}

/*
Output
Please enter your name: Jones
Hello! Jones
Please enter the amount of hours: 4.5
The hours of work: 4.5
Please enter the cost of parts and supplies: $97
Cost of parts and supplies: $97


   Costomer's name     Jones
   Hours of Labor      4.50
   Cost of Labor       157.50
   Parts and Supllies  97.00
   Tax                 8.73
   Total Amount Due    263.23

C:\Users\Jittapatana\source\repos\TEST\Debug\TEST.exe (process 16956) exited with code 0.
Press any key to close this window . . .

*/
