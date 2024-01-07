//Jittapatana Prayoonpruk
//LAB4D

/*************************************
Pseudocode
This program will calulate the amount of caffeine in the body X hours after the person drinks the coffee.
After caffeine is absorbed into the body, 13% is eliminated from the body each hour.

NOTE:
BE SURE TO INCLUDE ADEQUATE ERROR HANDLING.
Ask users to reprogram or exit.
Caffeine must not be greater than 350.
hours must be a positive number not greater than 14.
Remember to set the precision to something reasonable.

input:
The Type of Drink
The Amount of Caffeine
The Number of Hours

Checking:

Check The Amount of Caffeine Until it satisfied the conditions. ( < 0 amd <= 350 )

Check The Numbers of Hours Until it satisfied the conditions. ( < 0 and <= 14 )

Check user to do it again. If user want to do again then reprogram otherwise end program.

Calculation:
 13% is eliminated from the body each hour.
 The Alternative way - eliminated 13% that means 100-13 = 87%
 The amount of caffeine on X hours * 0.87 = The amount of caffeine on X-1 hours
 Caution:
 DO NOT SUBTRACT WITH THE SAME AMOUNT EACH HOUR THE PERCENTAGE OF AMOUNT OF CAFFINE
 IS NOT THE SAME, SO THE NUMBER WE HAVE TO ELIMINATED WILL NOT BE THE SAME!!

Output:
Type of drink
The Amount of Caffeine
Show How many caffeine left for each hour.

*************************************/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
int main()
{
	string TypeOfDrink;
	const float ElimPerHour = 0.87;
	float AmountOfCaff, NumHours, CaffLeft;
	bool Redo = true;
	char Exit;

	cout << fixed << showpoint << setprecision(2);

	while (Redo)
	{
		cout << "Please enter your type of drink : ";
		getline(cin, TypeOfDrink); //User can type any think included space.
		cout << "Your type of drink : " << TypeOfDrink;

		//do-while loop for the Amount of caffeine.
		do
		{
			cout << "\nPlease enter the amount of caffeine : ";
			cin >> AmountOfCaff;
		// Validatiing input checking for the amount of caffeine.
		while(cin.fail())
		{
			//clear buffer
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry the input is impossible for the amount of caffeine. \nplease enter the amount of caffeine : ";
			cin >> AmountOfCaff;
		}
		if(AmountOfCaff < 0)
		{
			//Just sent the message to the output screen.
			cout << "Sorry the amount of caffeine cannot be zero or less than.";
		}
		if (AmountOfCaff > 350)
		{
			//Just sent the message to the output screen.
			cout << "Sorry the amount of caffeine must not greater than 350";
		}
		} while (AmountOfCaff < 0 || AmountOfCaff > 350); //while this true then redo the loop.

		cout << "The amount of caffeine in your drink : " << AmountOfCaff << endl;
		//loop of The amount of caffeine end

		//If your body has amount of caffeine then do this
		if(AmountOfCaff > 0)
		{
			//do-while loop for the number of hours
			do
			{
				cout << "\nPlease enter the number of hours : ";
				cin >> NumHours;
				// Validatiing input checking for the number of hours
				while (cin.fail())
				{
					//clear buffer
					cin.clear();
					cin.ignore(200, '\n');
					cout << "Sorry input is impossible for the number of hours. \nplease enter the number of hours : ";
					cin >> NumHours;
				}
				if (NumHours <= 0)
				{
					//Just sent the message to the output screen
					cout << "Sorry the number of hours must be a positive number";
				}
				if (NumHours > 14)
				{
					//Just sent the message to the output screen
					cout << "Sorry the number of hours must not greater than 14";
				}
			} while (NumHours <= 0 || NumHours > 14); //while this ture then redo the loop.
			//loop of the number of hours end

			cout << TypeOfDrink << " " << AmountOfCaff << " mg\tshow " << NumHours << " hours\n";
			//calculation part:
			int AfterHour = 0;
			for (int i = NumHours; i >= 1; i--)
			{
				AfterHour++; //runing the output after 1, 2, 3, ... hours
				CaffLeft = AmountOfCaff * 0.87;
				cout << "Your caffeine in your boday after " << AfterHour << " hours : " << CaffLeft << endl;
				AmountOfCaff = CaffLeft;
			}
		}
		else // case caffeine in your body 
		{
			cout << "\nYou do not have amount of caffeine in your body. Thank you.\n";
		}

		//Ask users to redo the program
		cout << "\nDo you have others type of drink?\n";
		cout << "If you want to continue the program please type 'Y' otherwise type any character to exit the program\n";
		cin >> Exit;
		Exit = toupper(Exit); //sensitive case
		if (Exit != 89) //89 is equivalent to 'Y' in ASCII code
		{
			Redo = false;
		}
		cin.ignore(); //clear input buffer for redo the program.
	}

	return 0;
}

