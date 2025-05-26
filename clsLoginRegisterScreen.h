#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
#include "ClsUtil.h"
using namespace std;
class clsLoginRegisterScreen : protected clsScreen
{
private:


    static void _PrintClientRecordLine(clsUser::stLoginRegister Log)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << Log.Date;
        cout << "| " << setw(10) << left << Log.UserName;
        cout << "| " << setw(10) << left << ClsUtil::clsUtil::deCryption(Log.Password);
        cout << "| " << setw(12) << left << Log.Permissions;

    }
public:
    static void ShowLogsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegisetir))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("Logs Register Screen");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date";
        cout << "| " << left << setw(10) << "Username";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        vector<clsUser::stLoginRegister> vLogs = clsUser::LoadLogsDataFromFile();
        for (clsUser::stLoginRegister i : vLogs)
        {
            _PrintClientRecordLine(i);
            cout << endl;
        }
    }
};