//Jittapatana Prayoonpruk
//LAB5A
/****************************************************
Psudocode
GOAL: reading from input file and output to another output file

Each line has exactly 7 numbers, but don't know how many lines it has (use .eof())

for 0 to 7;
sum += num
Avg = sum / 7

set the initial num for min and max
if(j == 0)
min = num
max = num

if(num > max)
max = num

if(num < min)
min = num

****************************************************/

#include<iostream>
#include<string>
#include<fstream>  //do not forget this! (for file)
#include<iomanip>

using namespace std;

int main()
{
	ifstream inData;		//works like cin
	ofstream outData;		//works like cout
	int num, min, max, sum;
	float Avg;

	inData.open("DataFile.txt");
	if (!inData)
	{
		cout << "Cannot open file, terminating program." << endl;
		exit(1);
	}

	//This part don't necessary - this just print everything on the file to the output-file
	outData.open("OutputFile.txt");
	string str;
	while (!inData.eof())
	{
		getline(inData, str);
		outData << str << endl;
	}

	inData >> num;			//priming read, only use once

	outData << endl;
	inData.close();

	//Mark important
	inData.open("DataFile.txt");
	if (!inData)
	{
		cout << "Cannot open file, terminating program." << endl;
		exit(1);
	}

	inData >> num;			//priming read, only use once

	int i = 1;
	while (!inData.eof())   //read until the end of file
	{
		if (!inData.fail())  //checking input validation
		{
			sum = 0;
			for (int j = 0; j < 7; j++)  //run 7 number for each row
			{
				outData << num << " ";
				if (j == 0)
				{
					min = num;
					max = num;
				}
				else if (num < min)
				{
					min = num;
				}
				else if (num > max)
				{
					max = num;
				}
				sum += num;
				inData >> num;
			}
			outData << endl << endl;

			outData << "The sum of line " << i << " is: " << sum << endl;
			Avg = sum / 7.0;
			outData << "The average of the number for line " << i << " is " << fixed << setprecision(3) << Avg << endl;
			outData << "line number " << i << " has the lowest number is " << min << endl;
			outData << "line number " << i << " has the highest number is " << max << endl << endl;

			outData << endl;

			i++;
		}
		else  //Input invalid then the program error
		{
			inData >> num;
			outData << "invalid data/hardware error" << endl;
			exit(1);
		}
	}

	inData.close();

	outData.close();

	return 0;
}