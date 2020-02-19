//------------------------------------------------------------------------------------------------------------------------------------
//inVal
//This program will accept the name, zip code and employee id.
//The program will also output a list of errors to html file named errors.
//written by James Gouveia 4/13/16 Version 1.0
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

//create a structure to hold the inputed data
struct user
{
	string fname;
	string lname;
	string zip;
	string emp_id;
};

//function prototype
void show_intro();
int validateInput();
int validation_fname(string fname);
int validation_lname(string lname);
int validation_zip(string zip);
int validation_num(string dynamicuser);
void show_output();

//BONUS BONUS! programmer defined feature, declare global vectors used to hold the actual error data for output to the html error file
vector<string> fname_errors_log;
vector<string> lname_errors_log;
vector<string> zip_errors_log;
vector<string> emp_errors_log;


int main()
{
	//a short intro to the program
	show_intro();

	//This function accepts the user's input and calls other functions to validate the data
	validateInput();

	//This function will create the html file "error"
	show_output();
}

void show_intro()
{
	cout << "This program will accept the name, zip code and employee id provided by the user." << endl;
}

int validateInput()
{
	//declare flags to keep track of any errors
	int fname_error_flag;
	int lname_error_flag;
	int zip_error_flag;
	int emp_error_flag;

	//creates a variable used to create a dynamic structure
	cout << "Please enter the number of users that you would like to save data for." << endl;
	int number;
	cin >> number;

	//Pointer
	user * dynamicuser = new user[number];

	//for loop that accepts the user's input based on how many employees the user would like to enter
	for (int n = 0; n != number; n++)
	{
		cout << "Enter the user's first name: " << endl;
		cin >> dynamicuser[n].fname;

		//calls first name validation function
		fname_error_flag = validation_fname(dynamicuser[n].fname);

		//BONUS BONUS! checks for error and if found adds them to the appropriate vector
		if (fname_error_flag > 0)
			fname_errors_log.push_back(dynamicuser[n].fname);
	
		

		cout << "Enter the user's last name: " << endl;
		cin >> dynamicuser[n].lname;
		
		//calls last name validation function
		lname_error_flag = validation_lname(dynamicuser[n].lname);

		//BONUS BONUS! checks for error and if found adds them to the appropriate vector
		if (lname_error_flag > 0)
			lname_errors_log.push_back(dynamicuser[n].lname);
		
	
		cout << "Enter the user's zip code: " << endl;
		cin >> dynamicuser[n].zip;

		//calls zip validation function
		zip_error_flag = validation_zip(dynamicuser[n].zip);

		//BONUS BONUS! checks for error and if found adds them to the appropriate vector
		if (zip_error_flag > 0)
			zip_errors_log.push_back(dynamicuser[n].zip);
	

		cout << "Enter the user's employer ID: " << endl;
		cin >> dynamicuser[n].emp_id;

		//calls employee id validation function
		emp_error_flag = validation_num(dynamicuser[n].emp_id);

		//BONUS BONUS! checks for error and if found adds them to the appropriate vector
		if (emp_error_flag > 0)
			emp_errors_log.push_back(dynamicuser[n].emp_id);

	};

	return 0;
}

int validation_fname(string fname)
{
	//checks the length of the input
	int flag = 0;
	if (fname.length() < 2)
		{
		cout << "invalid input, first name must be at least 2 alpha characters long." << endl;
		flag = 1;
		}

	//checks that the input is alpha characters
	for (int o = 0; o < 2; o++)
			{
				bool flag_alpha = isalpha(fname[o]);
				if (flag_alpha < 1)
					{
					cout << "Invalid input, first name must be at least 2 alpha characters long." << endl;
					return 1;
					};	
			};

	return flag;
}

int validation_lname(string lname)
{
	//checks the length of the input
	int flag = 0;
	if (lname.length() < 2)
		{
		cout << "invalid input, last name must be at least 2 charachers long." << endl;
		flag = 1;
		}

	//checks that the input is alpha characters
	for (int v = 0; v < 2; v++)
			{
				bool flag_alpha = isalpha(lname[v]);
				if (flag_alpha < 1)
					{
					cout << "Invalid input, last name must be at least 2 charachers long." << endl;
					return 1;
					};	
			};

	return flag;
}

