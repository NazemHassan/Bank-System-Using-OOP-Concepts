#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_____________________";
		cout << "\nFirst Name : " << Client.FirstName;
		cout << "\nLast Name  : " << Client.LastName;
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email;
		cout << "\nPhone      : " << Client.Phone;
		cout << "\nAc. Number : " << Client.AccountNumber();
		cout << "\nPassword   : " << Client.PinCode;
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n_____________________";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";

		cout << "Please enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t\tWithdraw Screen");

		string AccountNumber;
		AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;

		cout << "\n\nPlease enter Withdraw amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		if (Client1.AccountBalance < Amount || Amount <= 0)
		{
			cout << "Cannot Withdraw, Invalid withdraw amount!\n";
			cout << "\nAmount To Withdraw is: " << Amount;
			cout << "\nYour Balance is; " << Client1.AccountBalance << endl;
		}
		else {

			cout << "\nAre you sure you want to perform this transaction? Y/N? ";

			char Answer = 'N';
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				if (Client1.Withdraw(Amount))
				{
					cout << "Amount Withdrew Successfully.\n";
					cout << "\nNew Balance is: " << Client1.AccountBalance << endl;
				}
				else
				{
					cout << "Cannot Withdraw, Invalid withdraw amount!\n";
					cout << "\nAmount To Withdraw is: " << Amount;
					cout << "\nYour Balance is; " << Client1.AccountBalance << endl;
				}
			}
			else
			{
				cout << "\nOperation was cancelled.\n";
			}
		}
	}

};

