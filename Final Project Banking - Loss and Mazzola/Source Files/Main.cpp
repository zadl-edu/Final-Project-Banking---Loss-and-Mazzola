#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <thread>
#include <windows.h>
#include "Teller.h"
#include "Account.h"
#include "Main.h"
using namespace std;

vector<Banking::Teller> loadedTellerAccounts;
vector<Banking::Account> loadedAccounts;
Banking::Teller* loadedTeller;

bool LogInMenu()
{
	string u,p;
	cout << "Enter Username:";
	cin >>  u;
	if (u == "verlassen")
	{
		exit(0);
	}
	cout << endl << "Enter Password:";
	cin >> p;
	if (p == "verlassen")
	{
		exit(0);
	}
	cout << endl;
	for (Banking::Teller i : loadedTellerAccounts)
	{
		if (i.LogIn(u, p))
		{
			loadedTeller = &i;
			cout << "Logged in as " << i.getUsername() << endl;
			return true;
		}
	}
	cout << "Log In Failed\n";
	return false;
}

void MainMenu()
{
	string input;
	getline(cin, input);
	if (input == "Log In")
	{
		if (!LogInMenu())
			thread(MainMenu).detach();
	}
	else if (input == "Exit")
	{
		return;
	}
	else 
	{
		cout << "Invalid Command : " << input << endl;
		thread(MainMenu).detach();
	}
}

void loadTellers() 
{
	string u,p;
	ifstream inputStream("Data Files\\tellers.dat");
	while (inputStream >> u)
	{
		inputStream >> p;
		loadedTellerAccounts.push_back(Banking::Teller(u, p));
	}
}

void loadAccounts()
{
	string accountNumber, ssn, name, address, phoneNumber;
	ifstream inputStream("Data Files\\accounts.dat");
	while (getline(inputStream, accountNumber))
	{
		getline(inputStream, ssn);
		getline(inputStream, name);
		getline(inputStream, address);
		getline(inputStream, phoneNumber);
		loadedAccounts.push_back(Banking::Account(accountNumber, ssn, name, address, phoneNumber));
	}
		
}

void loadInitialData(string tellers, string accounts)
{
	loadTellers();
	loadAccounts();
}

int main()
{
	loadInitialData("Data Files\\tellers.dat", "Data Files\\accounts.dat");
	MainMenu();
	return 0;
}
