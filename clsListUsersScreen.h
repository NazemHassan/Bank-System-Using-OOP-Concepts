#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(5) << "" << "| " << setw(16) << User.UserName;
		cout << "| " << setw(21) << User.FullName();
		cout << "| " << setw(13) << User.Phone;
		cout << "| " << setw(21) << User.Email;
		cout << "| " << setw(13) << User.Password;
		cout << "| " << setw(13) << User.Permissions;
	}

public:

	static void ShowUsersList()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t    User List Screen";
		string SubTitle = "\t      (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n\n";
		cout << setw(5) << "" << "| " << left << setw(16) << "UserName";
		cout << "| " << left << setw(21) << "Full Name";
		cout << "| " << left << setw(13) << "Phone";
		cout << "| " << left << setw(21) << "Email";
		cout << "| " << left << setw(13) << "Password";
		cout << "| " << left << setw(13) << "Permissions";
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";

		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\t\tNo Users Available In The System!\n\n";

		}
		else
		{
			for (clsUser& User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		cout << endl << setw(5) << "" << "_______________________________________________________________";
		cout << "______________________________________________\n";
	}

};

