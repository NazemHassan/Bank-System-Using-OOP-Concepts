#pragma once

#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Message = "Currency Card: ")
	{

		cout << "\n" << Message;
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was Not Found, Enter Again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From: ");

		if (Currency1.CurrencyCode() == "USD")
		{
			float amount_in_currency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

			cout << endl << Amount << " " << Currency1.CurrencyCode() << " = " <<
				amount_in_currency2 << " " << Currency2.CurrencyCode() << endl;
			return;
		}


		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout <<endl <<  Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		 }
		else
		{
			cout << "\nConverting from USD To:\n";
			_PrintCurrencyCard(Currency2, "To:");

			float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

			cout <<endl <<  Amount << " " << Currency1.CurrencyCode() << " = " <<
				AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;
		}

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
		    _DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? y/n? ";
			cin >> Continue;
		}

	

	}



};

