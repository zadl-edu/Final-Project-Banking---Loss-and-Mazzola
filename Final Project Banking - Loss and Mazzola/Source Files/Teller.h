#pragma once
#include <string>
namespace Banking 
{
	class Teller
	{
		private:
			std::string _username, _password;
			bool loggedIn = false;
		public:
			Teller (std::string username, std::string password);//Constructor
			bool LogIn(std::string username, std::string password);//Check for login
			std::string getUsername();
			bool LogOut();//Will log you out
			bool checkLoggedIn()
			{
				return loggedIn;
			}
			void saveToFile(std::ofstream& fileStream);//Saves the account to given file
	};
}

