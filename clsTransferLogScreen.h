#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintLogRecord(string line)
    {
        vector<string> Lines = clsString::Split(line);
        cout << "\t\t| " << setw(20) << left << Lines.at(0);  // Date
        cout << "| " << setw(10) << left << Lines.at(1);     // S.AccNum
        cout << "| " << setw(10) << left << Lines.at(2);     // D.AccNum
        cout << "| " << setw(12) << left << Lines.at(3);     // Amount
        cout << "| " << setw(12) << left << Lines.at(4);     // S.Balance
        cout << "| " << setw(12) << left << Lines.at(5);     // D.Balance
        cout << "| " << setw(10) << left << Lines.at(6) << "|\n";  // Username

    }
    static  vector <string> _LoadLogsDataFromFile()
    {

        vector <string> vLogs;

        fstream MyFile;
        MyFile.open("Transfers.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
                vLogs.push_back(Line);
            }

            MyFile.close();

        }

        return vLogs;

    }
public:

    static void ShowTransferLogsScreen()
    {
        _DrawScreenHeader("Transfer Logs Screen");

        vector<string> Logs = _LoadLogsDataFromFile();
        cout << "\t\t________________________________________________________";
        cout << "__________________________________________________\n";

        cout << "\t\t| " << setw(20) << left << "Date";
        cout << "| " << setw(10) << left << "S.AccNum";
        cout << "| " << setw(10) << left << "D.AccNum";
        cout << "| " << setw(12) << left << "Amount";
        cout << "| " << setw(12) << left << "S.Balance";
        cout << "| " << setw(12) << left << "D.Balance";
        cout << "| " << setw(10) << left << "Username";
        cout << "|\n";

        cout << "\t\t________________________________________________________";
        cout << "__________________________________________________\n";
        for (string i : Logs)
        {
            _PrintLogRecord(i);
        }

    }

};