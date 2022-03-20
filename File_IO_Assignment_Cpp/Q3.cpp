/*
Q3.Count the number of words that start with 'e'?
*/

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	ifstream fp;
	string str;
	int count=0;
	
	
	fp.open("data3.txt");		//opening the data3.txt file

	if(!fp)         //In case file is not created
	{
		cout << "File doesn't exists." << endl;
	}

	else
	{
		while(fp >> str)		//reading in a file character by character
		{
			if(str[0] == 'e' || str[0] == 'E')			//checking if 1st char is 'e' or not
			{
				count++;			//counting no. of words
			}			
		}
		
		cout << "The number of words that start with 'e' is: " << count << endl;
		
		
	}
	
	fp.close();			//closing the opened file
	
	return 0;
}