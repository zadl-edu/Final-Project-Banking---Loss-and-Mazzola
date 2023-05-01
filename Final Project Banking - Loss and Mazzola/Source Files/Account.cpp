#include "Account.h"
#include <fstream>

using namespace std;
class Account
{
private:
	string _accountNumber, _ssn, _name, _address, _phoneNumber;
	int64_t _balance;
	void loadBalance(string AccountNumber)
	{
		string fileLocation = "Data Files\\Account Balances\\"+ AccountNumber + ".dat";
		ifstream input(fileLocation);
		if (input.is_open())
		{
			input >> _balance;
			input.close();
		}
		else
		{
			_balance = 0;
		}
	}
public:
	Account(std::string AccountNumber, std::string SSN, std::string Name, std::string Address, std::string PhoneNumber)
	{
		_accountNumber = AccountNumber;
		_ssn = SSN;
		_name = Name;
		_address = Address;
		_phoneNumber = PhoneNumber;
		loadBalance(AccountNumber);
	}

	void setBalance(int64_t balance)
	{
		_balance = balance;
	}

	int64_t getBalance()
	{
		return _balance;
	}

	int64_t deposit(int64_t value)
	{
		_balance += value;
		return _balance;
	}

	int64_t withdraw(int64_t value)
	{
		_balance -= value;
		return _balance;
	}
};