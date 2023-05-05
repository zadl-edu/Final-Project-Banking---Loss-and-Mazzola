#include "Account.h"
#include <fstream>
#include <thread>
#include <iostream>
#include <filesystem>

using namespace std;

void Banking::Account::loadBalance()
{
	ifstream input("Data Files\\Account Balances\\" + _accountNumber + ".dat");
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

Banking::Account::Account(std::string AccountNumber, std::string SSN, std::string Name, std::string Address, std::string PhoneNumber)
{
	_accountNumber = AccountNumber;
	_ssn = SSN;
	_name = Name;
	_address = Address;
	_phoneNumber = PhoneNumber;
	loadBalance();
}

void Banking::Account::setBalance(int64_t balance)
{
	_balance = balance;
}

std::string Banking::Account::getAcountNumber()
{
	return _accountNumber;
}

int64_t Banking::Account::getBalance()
{
	return _balance;
}

int64_t Banking::Account::deposit(int64_t value)
{
	_balance += value;
	return _balance;
}

int64_t Banking::Account::withdraw(int64_t value)
{
	_balance -= value;
	return _balance;
}
void Banking::Account::saveToFile(std::ofstream& fileStream)
{
	fileStream << _accountNumber << endl;
	fileStream << _ssn << endl;
	fileStream << _name << endl;
	fileStream << _address << endl;
	fileStream << _phoneNumber << endl;
	saveBalance();
}

void Banking::Account::saveBalance()
{
	ofstream file("Data Files\\Account Balances\\" + _accountNumber + ".dat");
	if (file.is_open())
	{
		cout << "Saving balance of account " << _accountNumber << endl;
		file << _balance;
	}
	file.close();
}

std::string Banking::Account::getName()
{
	return _name;
}

std::string Banking::Account::getSSN()
{
	return _ssn;
}

std::string Banking::Account::getPhone()
{
	return _phoneNumber;
}

std::string Banking::Account::getAddress()
{
	return _address;
}

void Banking::Account::setName(std::string name)
{
	_name = name;
}

void Banking::Account::setSSN(std::string ssn)
{
	_ssn = ssn;
}

void Banking::Account::setPhone(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Banking::Account::setAddress(std::string address)
{
	_address = address;
}