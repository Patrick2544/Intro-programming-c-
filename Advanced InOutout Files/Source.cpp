//Jittapatana Prayoonpruk
//LAB6C
/*********************************
Pseudocode

Main Funct:
open-close all files
read until the end of file
call all 4 functs

Function 1:
use void - checking for error
read each data
if error, then output on ErrorFile
If not continue

Function 2:
use float - return Cost of Meal

Function 3:
use void - Pass by referneces value (&) for Tips and Taxes, and Surcharge

Function 4:
use void - output everything on OutputFile

**********************************/
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

//Function prototype
void InputData(int& Party_ID, int& Num_Adults, int& Num_Child, char& Meal_Type, char& Week_End, float& De_posit, bool& Error, ifstream& In_Data, ofstream& Error_File);
float CalCostMeal(int AdultsNum, int ChildNum, char TypeMeal);
void TipTaxAndSurcharge(float CostMeal, char WEnd, float& Tip_And_Tax, float& Sur_Charge);
void OutputScreen(ofstream& Out_Data, int PID, int N_Adults, int N_Child, float Meal_Cost, float T_And_T, float Surcharge_Cost, float Dep_osit);

int main()
{
	int PartyID, NumAdults, NumChild;
	char MealType, WeekEnd;
	bool Error;
	float Deposit, TotalCostMeal, TipTax, Surcharge;
	ifstream InData;				//works like cin (Read)
	ofstream ErrorFile, OutData;	//work like cout (write)

	InData.open("DataFile.txt");
	OutData.open("OutputFile.txt");
	ErrorFile.open("ErrorFile.txt");
	
	while(!(InData.eof()))
	{
		
		Error = false;
		//Call Function 1
		InputData(PartyID, NumAdults, NumChild, MealType, WeekEnd, Deposit, Error, InData, ErrorFile);
		if (!Error)
		{
			//Assign function 2 to TotalCostMeal
			TotalCostMeal = CalCostMeal(NumAdults, NumChild, MealType);  

			//Call function 3
			TipTaxAndSurcharge(TotalCostMeal, WeekEnd, TipTax, Surcharge);

			//Call function 4
			OutputScreen(OutData, PartyID, NumAdults, NumChild, TotalCostMeal, TipTax, Surcharge, Deposit);
		}
	}

	InData.close();
	OutData.close();
	ErrorFile.close();

	return 0;
}
//End main**************************************


//Function 1: Read data from DataFile, and output the errors to the ErrorFile
void InputData(int& Party_ID, int& Num_Adults, int& Num_Child, char& Meal_Type, char& Week_End, float& De_posit, bool& Error, ifstream& In_Data, ofstream& Error_File)
{
	if (In_Data.fail())
	{
		Error_File << "Cannnot open the file" << endl;
	}

	In_Data >> Party_ID;
	if (Party_ID <= 0)
	{
		Error_File << Party_ID << "\tThis Party ID is incorrect" << endl;
		Error = true;
	}

	In_Data >> Num_Adults;
	if (Num_Adults < 0)
	{
		Error_File << Num_Adults << "\tThis adults number is incorrect" << endl;
		Error = true;
	}

	In_Data >> Num_Child;
	if (Num_Child < 0)
	{
		Error_File << Num_Child << "\tThis children number is incorrect" << endl;
		Error = true;
	}

	Meal_Type = toupper(Meal_Type);
	In_Data >> Meal_Type;
	if (!(Meal_Type == 'S' || Meal_Type == 'D'))
	{
		Error_File << Meal_Type << "\tThis meal type is incorrect" << endl;
		Error = true;
	}

	Week_End = toupper(Week_End);
	In_Data >> Week_End;
	if (!(Week_End == 'Y' || Week_End == 'N'))
	{
		Error_File << Week_End << "\tThe weekend information is incorrect" << endl;
		Error = true;
	}

	In_Data >> De_posit;
	if (De_posit < 0)
	{
		Error_File << De_posit << "\tThis number of deposit is incorrect" << endl;
		Error = true;
	}
}

//Function 2: Calculate cost of meal
float CalCostMeal(int AdultsNum, int ChildNum, char TypeMeal)
{
	const float STD_Cost = 21.75;
	const float Delux_Cost = 25.80;
	const float Child_STD_Cost = 13.05;		//21.75*0.6
	const float Chile_Delux_Cost = 15.48;	//25.80*0.6

	if (TypeMeal == 'S')
	{
		return ((STD_Cost * AdultsNum) + (Child_STD_Cost * ChildNum));			//return the total of standard meal
	}
	else
	{
		return ((Delux_Cost * AdultsNum) + (Chile_Delux_Cost * ChildNum));		//return the total of deluxe meal
	}
}

//Function 3: Calculate Tips and Taxes, and Surcharge
void TipTaxAndSurcharge(float CostMeal, char WEnd, float& Tip_And_Tax, float& Sur_Charge)
{
	float RateTipTax = 0.18;
	Sur_Charge = 0;

	Tip_And_Tax = CostMeal * RateTipTax;

	if (WEnd == 'Y')   //if weekend true, calculate the surcharge
	{
		Sur_Charge = (CostMeal + Tip_And_Tax) * 0.07;
	}
}

//Function 4: Output everything to the output file
void OutputScreen(ofstream& Out_Data, int PID, int N_Adults, int N_Child, float Meal_Cost, float T_And_T, float Surcharge_Cost, float Dep_osit)
{
	float Total, TotalBalance;

	//Total (Meal + Taxes + Surcharge)
	Total = Meal_Cost + T_And_T + Surcharge_Cost;

	//calulate Total Balance
	if (Total > Dep_osit)
	{
		TotalBalance = Total - Dep_osit;
	}
	else
	{
		TotalBalance = Dep_osit - Total;
	}
	
	//output to the OutputFile
	Out_Data << "Bill" << endl;
	Out_Data << "Party ID:\t\t" << PID << endl;
	Out_Data << "Adults: \t\t" << N_Adults << endl;
	Out_Data << "Children: \t\t" << N_Child << endl;
	Out_Data << "Cost of Meals: \t\t" << fixed << showpoint << setprecision(2) << Meal_Cost << endl;
	Out_Data << "SurCharge: \t\t" << Surcharge_Cost << fixed << showpoint << setprecision(2) << endl;
	Out_Data << "Tips and Taxes: \t" << fixed << showpoint << setprecision(2) << T_And_T << endl;
	Out_Data << "Deposit: \t\t" << fixed << showpoint << setprecision(2) << Dep_osit << endl;
	Out_Data << "Total Cost: \t\t" << fixed << showpoint << setprecision(2) << Total << endl;
	Out_Data << "Total Balance Due: \t" << fixed << showpoint << setprecision(2) << TotalBalance << endl << endl;
}