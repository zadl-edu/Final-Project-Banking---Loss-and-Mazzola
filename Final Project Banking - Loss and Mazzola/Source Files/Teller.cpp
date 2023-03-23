#include "Teller.h"
class Teller
{
	private:std::string Username, Password;

	public:Teller(std::string username, std::string password)
	{
		Username = username;
		Password = password;
	}

	public:bool LogIn(std::string username, std::string password)
	{
		return true;
	}
};