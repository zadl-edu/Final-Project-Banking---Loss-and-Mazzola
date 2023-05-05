#pragma once
#include <string>
namespace Banking
{
	class Account
	{
	private:
		std::int64_t _balance;
		std::string _accountNumber, _ssn, _name, _address, _phoneNumber;
		void loadBalance();//Loads balance from file
		void saveBalance();//Saves balance to file
	public:
		Account(std::string AccountNumber, std::string SSN, std::string Name, std::string Address, std::string PhoneNumber);//Constructor
		void setBalance(int64_t balance);
		int64_t getBalance();
		int64_t deposit(int64_t value);//Deposit function
		int64_t withdraw(int64_t value);//Withdraw function
		std::string getAcountNumber();
		void saveToFile(std::ofstream& fileStream);//Saves account info to given file
		std::string getName();
		std::string getSSN();
		std::string getPhone();
		std::string getAddress();
		void setName(std::string name);
		void setSSN(std::string ssn);
		void setPhone(std::string phoneNumber);
		void setAddress(std::string address);
	};
}