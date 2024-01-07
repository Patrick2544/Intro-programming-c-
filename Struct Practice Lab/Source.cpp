//Jittapatana Prayoonpruk
//LAB8A

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;


struct TypeArr
{
	string IdenCode;
	float Income;
	int NumMember;
};

//Function prototype
void Menu(char& CaseType);
void PrintAllInfo(TypeArr Struct_Arr[], int Size_Data);
void CalcAvgIncome(TypeArr Arr_Struct[], int Size__Of_Data, float& Avg_Income);
void PovertyLevel(TypeArr Struct_Array[], int SizeOfData);
void CreateCopyArr(TypeArr Struct_Of_Arr[], TypeArr Copy_Struct[], int Size);
void swap(double& First_Element, double& Second_Element);
void bubbleSort(TypeArr Copy_StructArr[], int Size_Of_Arr);
void CalcMedianIncome(TypeArr Copy_Struct_Arr[], int Si_ze);



int main()
{
	ifstream Indata;
	TypeArr StructArr[50], CopyStructArr[50];
	int SizeData = 0;
	char CaseType;
	float AvgIncome = 0;

	Indata.open("DataFile.txt");
	if (!Indata)
	{
		cout << "Cannot open file, terminating program.";
		exit(1);
	}

	Indata >> StructArr[SizeData].IdenCode;
	Indata >> StructArr[SizeData].Income;
	Indata >> StructArr[SizeData].NumMember;

	while (!(Indata.eof()))
	{
		SizeData++;
		Indata >> StructArr[SizeData].IdenCode;
		Indata >> StructArr[SizeData].Income;
		Indata >> StructArr[SizeData].NumMember;
		
	}


	//Actual started program here

	CreateCopyArr(StructArr, CopyStructArr, SizeData);
	bubbleSort(CopyStructArr, SizeData);

	do
	{
		Menu(CaseType);
		cout << "Case: " << CaseType << endl;
		switch (CaseType)
		{
		case 'A':
			PrintAllInfo(StructArr, SizeData);
			cout << endl;
			break;

		case 'B':
			CalcAvgIncome(StructArr, SizeData, AvgIncome);
			cout << endl;
			break;

		case 'C':
			PovertyLevel(StructArr, SizeData);
			cout << endl;
			break;

		case 'D':
			PrintAllInfo(CopyStructArr, SizeData);
			cout << endl;
			break;

		case 'E': 
			CalcMedianIncome(CopyStructArr, SizeData);
			cout << endl;
			break;

		case 'F':
			cout << "The program is finished, terminating program." << endl;
			break;

		default: 
			cout << "Sorry the option does not match, please try again." << endl << endl;
			break;
		}

	} while (CaseType != 'F');

	Indata.close();

	return 0;
}
//End main********************************************************

void Menu(char& CaseType)
{
	cout << " Menu" << endl;
	cout << " A : Print all of data." << endl;
	cout << " B : Print list of households whose income is greater than the average." << endl;
	cout << " C : Print the percentage of household having an income below the property level." << endl;
	cout << " D : Print all of the input data sorted by households income." << endl;
	cout << " E : Print the median household income." << endl;
	cout << " F : Exit program." << endl << endl;
	cout << " Enter your choice: ";
	cin >> CaseType;
	CaseType = toupper(CaseType);
}

//CASE A:
void PrintAllInfo(TypeArr Struct_Arr[], int Size_Data)
{
	cout << "Identical code\tAnnual income\t\tMembers" << endl;
	for (int i = 0; i < Size_Data; i++)
	{
		cout << " " << Struct_Arr[i].IdenCode << "\t\t";
		cout << " " << fixed << showpoint << setprecision(2) << Struct_Arr[i].Income << "\t\t";
		cout << " " << Struct_Arr[i].NumMember << "\t";
		cout << endl;
	}
}

//CASE B:
void CalcAvgIncome(TypeArr Arr_Struct[], int Size__Of_Data, float& Avg_Income)
{
	for (int i = 0; i < Size__Of_Data; i++)
	{
		Avg_Income += Arr_Struct[i].Income;
	}
	Avg_Income /= Size__Of_Data;

	cout << "The average income is: " << fixed << showpoint << setprecision(2) << Avg_Income << endl;
	cout << "List of households whose income greater than the average: " << endl;
	cout << "Identical code\tIncome" << endl;

	for (int i = 0; i < Size__Of_Data; i++)
	{
		if (Avg_Income < Arr_Struct[i].Income)
		{
			cout << " " << Arr_Struct[i].IdenCode << "\t\t" << fixed << showpoint << setprecision(2) << Arr_Struct[i].Income << endl;
		}
	}
}

//CASE C:
void PovertyLevel(TypeArr Struct_Array[], int SizeOfData)
{
	int Poverty, CountPercent = 0;
	float Percentage;

	for (int i = 0; i < SizeOfData; i++)
	{
		Poverty = 8000 + (500 * (Struct_Array[i].NumMember - 2));
		if (Struct_Array[i].Income < Poverty)
		{
			CountPercent++;
		}
	}
	Percentage = (CountPercent * 100.0) / SizeOfData;
	cout << "The percentage of households having an income below the poverty level is: ";
	cout << fixed << showpoint << setprecision(2) << Percentage << "% " << endl;
}

//CASE D:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//make the duplicate of StructArray and sort its income. CASE D: use print all info functc from case A.
void CreateCopyArr(TypeArr Struct_Of_Arr[], TypeArr Copy_Struct[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Copy_Struct[i] = Struct_Of_Arr[i];
	}
}

//bubble sort: code from internet
void swap(double& First_Element, double& Second_Element)
{
	double temp = First_Element;
	First_Element = Second_Element;
	Second_Element = temp;
}

void bubbleSort(TypeArr Copy_StructArr[], int Size_Of_Arr)
{
	int i, j;
	bool swapped;
	for (i = 0; i < Size_Of_Arr - 1; i++)
	{
		swapped = false;
		for (j = 0; j < Size_Of_Arr - i - 1; j++)
		{
			if (Copy_StructArr[j].Income > Copy_StructArr[j + 1].Income)
			{
				swap(Copy_StructArr[j].Income, Copy_StructArr[j + 1].Income);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//CASE E:
void CalcMedianIncome(TypeArr Copy_Struct_Arr[], int Si_ze)
{
	float Median;
	int Middle;
	Middle = Si_ze / 2;
	if (Si_ze % 2 == 0)
	{
		Median = (Copy_Struct_Arr[Middle].Income + Copy_Struct_Arr[Middle - 1].Income) / 2;
	}
	else
		Median = Copy_Struct_Arr[Middle - 1].Income;

	cout << "The median of households income is: " << fixed << showpoint << setprecision(2) << Median << endl;
}