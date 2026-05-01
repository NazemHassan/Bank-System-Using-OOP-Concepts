#pragma once

#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(5) << "" << "| " << setw(35) << Currency.Country();
		cout << "| " << setw(10) << Currency.CurrencyCode() ;
		cout << "| " << setw(47) << Currency.CurrencyName() ;
		cout << "| " << setw(13) << Currency.Rate();
	}

public:
	static void ShowListCurrenciesScreen()
	{
		vector<clsCurrency> vCurrenciesData = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen.";
		string SubTitle = "\t   (" + to_string(vCurrenciesData.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n\n";
		cout << setw(5) << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(47) << "Name";
		cout << "| " << left << setw(13) << "Rate/(1$)";
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";


		if (vCurrenciesData.size() == 0)
		{
			cout << endl;
			cout << "\t\t\tNo Currencies are available in the system\n ";
			return;
		}

		for (clsCurrency& Currency : vCurrenciesData)
		{
			_PrintCurrencyRecordLine(Currency);
			cout << endl;
		}
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";


	}

};

