#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Teller.cpp"

using namespace std;

vector<Banking::Teller> loadedTellerAccounts;
Banking::Teller* loadedTeller;

int main() 
{	
	return 0;
}

bool Menu(string input)
{
	if (input.compare("Log In") == 0)
	{
		LogInMenu();
		return true;
	}
	
}

bool LogInMenu()
{
	string u,p;
	cout << "Enter Username:";
	cin >>  u;
	cout << endl << "Enter Password:";
	cin >> p;
	cout << endl;
	for (Banking::Teller i : loadedTellerAccounts)
	{
		if (i.LogIn(u, p))
		{
			loadedTeller = &i;
			cout << "Logged in as " << i.getUsername() << endl;
			break;
		}
	}
}

void loadInitialData(string tellers, string accounts)
{
	loadTellers();
	loadAccounts();
}

void loadTellers() {}

void loadAccounts() {}