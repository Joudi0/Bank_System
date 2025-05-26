#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "ClsDateLib.h"

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber(string m = "\nPlease enter AccountNumber: ")
    {
        string AccountNumber = "";
        cout << m;
        cin >> AccountNumber;
        return AccountNumber;
    }
    static void PrintBill(clsBankClient Client1, clsBankClient Client2, double Amount)
    {
        cout << "Transferred Done from account: " << endl;
        _PrintClient(Client1);
        cout << "To account: " << endl;
        _PrintClient(Client2);
        cout << "\nAmount: " << Amount << "\n";
        cout << "Date:  ";
        cout << clsDate::DateToString(clsDate());
        cout << " - ";
        cout <<  clsDate::TimeNow();
        cout << "\n\nTransfer Done.\n";
    }
public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("Transfer Screen");
        string AccountNumber1 = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumber("\nPlease enter AccountNumber You want to transfer From:  ");
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        _PrintClient(Client1);
        string AccountNumber2 = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
            AccountNumber2 = _ReadAccountNumber("\nPlease enter AccountNumber You want to transfer To:  ");
        }
        while (AccountNumber2 == AccountNumber1)
        {
            cout << "\nCannot Transfer to the same Account.\n";
            AccountNumber2 = _ReadAccountNumber("\nPlease enter AccountNumber You want to transfer To:  ");
        }
        clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
        _PrintClient(Client2);
        double Amount = 0;
        cout << "\n";
        Amount = clsInputValidate::ReadNumberBetween<double>("Please enter Transfer amount ? ",0,Client1.AccountBalance);

        cout << "\nAre you sure you want to perform this Transfer? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Transfer(Client2,Amount);
            PrintBill(Client1, Client2, Amount);
        }
        else
        {
            cout << "Transfer Canceled.\n";
        }
    }
};