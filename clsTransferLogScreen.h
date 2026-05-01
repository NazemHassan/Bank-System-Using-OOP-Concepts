#pragma once

#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogList(clsBankClient::stTransferLogRecord Record)
	{
		cout << setw(5) << "" << "| " << left << setw(22) << Record.DateTime;
		cout << "| " << left << setw(10) << Record.SourceAccount;
		cout << "| " << left << setw(10) << Record.DestinationAccount;
		cout << "| " << left << setw(12) << Record.Amount;
		cout << "| " << left << setw(14) << Record.SourceBalance;
		cout << "| " << left << setw(14) << Record.DestinationBalance;
		cout << "| " << left << setw(10) << Record.UserName;
	}

public:
	
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t(" + to_string(vTransferLogRecords.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);


		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n\n";
		cout << setw(5) << "" << "| " << left << setw(22) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(14) << "s.Balance";
		cout << "| " << left << setw(14) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";
	
		if (vTransferLogRecords.size() == 0)
		{
			cout <<"\n" <<  setw(35) << " " << "No Transfer Log Available In The System\n";
			return;
		}

		for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecords)
		{
			_PrintTransferLogList(Record);
			cout << endl;
		}

		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";

	}
};

