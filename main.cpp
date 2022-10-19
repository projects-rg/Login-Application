#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

//functions
void login();
void reg();
void resetDeat();

int main() {
	system("cls"); //clear screen
	int choice;
	//prints choices to user
	cout << "***** Company System *****\n";
	cout << "Existing user?\n1.Login\n";
	cout << "\nNew User?\n2.Register\n";
	cout << "\nCan't Remember Password?\n3.Forgot Password\n";
	cout << "\nPLEASE ENTER A NUMBER BELOW: \n";

	//gets user input
	cin >> choice;
	switch (choice) {
		case 1:
			login();
			break;
		case 2:
			reg();
			break;
		case 3:
			resetDeat();
			break;
		case 4:
			cout << "Thank you for signing in\n";
			break;
		default:
			cout << "Sorry, Wrong choice Selected... Please try again\n";
			main();
	}

	

}

//registration function
void reg()
{

	string user, regpass;
	system("cls"); //windows command prompt clears the screen
	cout << "Enter Username :";
	cin >> user; //stores username
	cout << "\nEnter Password :";
	cin >> regpass; //stores password

	ofstream reg("storage.txt", ios::app); //stores username and password in text file
	reg << user << ' ' << regpass << endl; //seperates inputs by space
	system("cls"); //clear screen
	cout << "\nSuccessfully Registered\n"; //create user account
	main();

	//to be added - check for existing username while creating account is in process.
}

void login()
{
	int userExists = 0;
	string user, password, u, p; 
	system("cls"); //clears screen
	cout << "Please enter your username and password below: \n";
	cout << "Username :";
	cin >> user; //stores username
	cout << "Password :";
	cin >> password; //stores password

	ifstream input("storage.txt");
	//checks input against entries in stored text file
	while (input >> u >> p)
	{
		if (u == user && p == password)
		{
			userExists = 1;
		}
	}
	input.close();

	//If user is found shows an welcome message
	if (userExists == 1)
	{
		cout << "Checking system for user...\n";
		Sleep(2000);
		cout << "User Found!!\n";
		Sleep(1000);
		cout << "Hello " << user << " Welcome Back!.. Press any key to continue"; // << endl;
		cin.get();
		cin.get();
		
		main();
	}
	//if user is not found shows an error code and try again
	else
	{
		cout << "Login Failed.. Press any key to continue";
		cin.get();
		main();

	}
}

//used to reset the users login information
void resetDeat() 
{
	int choice; //used to store users choice
	system("cls");
	cout << "Please Enter a number from above...\n";
	cout << "1.Search for username \n";
	cout << "2.Return to the main menu \n";
	cin >> choice;

    switch (choice)
    {
	//case 1 is responsible for checking for username and providing the password to the account
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered username :";
        cin >> searchuser;

        ifstream searchu("storage.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    //case 2 returns the user to the main menu
    case 2:
    {
        cin.get();
        main();
    }

	//user enters invalid number
    default:
        cout << "Sorry, An Error has occured. Please try again" << endl;
		resetDeat();
	}
}