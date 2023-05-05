#pragma once
#include <string>
//Main function
int main();

void MainMenu();
bool LogInMenu();
void loadInitialData(std::string tellers, std::string accounts);
void loadTellers(std::string tellers);
void loadAccounts(std::string accounts);
void LoggedInMenu();
void ManageMenu();
void ListAccounts();
void startExit();
void AccountMenu();
void SelectAccountMenu();
void DeleteAccountMenu();