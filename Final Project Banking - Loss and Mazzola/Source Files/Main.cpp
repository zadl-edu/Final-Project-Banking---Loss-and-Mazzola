#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <sstream>
#include "Teller.h"
#include "Account.h"
#include "Main.h"

using namespace std;

vector<Banking::Teller> loadedTellerAccounts;
vector<Banking::Account> loadedAccounts;
Banking::Teller* loadedTeller;
Banking::Account* selectedAccount;
string tellerFile = "Data Files\\tellers.dat";
string accountFile = "Data Files\\accounts.dat";

int main()
{
	loadInitialData(tellerFile, accountFile);
	MainMenu();
	return 0;
}

void MainMenu()
{
	cout << "Please enter a command:\n";
	string input;
	getline(cin, input);
	if (input == "Log In")
	{
		if (!LogInMenu())
			MainMenu();
		else
			LoggedInMenu();
	}
	else if ((input == "Exit") || (input == "verlassen"))
	{
		startExit();
		return;
	}
	else
	{
		cout << "Invalid Command : " << input << endl;
		MainMenu();
	}
}

bool LogInMenu()
{
	string u,p;
	cout << "Enter Username:";
	cin >>  u;
	if (u == "verlassen")
	{
		startExit();
	}
	cout << endl << "Enter Password:";
	cin >> p;
	if (p == "verlassen")
	{
		startExit();
	}
	cout << endl;
	for (Banking::Teller i : loadedTellerAccounts)
	{
		if (i.LogIn(u, p))
		{
			loadedTeller = &i;
			cout << "Logged in as " << loadedTeller->getUsername() << endl;
			return true;
		}
	}
	cout << "Log In Failed\n";
	return false;
}

void LoggedInMenu() 
{
	cout << "Please enter a command:\n";
	string input;
	getline(cin, input);
	if (input == "Log Out")
	{
		if (loadedTeller->LogOut())
		{
			loadedTeller = nullptr;
			cout << "Logged out sucessfully.";
			MainMenu();
		}
		else
		{
			cout << "Log out failed.\n";
			LoggedInMenu();
		}
	}
	else if (input == "Manage Accounts")
	{
		ManageMenu();
	}
	else if ((input == "Exit") || (input == "verlassen"))
	{
		startExit();
		return;
	}
	else
	{
		cout << "Invalid Command : " << input << endl;
		LoggedInMenu();
	}
}

void CreateNewAccountMenu()
{
	string accountNumber, ssn, name, address, phoneNumber;
	cout << "Enter the account number :\n";
	getline(cin, accountNumber);
	if (accountNumber == "verlassen")
		startExit();
	for (Banking::Account i : loadedAccounts)
	{
		if (i.getAcountNumber() == accountNumber)
		{
			cout << "Account number already in use.\n";
			return;
		}
	}
	cout << "Enter the SSN :\n";
	getline(cin, ssn);
	if (ssn == "verlassen")
		startExit();
	cout << "Enter the name :\n";
	getline(cin, name);
	if (name == "verlassen")
		startExit();
	cout << "Enter the address :\n";
	getline(cin, address);
	if (address == "verlassen")
		startExit();
	cout << "Enter the phone number\n";
	getline(cin, phoneNumber);
	if (phoneNumber == "verlassen")
		startExit();
	loadedAccounts.push_back(Banking::Account(accountNumber, ssn, name, address, phoneNumber));
	cout << "Account Created.\n";
}

void ManageMenu()
{
	cout << "Please enter a command:\n";
	string input;
	getline(cin, input);
	if (input == "Log Out")
	{
		if (loadedTeller->LogOut())
		{
			loadedTeller = nullptr;
			cout << "Logged out sucessfully.";
			MainMenu();
		}
		else
		{
			cout << "Log out failed.\n";
			ManageMenu();
		}
	}
	else if (input == "Create New Account")
	{
		CreateNewAccountMenu();
		ManageMenu();
	}
	else if (input == "Delete Account")
	{
		DeleteAccountMenu();
		ManageMenu();
	}
	else if (input == "Manage Account")
	{
		SelectAccountMenu();
		AccountMenu();
		ManageMenu();
	}
	else if (input == "List Accounts")
	{
		ListAccounts();
		ManageMenu();
	}
	else if (input == "Back")
	{
		if (loadedTeller->checkLoggedIn())
			LoggedInMenu();
		else
			MainMenu();
	}
	else if ((input == "Exit") || (input == "verlassen"))
	{
		startExit();
		return;
	}
	else
	{
		cout << "Invalid Command : " << input << endl;
		LoggedInMenu();
	}
}

