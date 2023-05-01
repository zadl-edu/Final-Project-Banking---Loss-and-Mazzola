#include "Teller.h"

using namespace std;
class Teller
{
private:
	string _username, _password;
	bool loggedIn = false;
public:
	string getUsername() { return _username; }
	
	Teller(string username, string password)
	{
		_username = username;
		_password = password;
	}

	bool LogIn(string username, string password)
	{
		if ((_username == username) && (_password == password))
		{
			loggedIn = true;
			return true;
		}
		else
			return false;
	}

	bool LogOut()
	{
		loggedIn = false;
		if (!loggedIn)
			return true;
		else
			return false;
	}
};