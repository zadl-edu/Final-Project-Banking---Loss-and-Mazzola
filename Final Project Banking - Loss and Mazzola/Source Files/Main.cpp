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
	LogInMenu();
	return 0;
}

int Menu(string input)
{
	if (input.compare("Log Out") == 0)
	{
		if (loadedTeller == NULL)
			if (LogInMenu())
		return 0;
	}
	else if (input.compare("") == 0)
	{
		
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
			return true;
		}
	}
	cout << "Log In Failed\n";
	return false;

}

void loadInitialData(string tellers, string accounts)
{
	loadTellers();
	loadAccounts();
}

void loadTellers() 
{
}

void loadAccounts()
{
}