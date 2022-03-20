/*
Q1.Count the number of time the word 'the' is present in the file
*/

#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

int main()
{

	ifstream fp;
	string str;
	int count = 0;
	string word = "the" ;
	
	fp.open("data.txt");			//opening the data.txt file	
	
	if(!fp)			//In case file is not created
	{
		cout << "File doesnot exists." << endl;
	}
	
	else
	{
		while(fp >> str) 		//reading character by character
		{
			if (str == word)		// Checking word 'the'
			{
				count++;
			}
		}
		
		cout << "The number of time the word 'the' is present in the data.txt file is: " << count << endl;
	}
	
	fp.close();			//closing the opened file
	
	return 0;
}