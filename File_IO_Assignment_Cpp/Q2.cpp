/*
Q2.Count the number of words that has 'a' in them?
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
	
	
	fp.open("data2.txt");		//opening the data2.txt file

	if(!fp)         //In case file is not created
	{
		cout << "File doesn't exists." << endl;
	}

	else
	{	
		while(fp >> str)		//reading character by character
		{
			int n = str.length();		//getting length of the string
			
			for(int i = 0; i < n;i++)		//checking for the words having 'a' in them
			{
				if(str[i] == 'a' || str[i] == 'A')
				{
					count++;			//count no. of words
					break;
				}
			}
			
		}
		
		cout << "The number of words that has 'a' in them is: "<< count << endl;
		
		
	}
	
	fp.close();			//closing the opened file
	
	return 0;
}