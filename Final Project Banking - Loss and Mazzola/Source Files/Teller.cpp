#include "Teller.h"
#include <fstream>

using namespace std;

string Banking::Teller::getUsername() 
{
	return _username; 
}
	
Banking::Teller::Teller(string username, string password)
{
	_username = username;
	_password = password;
}

bool Banking::Teller::LogIn(string username, string password)
{
	if ((_username == username) && (_password == password))
	{
		loggedIn = true;
		return true;
	}
	else
		return false;
}

bool Banking::Teller::LogOut()
{
	loggedIn = false;
	if (!loggedIn)
		return true;
	else
		return false;
}
void Banking::Teller::saveToFile(std::ofstream& fileStream)
{
	fileStream << _username << " " << _password << endl;
}