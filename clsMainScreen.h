#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

using namespace std;


class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9,eExit = 10
	};

	static void _GoBackToMainMenu()
	{
		cout << "\n\n\tPress any key to go back to main menu...\n";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsListScreen()
	{
		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "Add new clients screen will be here...\n";

		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "Delete client will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "Update client will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find client will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		//cout << "Transactions menu will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		//cout << "Manage users menu will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\nLogin Register will be here...\n";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\nCurrency Exchange will be here...\n";
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenu();
	}

	static void _Logout()
	{
		//cout << "End screen will be here...\n";

		//here we should not use clsLoginScreen::ShowLoginScreen(); because it will make error 
		//called circular reference. we will solved in main.cpp or main file

		CurrentUser = clsUser::Find("", "");
	}

	static short _ReadMainMenuOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 10]?";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 and 10");
		return choice;
	}

	static void _PerformMainMenuOption(enMainMenueOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenueOptions::eListClients:
			system("cls");
			_ShowAllClientsListScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			break;

		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Menu");

		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t\t\tMain Menu Screen\n";
		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(39) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(39) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(39) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(39) << left << "" << "\t[5] Find Client.\n";
		cout << setw(39) << left << "" << "\t[6] Transactions.\n";
		cout << setw(39) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(39) << left << "" << "\t[8] Login Register.\n";
		cout << setw(39) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(39) << left << "" << "\t[10] Logout.\n";
		cout << setw(39) << left << "" << "===========================================\n";
		_PerformMainMenuOption((enMainMenueOptions)_ReadMainMenuOption());

	}

};

