/*
Q5.Write a cpp program that shows a menu:
1: enter student detail
2: find student

Note: Make sure to use exception handling concepts here and think of
what could go wrong and put proper try-throw-catch setup in place.
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>


using namespace std;

class student
{
	public:
	
	int id;
	string name, branch, location;

	void getDetails()			//function to get student details from stdin
	{
	
		cout << "Enter id, name, branch, location" << endl;
		
		cout << "id: ";
		cin >> id;
		
		cout << "name: ";
		cin >> name;
		
		cout << "branch: ";
		cin >> branch;
		
		cout << "location: ";
		cin >> location;

	}
	
	void addDetails()			//write the data to file
	{
		fstream fp;
		student stud;

		fp.open("student_record.txt", ios::app|ios::binary);
		
		stud.getDetails();			//take input student data

		fp.write((char *) &stud, sizeof(stud));

		fp.close();
		
	}
	
	
	void findStud()			//function to find student
	{
		int sid, count=0;
		fstream fp;
		student stud;

		int f = 0;		//flag to indicate if user found or not
		
		cout << "Enter the student id" << endl;
		cin >> sid;

		fp.open("student_record.txt", ios::in|ios::binary);

		//count total entries in file
		while(!fp.eof())
		{
			fp.read((char *) &stud, sizeof(stud));
			count++;
		}
		
		fp.close();

		
		//displaying stud details if found
		fp.open("student_record.txt", ios::in|ios::binary);

		for(int i = 0; i < count-1; i++)
		{
			fp.read((char *) &stud, sizeof(stud));

			if(sid == stud.id)
			{
				cout << "\nstudent id matched\n" << endl;
				cout << "Id number: " << stud.id << endl;
				cout << "Name: " << stud.name << endl;
				cout << "Branch: " << stud.branch << endl;
				cout << "Location: " << stud.location << endl;
				f = 1;
			}
			
		}
		
		if(!f)
			cout << "Student Not Found\n" << endl;
				
		fp.close();	
	}

};	//end of class



int main()
{
	
	int count=0;
	char opt;
	int flag = 1;
	student s1;
	
	
	//menu driven operation
	try				//using exception handling
	{
		
		while(flag)
		{
			//displaying menu
			cout << "\nSelect the operation you want to perform : \n1. Enter Student Details\n2. Find Student\n3. Exit" << endl;
	
		
			cin >> opt;
			
			if(isalpha(opt))		//check for aplhabet entry
			{
				throw -1;
			}

			else
			{
				switch(opt)
				{
					case '1':
					s1.addDetails();
					break;
					
					case '2':
					s1.findStud();
					break;
					
					case '3':
					flag = 0;
					break;
					
					default:
					cout << "Invalid Option\nTry Again" << endl;
					break;
				}
			}
		
		
		}
		
		
	}
	
	catch(int a)
		{
			cout << "Not a number\nPlease enter a number only" << endl;
		}
		
	return 0;
}