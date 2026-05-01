#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber;
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_____________________";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAc. Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n_____________________";
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;
		cout << "\n\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\n\nAmount Exceeds The Available Balance, Enter Another Amount? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

public:
	static void ShowTransferScreen()
	{ 
		_DrawScreenHeader("\t\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find (_ReadAccountNumber("\nPlease enter account number to transfer from: "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\n\nPlease enter account number to transfer to: "));
		_PrintClient(DestinationClient);


		while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
		{
			cout << "\nError, Destination Account cannot be the same as the source account.\n";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("\n\nPlease enter different account number to transfer to: "));
		}


		float Amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation? Y/N? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer failed\n";
			}

		}
			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
	}

};

