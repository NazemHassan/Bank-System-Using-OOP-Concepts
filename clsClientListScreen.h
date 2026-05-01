#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(5) << "" << "| " << setw(16) << Client.AccountNumber();
		cout << "| " << setw(21) << Client.FullName();
		cout << "| " << setw(13) << Client.Phone;
		cout << "| " << setw(21) << Client.Email;
		cout << "| " << setw(13) << Client.PinCode;
		cout << "| " << setw(13) << Client.AccountBalance;
	}

public:
	static void ShowClientsList()
	{

		if (!_CheckAccessRights(clsUser::enMainMenuePermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t\tClient List Screen";
		string Subtitle = "\t\t(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, Subtitle);


		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n\n";
		cout << setw(5) << "" << "| " << left << setw(16) << "Account Number";
		cout << "| " << left << setw(21) << "Client Name";
		cout << "| " << left << setw(13) << "Phone";
		cout << "| " << left << setw(21) << "Email";
		cout << "| " << left << setw(13) << "Pin Code";
		cout << "| " << left << setw(13) << "Balance";
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";


		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t\tNo Clients Available In The System!\n\n";
		}

		for (const clsBankClient& C : vClients)
		{
			_PrintClientRecordLine(C);
			cout << endl;
		}
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";
	}

};

