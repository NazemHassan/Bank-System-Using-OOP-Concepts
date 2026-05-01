#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	enum enCurrenciesMainMenuOptions{eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenu = 5};
	
	static void _ShowListCurrenciesScreen()
	{
		//cout << "List Currencies screen will be here...\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency screen will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate rate screen will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency calculator screen will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrenciesMenu()
	{
		cout << "\n\n\tPress any key to go back to currency exchange menu...\n";
		system("pause>0");		
		ShowCurrenciesMenu();
	}

	static short _ReadCurrencyExchangeOption()
	{
		short Option = 0;
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 and 5");
		return Option;
	}

	static void _PerformCurrencyExchangeOption(enCurrenciesMainMenuOptions MenuOption)
	{
		switch (MenuOption)
		{
		case enCurrenciesMainMenuOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenu();
			break;
		}
		case enCurrenciesMainMenuOptions::eMainMenu:
		{
			//Do nothing here automaticly main screen  menu will handel it 
		}
		}
	}


public:

	static void ShowCurrenciesMenu()
	{
		system("cls");

		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(39) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(39) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(39) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(39) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(39) << left << "" << "===========================================\n";
		_PerformCurrencyExchangeOption((enCurrenciesMainMenuOptions)_ReadCurrencyExchangeOption());

	}

};

