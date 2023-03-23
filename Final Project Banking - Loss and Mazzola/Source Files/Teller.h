#pragma once
#include <string>
namespace Accounts 
{
	class Teller
	{
		public:Teller (std::string username, std::string password);
		public:bool LogIn(std::string username, std::string password);
	};
}

