#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, 
		eShowTotalBalance = 3,eTransfer = 4,eTransferLog = 5,eShowMainMenue = 6 };

	static void _GoBackToTransactionMenu()
	{
		cout << "\n\nPress any key to go back to transaction menu...\n";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen()
	{
		//cout << "Deposit screen will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "Withdraw screen will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "Total balance screen will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer screen will be here...\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "Transfer Screen Will Be Here...\n";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static short _ReadTransactionMenu()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between 1 to 6? ");
		return Choice;
	}

	static void _PerformTransactionsMenu(enTransactionsMenueOptions MenuOption)
	{
		switch (MenuOption)
		{
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenu();
			break;
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
			//Do nothing here main menu screen will handle it :-)

			break;
		}
	}


public:
	static void ShowTransactionsMenu()
	{

		if (!_CheckAccessRights(clsUser::enMainMenuePermissions::pTranactions))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\t     Transaction Menu");

		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t\t    Transactions Menu \n";
		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t[1] Deposit.\n";
		cout << setw(39) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(39) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(39) << left << "" << "\t[4] Transfer.\n";
		cout << setw(39) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(39) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(39) << left << "" << "===========================================\n";
		_PerformTransactionsMenu((enTransactionsMenueOptions)_ReadTransactionMenu());

	}


};

