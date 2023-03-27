#include "Teller.h"
class Teller
{
private:
	std::string _username;
	std::string _password;
	bool loggedIn = false;
public:
	std::string getUsername() { return _username; }
	
	Teller(std::string username, std::string password)
	{
		_username = username;
		_password = password;
	}

	bool LogIn(std::string username, std::string password)
	{
		if ((_username.compare(username)) == 0 && (_password.compare(password) == 0))
		{
			loggedIn = true;
			return true;
		}
		else
			return false;
	}
};