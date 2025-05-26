#pragma once

#include <iostream>
#include <fstream>
#include "clsScreen.h"
#include "clsUser.h"
#include "ClsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "ClsDateLib.h"


class clsLoginScreen :protected clsScreen
{

private:
    static bool _Login()
    {
        bool LoginFaild = false;
        short trys = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You Have " << trys << " Trails to login\n";
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, ClsUtil::clsUtil::deCryption(Password));

            LoginFaild = CurrentUser.IsEmpty();
            
        } while (LoginFaild && --trys > 0);
        if (trys == 0) 
        {
            cout << "System Locked after 3 failed trys.\n";
            return false;
        }
        CurrentUser.SaveLog();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};

