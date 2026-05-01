#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\n\tPress any key to go back to manage users menu...\n";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "List Users screen will be here...\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Add new user screen will be here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "Delete user screen will be here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "Update user screen will be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "Find user screen will be here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUsersMenuOption()
	{
		cout << setw(39) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenueOptions ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			//Do nothing here main menu screen will handle it :-)
		}
		}
	}

public:
	static void ShowManageUsersMenu()
	{
		if (!_CheckAccessRights(clsUser::enMainMenuePermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\t    Manage Users Screen");

		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t\t    Manage Users Screen\n";
		cout << setw(39) << left << "" << "===========================================\n";
		cout << setw(39) << left << "" << "\t[1] List Users.\n";
		cout << setw(39) << left << "" << "\t[2] Add New User.\n";
		cout << setw(39) << left << "" << "\t[3] Delete User.\n";
		cout << setw(39) << left << "" << "\t[4] Update User.\n";
		cout << setw(39) << left << "" << "\t[5] Find User.\n";
		cout << setw(39) << left << "" << "\t[6] Main Menu.\n";	
		cout << setw(39) << left << "" << "===========================================\n";
		_PerformManageUsersMenuOption((enManageUsersMenueOptions)_ReadManageUsersMenuOption());
	}

};