int validation_zip(string zip)
{
	//checks the length of the input
	int flag = 0;
	if (zip.length() != 5)
		{
		cout << "invalid input, the zip code must be 5 digits." << endl;
		flag = 1;
		};
	
	//checks that the input is alpha characters
	for (int w = 0; w < 5; w++)
			{
				bool flag_digit = isdigit(zip[w]);
				if (flag_digit < 1)
					{
					cout << "Invalid input, the zip code must be 5 digits." << endl;
					return 1;
					};
			};


	return flag;
}

void show_output()
{

	//creates a file named errors.htm and opens a file named myfile
	ofstream myfile;
	myfile.open("errors.htm", ios:: out);
	//format the html doc and output the error log
	myfile << "<DOCTYPE html>\n" 
	       << "<html>\n"
	       << "<title>Error Log!</title>\n"
		   << "<style>\n body{background-color:green;}\n p {color:red;}\n</style>"
	       << "<body>\n"
	       << "<h1> The number of first name errors:  "
	       << fname_errors_log.size() << endl;
	myfile << "\n</h1><br>"
	       << "\nHere is a list of user typed first name errors.<br>" << endl;

	int size_fname_error = fname_errors_log.size();

	//BONUS BONUS! Programmer defined bonus, display the actual incorrect data in the html file for later analysis
	for (int n = 0; n < size_fname_error; n++)
	{
		myfile << fname_errors_log[n] << endl;
		myfile << "<br>" << endl;
		        
	};

	myfile << "<h1><br> The number of last name errors:  "
	       << lname_errors_log.size() << endl;
	myfile << "\n</h1><br>"
	 << "<br>Here is a list of user typed last name errors.<br>" << endl;

	int size_lname_error = lname_errors_log.size();

	//BONUS BONUS! Programmer defined bonus, display the actual incorrect data in the html file for later analysis
	for (int x = 0; x < size_lname_error; x++)
	{
		myfile << lname_errors_log[x] << endl;
		myfile << "<br>" << endl;
		        
	};

	myfile << "<h1><br> The number of zip errors:  "
	       << zip_errors_log.size() << endl;
	myfile << "\n</h1><br>"
	 << "<br>Here is a list of user typed zip errors.<br>" << endl;

	int size_zip_error = zip_errors_log.size();

	//BONUS BONUS! Programmer defined bonus, display the actual incorrect data in the html file for later analysis
	for (int x = 0; x < size_zip_error; x++)
	{
		myfile << zip_errors_log[x] << endl;
		myfile << "<br>" << endl;
		        
	};

	myfile << "<h1><br> The number of employee id errors:  "
	       << emp_errors_log.size() << endl;
	myfile << "\n</h1><br>"
	 << "<br>Here is a list of user typed employee id errors.<br>" << endl;

	int size_emp_error = emp_errors_log.size();

	//BONUS BONUS! Programmer defined bonus, display the acutal incorrect data in the html file for later analysis
	for (int e = 0; e < size_emp_error; e++)
	{
		myfile << emp_errors_log[e] << endl;
		myfile << "<br>" << endl;
		        
	};

	myfile << "</body>\n"
		   << "</html>";

	myfile.close();
}

int validation_num(string emp_id)
{	
	//validates the first 2 characters of the employee id
	string alpha_checker(emp_id.substr(0,2));
		for (int y = 0; y < 2; y++)
			{
				bool alpha_flag = isalpha(alpha_checker[y]);
				//cout << alpha_flag << endl;
				if (alpha_flag < 1)
					{
					cout << "Invalid input, employee id must be in format: AA-1234" << endl;
					return 1;
					};
			};
		
		//validates that the 3rd character is a punctuation mark
		string punct_checker(emp_id.substr(2,1));
		bool punct_flag = ispunct(punct_checker[0]);
		if (punct_flag < 1)
			{
			cout << "Invalid input, employee id must be in format: AA-1234" << endl;
			return 1;
			};

		//validates that the 4-7 characters are digits
		string num_checker(emp_id.substr(3,4));
		for (int z = 0; z < 4; z++)
			{
				bool num_flag = isdigit(num_checker[z]);
				if (num_flag < 1)
					{
					cout << "Invalid input, employee id must be in format: AA-1234" << endl;
					return 1;
					};
			};
		//validates that all of the characters are the correct type and that the employee id is not too long
		if (emp_id.length() > 7)
			{
			cout << "Invalid input, employee id must be in format: AA-1234" << endl;
			return 1;
			};

	return 0;

}