void DeleteAccountMenu()
{
	cout << "Existing Accounts :\n";
	ListAccounts();
	string input;
	cout << "Input the account number of the desired account to delete:";
	getline(cin, input);
	if (input == "verlassen")
		startExit();
	for (int i = 0; i < loadedAccounts.size(); i++)
	{
		if (loadedAccounts[i].getAcountNumber() == input)
		{
			loadedAccounts.erase(loadedAccounts.begin()+i);
			break;
		}
	}
	cout << "Account " << input << " has been deleted.\n";
}

void SelectAccountMenu() 
{
	if (!(selectedAccount == nullptr))
	{
		cout << "Current Selected Account is " << selectedAccount->getAcountNumber() << endl;
	}
	cout << "Existing Accounts :\n";
	ListAccounts();
	string input;
	cout << "Enter the account number :\n";
	cin >> input;
	if (input == "verlassen")
		startExit();
	for (Banking::Account i : loadedAccounts)
	{
		if (i.getAcountNumber() == input)
		{
			selectedAccount = &i;
			cout << "Selected account is " << selectedAccount->getAcountNumber() << endl;
			return;
		}
	}
	if (selectedAccount == nullptr)
	{
		cout << "Selection failed. Please try again.\n";
		SelectAccountMenu();
	}
}

void AccountMenu()
{
	if (!(selectedAccount == nullptr))
	{
		cout << "Current Selected Account is " << selectedAccount->getAcountNumber() << endl;
	}
	else
	{
		SelectAccountMenu();
	}
	cout << "Please enter a command:\n";
	string input;
	getline(cin, input);
	if (input == "Log Out")
	{
		if (loadedTeller->LogOut())
		{
			loadedTeller = nullptr;
			selectedAccount = nullptr;
			cout << "Logged out sucessfully.";
			MainMenu();
		}
		else
		{
			cout << "Log out failed.\n";
			AccountMenu();
		}
	}
	else if (input == "Get Name")
	{
		cout << "Current name on the account is " << selectedAccount->getName() << ".\n";
		ManageMenu();
	}
	else if (input == "Get Phone Number")
	{
		cout << "Current phone number on the account is " << selectedAccount->getPhone() << ".\n";
		ManageMenu();
	}
	else if (input == "Get SSN")
	{
		cout << "Current SSN on the account is " << selectedAccount->getSSN() << ".\n";
		ManageMenu();
	}
	else if (input == "Get Address")
	{
		cout << "Current Address on the account is " << selectedAccount->getAddress() << ".\n";
		ManageMenu();
	}
	else if (input == "Change Name")
	{
		cout << "Current name on the account is " << selectedAccount->getName() << ".\n";
		cout << "Enter the new name of the account :";
		getline(cin, input);
		if (input == "verlassen")
			startExit();
		selectedAccount->setName(input);
		cout << "Current name on the account is now" << selectedAccount->getName() << ".\n";
		ManageMenu();
	}
	else if (input == "Change Phone Number")
	{
		cout << "Current phone number on the account is " << selectedAccount->getPhone() << ".\n";
		cout << "Enter the new phone number of the account :";
		getline(cin, input);
		if (input == "verlassen")
			startExit();
		selectedAccount->setPhone(input);
		cout << "Current phone number on the account is now" << selectedAccount->getPhone() << ".\n";
		ManageMenu();
	}
	else if (input == "Change SSN")
	{
		cout << "Current SSN on the account is " << selectedAccount->getSSN() << ".\n";
		cout << "Enter the new SNN of the account :";
		getline(cin, input);
		if (input == "verlassen")
			startExit();
		selectedAccount->setSSN(input);
		cout << "Current phone number on the account is now" << selectedAccount->getSSN() << ".\n";
		ManageMenu();
	}
	else if (input == "Change Address")
	{
		cout << "Current address on the account is " << selectedAccount->getAddress() << ".\n";
		cout << "Enter the new address of the account :";
		getline(cin, input);
		if (input == "verlassen")
			startExit();
		selectedAccount->setAddress(input);
		cout << "Current phone number on the account is now" << selectedAccount->getAddress() << ".\n";
		ManageMenu();
	}
	else if (input == "Deposit")
	{
		float value;
		cout << "Enter value of deposit in USD :";
		cin >> input;
		if (input == "verlassen")
			startExit();
		stringstream ss;
		ss << input;
		ss >> value;
		if (value != NULL)
		{
			cout << "Deposited " << value << " USD.\nNew Balance is " << (float)(selectedAccount->deposit((int64_t)((value * 100) / 100.0f))) << " USD.\n";
		}
		else
		{
			cout << "Invalid input.\n";
		}
		ManageMenu();
	}
	else if (input == "Withdraw")
	{
		float value;
		cin >> input;
		if (input == "verlassen")
			startExit();
		stringstream ss;
		ss << input;
		ss >> value;
		cout << "Enter value of withdraw in USD :";
		cin >> value;
		if (value != NULL)
		{
			cout << "Deposited " << value << " cents.\nNew Balance is " << (float)(selectedAccount->withdraw((int64_t)(value * 100)) / 100.0f) << " cents.\n";
		}
		else
		{
			cout << "Invalid input.\n";
		}
		ManageMenu();
	}
	else if (input == "Set Balance")
	{
		cout << "Current balance is " << (float)(selectedAccount->getBalance()/100.0f) << " USD.\n";
		float value;
		cout << "Enter new value of account in USD :";
		cin >> input;
		if (input == "verlassen")
			startExit();
		stringstream ss;
		ss << input;
		ss >> value;
		if (value != NULL)
		{
			selectedAccount->setBalance((int64_t)(value * 100));
			cout << "The balance is now" << (float)(selectedAccount->getBalance()/ 100.0f) << " USD.\n";
		}
		else
		{
			cout << "Invalid input.\n";
		}
		ManageMenu();
	}
	else if (input == "Get Balance")
	{
		cout << "Current balance is " << (float)(selectedAccount->getBalance()/ 100.0f) << " USD.\n";
		ManageMenu();
	}
	else if (input == "List Accounts")
	{
		ListAccounts();
		ManageMenu();
	}
	else if (input == "Back")
	{
		selectedAccount = nullptr;
		if (loadedTeller->checkLoggedIn())
			ManageMenu();
		else
			MainMenu();
	}
	else if ((input == "Exit") || (input == "verlassen"))
	{
		startExit();
		return;
	}
	else
	{
		cout << "Invalid Command : " << input << endl;
		LoggedInMenu();
	}

}

