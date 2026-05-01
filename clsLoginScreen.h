#pragma once

#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
		{
		string UserName, Password;
		bool LoginFailed = false;
		short FailedLoginCount = 0;

		do
		{

			if (LoginFailed)
			{
				FailedLoginCount++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You Have " << 3-FailedLoginCount << " Trail(s) to login.\n";
				
				if (FailedLoginCount == 3)
				{
					cout << "\n\nYou are locked after 3 failed trails\n";
					return false;
				}

			}

			cout << "\nEnter UserName: ";
			UserName = clsInputValidate::ReadString();
			cout << "Enter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");
		return _Login();   
	
	}


};



