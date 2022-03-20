/*
Q3.Count the number of words that end with 's'?
*/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
	ifstream fp;
	string str;
	int count=0;
	
	
	fp.open("data4.txt");		//opening the data4.txt file

	if(!fp)
	{
		cout << "File doesn't exists." << endl;
	}

	else
	{
		while(fp >> str)		//read from a file charcter by character
		{
			int n = str.length();			//getting length of string
			
			if(str[n-1] == 's' || str[n-1] == 'S')			//checking if last char is 's' or not
			{
				count++;			//counting no. of words
			}			
		}
		
		cout << "The number of words that end with 's' is: " << count << endl;
		
		
	}
	
	fp.close();			//closing the opened file
	
	return 0;
}