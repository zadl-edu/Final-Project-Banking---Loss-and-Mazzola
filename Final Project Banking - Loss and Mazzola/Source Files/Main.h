#pragma once
#include <string>
//Main function
int main();
//Main menu
void MainMenu();
//Log in screen
bool LogInMenu();
//Loads tellers and accounts from given file locations
void loadInitialData(std::string tellers, std::string accounts);
//Function that loads tellers into memory
void loadTellers(std::string tellers);
//Function that loads accounts into memory
void loadAccounts(std::string accounts);
//Menu after logging in
void LoggedInMenu();
//Menu that allows you to manage accounts
void ManageMenu();
//Function to list all accounts loaded
void ListAccounts();
//Exit function that saves the teller and accounts to the files
void startExit();
//Menu that allows you to edit account info
void AccountMenu();
//Selection menu
void SelectAccountMenu();
//Menu that allows you to delete an account
void DeleteAccountMenu();