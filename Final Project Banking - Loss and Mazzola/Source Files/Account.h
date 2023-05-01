#pragma once
#include <string>
namespace Banking
{
	class Account
	{
	private:
		std::int64_t _balance;
		std::string _accountNumber, _ssn, _name, _address, _phoneNumber;
		void loadBalance(std::string AccountNumber);

	public:
		Account(std::string AccountNumber, std::string SSN, std::string Name, std::string Address, std::string PhoneNumber);
		void setBalance(int64_t balance);
		int64_t getBalance();
		int64_t deposit(int64_t value);
		int64_t withdraw(int64_t value);
	};
}