void loadTellers(string tellers)
{
	string u,p;
	ifstream inputStream("Data Files\\tellers.dat");
	if (inputStream.is_open())
	{
		while (inputStream >> u)
		{
			inputStream >> p;
			loadedTellerAccounts.push_back(Banking::Teller(u, p));
		}
	}
}

void loadAccounts(string accounts)
{
	string accountNumber, ssn, name, address, phoneNumber;
	ifstream inputStream(accounts);
	if (inputStream.is_open())
	{
		while (getline(inputStream, accountNumber))
		{
			getline(inputStream, ssn);
			getline(inputStream, name);
			getline(inputStream, address);
			getline(inputStream, phoneNumber);
			loadedAccounts.push_back(Banking::Account(accountNumber, ssn, name, address, phoneNumber));
		}
	}
}

void loadInitialData(string tellers, string accounts)
{
	thread a(loadTellers, tellers);
	thread b(loadAccounts, accounts);
	a.join();
	b.join();
}

void ListAccounts()
{
	for (Banking::Account account : loadedAccounts)
	{
		cout << account.getAcountNumber() << endl;
	}
}

void startExit()
{
	thread tellers([]() 
	{
		ofstream output(tellerFile);
		if (output.is_open())
		{
			cout << "Saving Tellers"<< endl;
			for (Banking::Teller teller : loadedTellerAccounts)
			{
				teller.saveToFile(output);
			}
		}
		output.close();
	});
	
	thread accounts([]()
	{
		ofstream output(accountFile);
		if (output.is_open())
		{
			cout << "Saving Accounts" << endl;
			for (Banking::Account account : loadedAccounts)
			{
				account.saveToFile(output);
			}
		}
		output.close();
	});
	tellers.join();
	accounts.join();
	exit(0);
}