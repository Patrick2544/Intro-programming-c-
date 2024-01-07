//Jittapatana Prayoonpruk
//LAB7B
/*
Main 
Read Data from DataFile
count data one by one, so we know how many data we have exactly
call all 4 functions

Funct 1:
Create Odd and Even Array using void

Funct 2:
Print odd and Even Array using void

Funct 3:
Find Min and Max
setting inital data for min and max
run for loop: if data < min then min = data
              else if data > max then max = data
and find average
setting sum = 0 then each loop sum += data
Average = sum / number of data

Funct 4:
Print all data that higher than average
run for loop: if data > Avergae then print data

*/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void CreateArray(int num, int& Count_Odd, int& Count_Even, int Odd_Array[], int Even_Array[]);
void PrintArray(int Count, int Array[]);
void FindMinMax_Avg(int& Min, int& Max, int Count, int Array[], float& Avg);
void NumHighThanAvg(int Count, int Array[], float Avg);

int main()
{
	int Num, CountOdd = 0, CountEven = 0, OddArray[50], EvenArray[50];
	int MaxOdd, MinOdd, MaxEven, MinEven;
	float AvgOdd, AvgEven;
	ifstream InData;

	InData.open("DataFile.txt");
	if (!InData)
	{
		cout << "Cannot open the file." << endl;
		exit(1);
	}

	InData >> Num;			//priming read

	while (!(InData.eof()))
	{
		if (!(InData.fail()))
		{
			CreateArray(Num, CountOdd, CountEven, OddArray, EvenArray);
			InData >> Num;
		}
		else
		{
			cout << "Data fail, terminating program." << endl;
			exit(1);
		}
	}

	FindMinMax_Avg(MinOdd, MaxOdd, CountOdd, OddArray, AvgOdd);
	FindMinMax_Avg(MinEven, MaxEven, CountEven, EvenArray, AvgEven);

	cout << "Even numbers have " << CountEven << " numbers: " << endl;
	PrintArray(CountEven, EvenArray);
	cout << "The Maximum number is: " << MaxEven << endl;
	cout << "The Minimum number is: " << MinEven << endl;
	cout << "The Average number is: " << fixed << showpoint << setprecision(2) << AvgEven << endl;
	cout << "Number higher than average is: " << endl;
	NumHighThanAvg(CountEven, EvenArray, AvgEven);
	cout << endl;
	cout << "Odd numbers have " << CountOdd << " numbers: " << endl;
	PrintArray(CountOdd, OddArray);
	cout << "The Maximum number is: " << MaxOdd << endl;
	cout << "The Minimum number is: " << MinOdd << endl;
	cout << "The Average number is: " << fixed << showpoint << setprecision(2) << AvgOdd << endl;
	cout << "Number higher than average is: " << endl;
	NumHighThanAvg(CountOdd, OddArray, AvgOdd);

	InData.close();
	return 0;
}
//End main************************************************

//Function 1: Create Odd and Even arrays
void CreateArray(int num, int& Count_Odd, int&Count_Even, int Odd_Array[], int Even_Array[])
{
	if (num % 2 == 0)
	{
		Even_Array[Count_Even++] = num;
	}
	else
	{
		Odd_Array[Count_Odd++] = num;
	}
}


//Function 2: Print Odd and Even numbers
void PrintArray(int Count, int Array[])
{
	for (int i = 0; i < Count; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

//Function 3: Finding Min, Max, and Average for each Odd and Even
void FindMinMax_Avg(int& Min, int&Max, int Count, int Array[], float& Avg)
{
	float sum = 0.0;
	Max = Array[0];
	Min = Array[0];

	for (int i = 0; i < Count; i++)
	{
		if (Array[i] < Min)
		{
			Min = Array[i];
		}
		else if (Array[i] > Max)
		{
			Max = Array[i];
		}
		sum += Array[i];
	}
	Avg = sum / Count;
}

//Function 4: Print all numbers that higher than the Average
void NumHighThanAvg(int Count, int Array[], float Avg)
{
	for (int i = 0; i < Count; i++)
	{
		if (Array[i] > Avg)
		{
			cout << Array[i] << " ";
		}
	}
	cout << endl;
}