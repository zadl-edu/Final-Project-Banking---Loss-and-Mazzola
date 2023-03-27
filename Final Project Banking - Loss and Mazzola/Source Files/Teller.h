#pragma once
#include <string>
namespace Banking 
{
	class Teller
	{
		private:
			std::string Username, Password;
			
		public:
			Teller (std::string username, std::string password);
			bool LogIn(std::string username, std::string password);
			std::string getUsername();
			bool LogOut();
	};
}

