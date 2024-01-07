//Jittapatana Prayoonpruk
//LAB3C

/**************************************
Pseudocode
This program will calculate a customer's monthly bill.

Package A	$9.95 per 10 Hours	Addition $2.00 per hours
Package B	$14.95 per 20 hours	Addition $1.00 per hours
Package C	$19.95 per month	Limited access

Input:
Package purchased (A, B, C)
Hours were used

Checking:

If: package != A, B or C
then end program

If: Hours exceed 200
then end program

calculuation:

Package A
if: Hours were used > 10
then Total = 9.95 + ( (Hours were used - 10) * 2.00 )
else: Total = 9.95

**Extra credit**
if: Hours were used == 30 for package A
then switch to package C will save $30

Package B
if: Hourse were used > 20
then Total = 14.95 + ( (Hours were used - 20) * 1.00 )
else: Total = 14.95

Package C
Total = 19.95

Output:
Package purchased
Number of Hours used
The Base Charge
The Hourly Charges
The Total Bill

***************************************/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int NumHours;
	char TypePackage;
	float TotalBill, HourlyCharges, BaseCharge;
	bool exit = false;

	cout << "Which package you have purchased? (Please type with a sigle character): ";
	cin >> TypePackage;
	TypePackage = toupper(TypePackage);  //sensitive case
	//Type of package Checking 
	if (!(TypePackage == 'A' || TypePackage == 'B' || TypePackage == 'C'))
	{
		exit = true;
		/*
		caution: DO NOT DO THIS!!
		if (TypePackage != 'A' || TypePackage != 'B' || TypePackage != 'C')
		This is a logical error
		*/
	}
	//If type of package does match the condition then contiue otherwise end program.
	if (!(exit))
	{
		cout << "Your package is package " << TypePackage << endl;
		cout << "How many hours you have used for this month? : ";
		cin >> NumHours;
		//Number of Hours cannot exceed 200
		if (NumHours > 200)
		{
			exit = true;
		}
		//If hours do not exceed then continue otherwise end program
		if (!(exit))
		{
			cout << "Your hours used : " << NumHours << endl;
			if (TypePackage == 'A')
			{
				BaseCharge = 9.95;
				if (NumHours > 10)
				{
					HourlyCharges = (NumHours - 10) * 2;
					TotalBill = BaseCharge + HourlyCharges;
				}
				else
				{
					HourlyCharges = 0;
					TotalBill = BaseCharge;
				}

			}
			else if (TypePackage == 'B')
			{
				BaseCharge = 14.95;
				if (NumHours > 20)
				{
					HourlyCharges = NumHours - 20;
					TotalBill = BaseCharge + HourlyCharges;
				}
				else
				{
					HourlyCharges = 0;
					TotalBill = BaseCharge;
				}
			}
			else //When TypePackage == 'C'
			{
				BaseCharge = 19.95;
				HourlyCharges = 0;
				TotalBill = BaseCharge;
			}
			//output part:
			cout << fixed << showpoint << setprecision(2); //set output to show 2 decimal points.
			cout << "Package " << TypePackage << ", usage " << NumHours << " hours\t" << "Bill\n";
			cout << "\t   Base Charge:         " << BaseCharge << endl;
			cout << "\t   Hourly Charge:       " << HourlyCharges << endl;
			cout << "\t   Total:               " << TotalBill << endl;
			//Extra credit
			if (TypePackage == 'A' && NumHours == 30)
			{
				cout << "**You will save $30 by switching to package C**\n";
			}
		}
		else //end program from hours exceed 200
		{
			cout << "Sorry we do not allow the number of usage exceed 200" << endl;
		}

	}
	else  //end program from type of package does not match.
	{
		cout << "Sorry we do not provide this type of package" << endl;
		cout << "Please try again later" << endl;
	}

	return 0;
}

/*
Output:
Which package you have purchased? (Please type with a sigle character): a
Your package is package A
How many hours you have used for this month? : 30
Your hours used : 30
Package A, usage 30 hours       Bill
		   Base Charge:         9.95
		   Hourly Charge:       40.00
		   Total:               49.95
**You will save $30 by switching to package C**

C:\Users\Jittapatana\source\repos\TEST\Debug\TEST.exe (process 1880) exited with code 0.
Press any key to close this window . . .

*/
