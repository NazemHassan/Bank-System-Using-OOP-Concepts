#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n_____________________";
        cout << "\nFirst Name : " << User.FirstName;
        cout << "\nLast Name  : " << User.LastName;
        cout << "\nFull Name  : " << User.FullName();
        cout << "\nEmail      : " << User.Email;
        cout << "\nPhone      : " << User.Phone;
        cout << "\nUser Name : " << User.UserName;
        cout << "\nPassword   : " << User.Password;
        cout << "\nPermissions    : " << User.Permissions;
        cout << "\n_____________________";

    }

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t    Delete User Screen");

        string UserName = "";

        cout << "Please enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this user? y/n? ";
        char Answer;
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser deleted successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError, User was Not deleted :-(\n";
            }
        }

    }

};


