#pragma once
#include <iostream>
#include <iomanip>
#include <String>
#include <vector>
#include <cctype>
#include <fstream>
#include "Files.h";
#include "ClsUtil.h";

using namespace std;
namespace strings
{
    const string FN = "Bank.txt";
    const string UFN = "Users.txt";
    enum enMainMiue
    {
        Clients_List = 1,
        Add_Clients,
        Delete_Clients,
        Update_Clients,
        Find_Clients,
        Transactions,
        User_Managment,
        Logout
    };
    enum enTransactions { Deposit = 1, Withdraw, Balances, Main_minu};
    enum enUsersManagment
    {
        Users_List = 1,
        Add_User, 
        Delete_User,
        Update_User, 
        Find_User, 
        Main_Minu
    };
    int ReadInt(string m, short Min = 0, int Max = INT_MAX)
    {
        int i = INT_MIN;
        while (i <= Min || i > Max)
        {
            cout << m;
            cin >> i;
        }
        return i;
    }
    string ReadString(string m)
    {
        string s;
        cout << m;
        cin >> s;
        return s;
    }
    void PrintFirstLetter(string s)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isFirstLetter && s[i] != ' ') cout << s[i] << "\n";
            isFirstLetter = (s[i] == ' ');
        }
    }
    void FirstLetterToUpper(string& s)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isFirstLetter && s[i] != ' ')
            {
                s[i] = toupper(s[i]);
            }
            isFirstLetter = (s[i] == ' ');
        }
    }
    void FirstLetterToLower(string& s)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isFirstLetter && s[i] != ' ')
            {
                s[i] = tolower(s[i]);
            }
            isFirstLetter = (s[i] == ' ');
        }
    }
    void StringToUpper(string& s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            s[i] = toupper(s[i]);
        }
    }
    void StringToLower(string& s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            s[i] = tolower(s[i]);
        }
    }
    char ReadCharacter()
    {
        char c;
        cout << "Enter a Character: ";
        cin >> c;
        return c;
    }
    char Cinvert()
    {
        char c = ReadCharacter();
        return isupper(c) ? tolower(c) : toupper(c);
    }
    void Sinvert(string& s)
    {
        for (int i = 0; i < s.length();++i)
        {
            if (isupper(s[i])) s[i] = tolower(s[i]);
            else s[i] = toupper(s[i]);
        }
    }
    short LowerCount(string s)
    {
        short small = 0;
        for (int i = 0; i < s.length();++i)
        {
            if (islower(s[i])) small++;
        }
        return small;
    }
    short UpperCount(string s)
    {
        short capital = 0;
        for (int i = 0; i < s.length();++i)
        {
            if (isupper(s[i])) capital++;
        }
        return capital;
    }
    void Statistics(string s)
    {
        cout << "String Length: " << s.length()
            << "\nCapital Letters: " << UpperCount(s)
            << "\nSmall Letters: " << LowerCount(s) << endl;
    }
    int CountChar(string s, char c, bool sen = true)
    {
        short count = 0;
        if(sen)
        {
            for (short i = 0; i < s.length();++i)
            {
                if (c == s[i]) count++;
            }
        }
        else
        {
            for (short i = 0; i < s.length();++i)
            {
                if (tolower(c) == tolower(s[i])) count++;
            }
        }
        return count;
    } // aeiou
    bool IsVowel(char c)
    {
        c = tolower(c);
        string v = "aeiou";
        for (int i = 0; i < v.length();++i)
        {
            if (v[i] == c) return true;
        }
        return false;
    }
    int CountVowels(string s)
    {
        int C = 0;
        for(int i = 0; i < s.length();++i)
        {
            if (IsVowel(s[i])) C++;
        }
        return C;
    }
    void StringVowels(string s)
    {
        for (int i = 0; i < s.length();++i)
        {
            if (IsVowel(s[i])) cout << char(tolower(s[i])) << "  ";
        }
    }
    void PrintEachWord(string s)
    {
        string word = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ') word.push_back(s[i]);
            else
            {
                if(!word.empty())
                {
                    cout << word << "\n";
                    word.clear();
                }
            }
        }
        cout << word << "\n";
    }
    int CountWords(string s)
    {
        if (s.empty()) return 0;
        short count = 0;
        string word = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ') word.push_back(s[i]);
            else
            {
                if (!word.empty())
                {
                    count++;
                    word.clear();
                }
            }
        }
        return word.empty() ? count : ++count;
    }
    vector<string> MySplit(string s, string d = "#//#")
    {
        vector<string> vec;
        string word = "";
        short pos = 0;
        while ((pos = s.find(d)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != "")
            {
                vec.push_back(word);
            }
            s.erase(0, pos + d.length());
        }
        if (s != "") vec.push_back(s);
        return vec;
    }

    string TrimLeft(string s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s.at(i) != ' ') return s.substr(i,s.length()-i);
        }
        return "";
    }
    string TrimRight(string s)
    {
        for (short i = s.length()-1; i >= 0; --i)
        {
            if (s.at(i) != ' ') return s.substr(0,i+1);
        }
        return "";
    }
    string TrimAll(string& s)
    {
        return TrimLeft(TrimRight(s));
    }
    string MyJoin(vector<string> s, string d = " ")
    {
        string str = "";
        for (string& i : s)
        {
            str.append(i + d);
        }
        return str.substr(0,str.length()-d.length());
    }
    string MyJoin(string s[], short l, string d = " ")
    {
        string str = "";
        for (short i = 0; i < l; ++i)
        {
            str.append(s[i] + d);
        }
        return str.substr(0, str.length() - d.length());
    }
    void ReverseWords(string& s)
    {
        vector<string> vec = MySplit(s);
        string news = "";
        vector<string>::iterator it = vec.end();
        while(it != vec.begin())
        {
            --it;
            news.append(*it + " ");
        }
        s = news;
    }
    string MyReplace(string s,string word, string subw)
    {
        short pos = 0;
        while ((pos = s.find(word)) != string::npos)
        {
            s.replace(pos,word.length(), subw);
        }
    return s;
    }
    string MyReplace(string s, string word, string subw, bool match = true)
    {
        short pos = 0;
        if(match)
        {
            while ((pos = s.find(word)) != string::npos)
            {
                s = s.substr(0, pos) + subw + s.substr(pos + word.length(), s.length());
            }
        }
        else
        {
            StringToLower(s);
            StringToLower(word);
            while ((pos = s.find(word)) != string::npos)
            {
                s = s.substr(0, pos) + subw + s.substr(pos + word.length(), s.length());
            }
        }
        return s;
    }
    string RemoveP(string s)
    {
        string result = "";
        for (char& x : s)
        {
            if (isalpha(x) || isdigit(x) || x == ' ')
            {
                result.push_back(x);
            }
        }
        return result;
    }
    void Reverse(string& text)
    {

        string r = "";
        for (int i = text.length() - 1; i >= 0; --i)
        {
            r += text[i];
        }
        text = r;
    }
    struct strBankInfo
    {
        string name;
        string AccountNumber;
        string PinCode;
        string Phone;
        double AccountBalance;
    };
    short FindClientIndex(string AccNum);
    strBankInfo ReadBankInfo()
    {
        strBankInfo BankInfo;
        cout << "Enter Client Name: ";
        getline(cin >> ws, BankInfo.name);
        cout << "Enter The Account Number: ";
        getline(cin, BankInfo.AccountNumber);
        while (FindClientIndex(BankInfo.AccountNumber) > -1)
        {
            cout << "The Account Number is Exist, Please Try Another One: ";
            getline(cin, BankInfo.AccountNumber);
        }
        cout << "Enter The PinCode: ";
        getline(cin, BankInfo.PinCode);
        cout << "Enter The Phone Number: ";
        getline(cin, BankInfo.Phone);
        BankInfo.AccountBalance = ReadInt("Enter The Account Balance: ");
        cin.ignore();
        return BankInfo;
    }
    void PrintBankInfo(strBankInfo struc)
    {
        cout << "-----------------------------------------\n";
        cout << "Name           : " << struc.name << "\n";
        cout << "Account Number : " << struc.AccountNumber << "\n";
        cout << "PinCode        : " << struc.PinCode << "\n";
        cout << "Phone Number   : " << struc.Phone << "\n";
        cout << "Account Balance: " << struc.AccountBalance << endl;
        cout << "-----------------------------------------\n";
    }
    string ToOneLine(strBankInfo BankInfo,string sp = "#//#")
    {
        vector<string> s = {BankInfo.name,BankInfo.AccountNumber,BankInfo.PinCode,BankInfo.Phone,to_string(BankInfo.AccountBalance) };
        return MyJoin(s,sp);
    }
    strBankInfo ToStructure(string line,string sp = "#//#")
    {
        vector<string> vec = MySplit(line, sp);
        strBankInfo BankInfo;
        BankInfo.name = vec.at(0);
        BankInfo.AccountNumber = vec.at(1);
        BankInfo.PinCode = vec.at(2);
        BankInfo.Phone = vec.at(3);
        BankInfo.AccountBalance = stod(vec.at(4));
        return BankInfo;
    }
    vector<strBankInfo> FileToStrBankInfo(string FileName)
    {
        vector<strBankInfo> v;
        fstream file;
        file.open(FileName, ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                v.push_back(ToStructure(line));
            }
        }
        file.close();
        return v;
    }
    vector<strBankInfo> ReadClients()
    {
        vector<strBankInfo> Clients;
        char a = 'y';
        while ((tolower(a) == 'y'))
        {
            cout << "Enter The Client Information: \n";
            strBankInfo Info = ReadBankInfo();
            Clients.push_back(Info);
            cout << "Do You Want To Add More Clients(y/n): ";
            cin >> a;
            while (tolower(a) != 'n' && tolower(a) != 'y')
            {
                cout << "Incorrect Answer, Please Enter (y/n): ";
                cin >> a;
            }
            system("cls");
        }
        return Clients;
    }
    vector<string> ClientsToString(vector<strBankInfo> vec)
    {
        vector<string> NewVec;
        for (strBankInfo& i : vec)
        {
            NewVec.push_back(ToOneLine(i, "#//#"));
        }
        return NewVec;
    }
    void ClientsToFile(vector<string> vec, string FileName)
    {
        files::vectortofile(FileName, vec);
    }
    void NewClientsToFile(vector<string> vec, string FileName)
    {
        files::NewVectorToFile(FileName, vec);
    }
    void ShowClients(string FileName = "Bank.txt")
    {
        vector<string> vec = files::filetovector(FileName);
        cout << setw(34) << "Clients List (" << vec.size() << ") Client(s).\n";
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "\n|" << setw(20) << "Client Name";
        cout << "|" << setw(14) << "Account Number";
        cout << "|" << setw(8) << "Pin Code";
        cout << "|" << setw(12) << "Phone Number";
        cout << "|" << setw(13) << "Balance\n";
        cout << "\n-----------------------------------------------------------------------\n";
        for (string i : vec)
        {
            vector<string> I = MySplit(i, "#//#");
            cout << "|" << setw(20) << I.at(0);
            cout << "|" << setw(14) << I.at(1);
            cout << "|" << setw(8) << I.at(2);
            cout << "|" << setw(12) << I.at(3);
            cout << "|" << setw(11) << I.at(4) << endl;
        }
        cout << "\n-----------------------------------------------------------------------\n";
    }
    void ShowUsers(string FileName = "Users.txt")
    {
        vector<string> vec = files::filetovector(FileName);
        cout << setw(34) << "Users List (" << vec.size() << ") User(s).\n";
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "\n|" << setw(20) << "Username";
        cout << "|" << setw(20) << "Password";
        cout << "|" << setw(12) << "Permissions\n";
        cout << "\n-----------------------------------------------------------------------\n";
        for (string i : vec)
        {
            if (i == "") continue;
            vector<string> I = MySplit(i, "#//#");
            cout << "|" << setw(20) << I.at(0);
            cout << "|" << setw(20) << I.at(1);
            cout << "|" << setw(12) << I.at(2) << endl;
        }
        cout << "\n-----------------------------------------------------------------------\n";
    }
    int TotalBalances(vector<strBankInfo> vec)
    {
        double total = 0;
        for (short i = 0; i < vec.size(); ++i)
        {
            total += vec.at(i).AccountBalance;
        }
        return total;
    }
    void ShowClientsBalances(string FileName)
    {
        vector<string> vec = files::filetovector(FileName);
        cout << setw(34) << "Clients List (" << vec.size() << ") Clients(s).\n";
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "\n|" << setw(14) << "Account Number";
        cout << "|" << setw(20) << "Client Name";
        cout << "|" << setw(13) << "Balance\n";
        cout << "\n-----------------------------------------------------------------------\n";
        for (string i : vec)
        {
            vector<string> I = MySplit(i, "#//#");
            cout << "|" << setw(14) << I.at(1);
            cout << "|" << setw(20) << I.at(0);
            cout << "|" << setw(11) << I.at(4) << endl;
        }
        cout << "\n-----------------------------------------------------------------------\n";
        vector<strBankInfo> VEC = FileToStrBankInfo(FN);
        cout << "                   Total Balances: " << TotalBalances(VEC);
    }
    short FindClientIndex(string AccNum)
    {
        vector<strBankInfo> vec = FileToStrBankInfo(FN);
        for (short i = 0; i < vec.size(); ++i)
        {
            if (AccNum == vec.at(i).AccountNumber)
            {
                return i;
            }
        }
        return -1;
    }
    void LoadClientInfo(strBankInfo& Client, short index)
    {
        vector<strBankInfo> vec = FileToStrBankInfo(FN);
        Client = vec.at(index);
    }
    void DeleteClient(string AccNum)
    {
        strBankInfo c;
        short index = FindClientIndex(AccNum);
        LoadClientInfo(c, index);
        if (index > -1)
        {
            PrintBankInfo(c);
            cout << "Are You Sure You Want To Delete This Client?: ";
            char answer;
            cin >> answer;
            while (toupper(answer) != 'Y' && toupper(answer) != 'N')
            {
                cout << "Invalid Answer, Please Enter (Y,N): ";
                cin >> answer;
            }
            if (toupper(answer) == 'Y')
            {
                vector<strBankInfo> vec = FileToStrBankInfo(FN);
                vector<string> StrVec = ClientsToString(vec);
                files::delet(FN,StrVec.at(index));
                cout << "Account Deleted Successfully!";
            }
            else
            {
                cout << "The Account Has Not Been Deleted";
            }
        }
        else
        {
            cout << "Client With Account Number: " << AccNum << " Does Not Exist.\n";
        }
    }
    strBankInfo UpdateClientInfo(strBankInfo OldClient)
    {
        strBankInfo BankInfo;
        cout << "Enter Client Name: ";
        getline(cin >> ws, BankInfo.name);
        cout << "Enter The PinCode: ";
        getline(cin, BankInfo.PinCode);
        cout << "Enter The Phone Number: ";
        getline(cin, BankInfo.Phone);
        BankInfo.AccountBalance = ReadInt("Enter The Account Balance: ");
        cin.ignore();
        BankInfo.AccountNumber = OldClient.AccountNumber;
        return BankInfo;
    }
    void UpdateClient(string OldAccNum)
    {
        strBankInfo c;
        short index = FindClientIndex(OldAccNum);
        LoadClientInfo(c, index);
        if (index > -1)
        {
            PrintBankInfo(c);
            cout << "Are You Sure You Want To Update This Client?: ";
            char answer;
            cin >> answer;
            while (toupper(answer) != 'Y' && toupper(answer) != 'N')
            {
                cout << "Invalid Anser, Please Enter (Y,N): ";
                cin >> answer;
            }
            if (toupper(answer) == 'Y')
            {
                vector<strBankInfo> vec = FileToStrBankInfo(FN);
                vector<string> StrVec = ClientsToString(vec);
                strBankInfo BankInfo = UpdateClientInfo(vec.at(index));
                string NewClient = ToOneLine(BankInfo);
                files::update(FN, StrVec.at(index),NewClient);
                cout << "Account Updated Successfully!";
            }
            else
            {
                cout << "The Account Has Not Been Updated";
            }
        }
        else
        {
            cout << "Client With Account Number: " << OldAccNum << " Does Not Exist.\n";
        }
    }
    void ShowMinu()
    {
        ClsUtil::clsUtil::Tabs(5);
        cout << "Welcome To The Bank System\n";
        ClsUtil::clsUtil::Tabs(3);
        cout << "=========================================================\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[1] Show Client List\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[2] Add New Client\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[3] Delete Client\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[4] Update Client Info\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[5] Find Client\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[6] Transactions Minu\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[7] Users Managment\n";
        ClsUtil::clsUtil::Tabs(5);
        cout << "[8] Logout\n";
        ClsUtil::clsUtil::Tabs(3);
        cout << "=========================================================\n";
    }
    void ShowTransMinu()
    {
        cout << "\t\tWelcome To Transactions Minu\n";
        cout << "=========================================================\n";
        cout << "\t\t[1] Deposit\n";
        cout << "\t\t[2] Withdraw\n";
        cout << "\t\t[3] Total Balances\n";
        cout << "\t\t[5] Logout\n";
        cout << "=========================================================\n";
    }
    void ShowATMMinu()
    {
        cout << "\t\tWelcome To ATM Minu\n";
        cout << "=========================================================\n";
        cout << "\t\t[1] Quick Withdraw\n";
        cout << "\t\t[2] Normal Withdraw\n";
        cout << "\t\t[3] Deposit\n";
        cout << "\t\t[4] My Balance\n";
        cout << "\t\t[5] Logout\n";
        cout << "=========================================================\n";
    }
    enum enATM {QuickW = 1, NormalW, enATMDeposit, Balance, enATMLogout};
    bool ATMLoginCheck(string AccNum, string Pincode)
    {
        strBankInfo BI;
        short index = FindClientIndex(AccNum);
        if(index > -1)
        {
            LoadClientInfo(BI, index);
            return BI.PinCode == Pincode;
        }
        return false;
    }
    void QuickWithdrawScreen()
    {
        cout << "=================================\n";
        cout << "\tQuick Withdraw\n";
        cout << "=================================\n";
        cout << "[1] 20  [2] 50\n[3] 100\t[4] 200\n[5] 400\t[6] 600\n[7] 800\t[8] 1000\n[9] Exit\n";
        cout << "=================================\n";
    }
    void ShowUsersMinu()
    {
        cout << "\t\tWelcome to User Management Minu\n";
        cout << "======================================================\n";
        cout << "\t\t[1] List User\n";
        cout << "\t\t[2] Add User\n";
        cout << "\t\t[3] Delete User\n";
        cout << "\t\t[4] Update User\n";
        cout << "\t\t[5] Find User\n";
        cout << "\t\t[6] Main Minu\n";
        cout << "======================================================\n";
    }
    int TakeChoice()
    {
        short Choice;
        cout << "Choose What Do You Want To Do [1 to 8]: ";
        cin >> Choice;
        while (Choice < 1 || Choice > 8)
        {
            cout << "Invalid Choice, Please Enter Between 1 And 8: ";
            cin >> Choice;
        }
        return Choice;
    }
    int TakeTransChoice()
    {
        short Choice;
        cout << "Choose What Do You Want [1 to 4]: ";
        cin >> Choice;
        while (Choice < 1 || Choice > 4)
        {
            cout << "Invalid Choice, Please Enter Between 1 And 4: ";
            cin >> Choice;
        }
        return Choice;
    }
    void LeaveCurrent()
    {
        string leave = " ";
        cout << "\nPlease Enter Any Key To Return To The Menu: ";
        cin >> leave;
    }
    void deposit(string AccNum)
    {
        strBankInfo BI;
        int i = FindClientIndex(AccNum);
        LoadClientInfo(BI, i);
        PrintBankInfo(BI);
        double money = -1;
        money = ReadInt("How Much Do You Want To Add: ",0);
        vector<strBankInfo> vec = FileToStrBankInfo(FN);
        vec.at(i).AccountBalance += money;
        vector<string> VEC = ClientsToString(vec);
        NewClientsToFile(VEC,FN);
    }
    bool IsMoneyInBalance(string AccNum, int money)
    {
        strBankInfo BI;
        int i = FindClientIndex(AccNum);
        LoadClientInfo(BI, i);
        return money <= BI.AccountBalance;
    }
    void withdraw(string AccNum)
    {
        strBankInfo BI;
        int i = FindClientIndex(AccNum);
        LoadClientInfo(BI,i);
        PrintBankInfo(BI);
        int money = 0;
        money = ReadInt("How Much Do You Want To withdraw: ");
        vector<strBankInfo> vec = FileToStrBankInfo(FN);
        if (money > BI.AccountBalance || money <= 0 || money % 5 != 0)
        {
            money = ReadInt("Invalid Number, Please Enter in Your Balance Range a number Divisible by 5 And Positive: ", 5, BI.AccountBalance + 1);
        }
        char c = 'k';
        cout << "Are You sure you want to withdraw?: ";
        cin >> c;
        while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
        {
            cout << "Invalid Answer, Please Enter(y,n): ";
            cin >> c;
        }
        if (c == 'n' || c == 'N') return;
        vec.at(i).AccountBalance -= money;
        vector<string> VEC = ClientsToString(vec);
        NewClientsToFile(VEC, FN);
    }
    void withdraw(string AccNum, int money)
    {
        strBankInfo BI;
        int i = FindClientIndex(AccNum);
        LoadClientInfo(BI, i);
        PrintBankInfo(BI);
        cout << "Are You sure you want to withdraw?: ";
        char c = 'k';
        while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
        {
            cout << "Invalid Answer, Please Enter(y,n): ";
            cin >> c;
        }
        if (c == 'n' || c == 'N') return;
        vector<strBankInfo> vec = FileToStrBankInfo(FN);
        vec.at(i).AccountBalance -= money;
        vector<string> VEC = ClientsToString(vec);
        NewClientsToFile(VEC, FN);
    }
    void QuickWithdraw(string AccNum)
    {
        vector<int> money = { 20,50,100,200,400,600,800,1000 };
        short ch = ReadInt("Choose what to withdraw from [1] to [8]: ", 1, 9);
        if (ch == 9) return;
        else
        {
            while (!IsMoneyInBalance(AccNum, money.at(ch - 1)))
            {
                cout << "You Do not have this amount of money, please choose in ypur range balance: \n";
                short ch = ReadInt("Choose what to withdraw from [1] to [8]: ", 1, 10);
            }
            withdraw(AccNum, money.at(ch - 1));
        }
        cout << "Withdraw Completed, Done.\n";
    }
    strBankInfo ATMLogin()
    {
        string AccNum = "";
        string Pincode = "";
        cout << "===================================================\n";
        cout << "\t\t Login Screen";
        cout << "\n===================================================\n";
        AccNum = to_string(ReadInt("Enter Your Account Number: "));
        Pincode = to_string(ReadInt("Enter Your Pincode: "));
        while (!ATMLoginCheck(AccNum, Pincode))
        {
            cout << "===================================================\n";
            cout << "\t\t Login Screen";
            cout << "\n===================================================\n";
            cout << "Wrong Accout number/Pin Code, Please try again\n";
            AccNum = to_string(ReadInt("Enter Your Account Number: "));
            Pincode = to_string(ReadInt("Enter Your Pincode: "));
        }
        strBankInfo BI;
        LoadClientInfo(BI, FindClientIndex(AccNum));
        return BI;
    }
    void ATMSystem()
    {
        enATM C;
        strBankInfo BI = ATMLogin();
        while (true) {
            cout << "Welcome in the ATM System!\n";
            system("cls");
            ShowATMMinu();
            C = (enATM)ReadInt("Choose a Number from 1 to 5: ");
            switch (C)
            {
            case enATM::QuickW:
            {
                QuickWithdrawScreen();
                QuickWithdraw(BI.AccountNumber);
                LoadClientInfo(BI, FindClientIndex(BI.AccountNumber));
                LeaveCurrent();
                break;
            }
            case enATM::NormalW:
            {
                withdraw(BI.AccountNumber);
                LoadClientInfo(BI, FindClientIndex(BI.AccountNumber));
                LeaveCurrent();
                break;
            }
            case enATM::enATMDeposit:

                deposit(BI.AccountNumber);
                LoadClientInfo(BI, FindClientIndex(BI.AccountNumber));
                LeaveCurrent();
                break;
            case enATM::Balance:
            {
                cout << "Balance: " << BI.AccountBalance << endl;
                LeaveCurrent();
                break;
            }
            case enATM::enATMLogout:
                cout << "Logout Done Successfuly!\n";
                return;
            default:
                break;
            }
        }
    }
    void TransSystem()
    {
        short choice = 0;
        enTransactions C;
        while (true) {
            system("cls");
            ShowTransMinu();
            choice = TakeTransChoice();
            C = enTransactions(choice);
            switch (C)
            {
            case enTransactions::Deposit:
            {
                string ac = ReadString("Enter The Account Number: ");
                while(FindClientIndex(ac) < 0)
                {
                    ac = ReadString("The ID not exist ,Enter Correct Account Number: ");
                }
                deposit(ac);
                LeaveCurrent();
                break;
            }
            case enTransactions::Withdraw:
            {
                string ac = ReadString("Enter The Account Number: ");
                while (FindClientIndex(ac) < 0)
                {
                    ac = ReadString("The ID not exist ,Enter Correct Account Number: ");
                }
                withdraw(ac);
                LeaveCurrent();
                break;
            }
            case enTransactions::Balances:
                ShowClientsBalances(FN);
                LeaveCurrent();
                break;
            case enTransactions::Main_minu:
                return;
            default:
                break;
            }
        }
    }
    struct strUserAccount { string Username = ""; string Password = ""; short Permissons = 0; };
    short ReadPermissons()
    {
        short p = 0;
        char a;
        cout << "Do you want the user with full access?: ";
        cin >> a;
        if (tolower(a) == 'y') return -1;
        else
        {
            cout << "Do you want to give access to: \n";
            cout << "List Clients: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 1;
            cout << "Add Clients: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 2;   
            cout << "Delete Clients: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 4;  
            cout << "Update Clients: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 8;  
            cout << "Find Clients: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 16;
            cout << "Transactions: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 32;
            cout << "Users Managment: ";
            cin >> a;
            if (tolower(a) == 'y') p |= 64;
        }
        return p;
    }
    strUserAccount TostrUserAccount(string line, string sp = "#//#")
    {
        vector<string> vec = MySplit(line, sp);
        strUserAccount UserAccount;
        UserAccount.Username = vec.at(0);
        UserAccount.Password = vec.at(1);
        UserAccount.Permissons = stoi(vec.at(2));
        return UserAccount;
    }
    vector<strUserAccount> FileTostrUserAccount(string FileName = "Users.txt")
    {
        vector<strUserAccount> v;
        fstream file;
        file.open(FileName, ios::in);
        if (file.is_open()) {
            string line;

            while (getline(file, line) && line != "")
            {
                v.push_back(TostrUserAccount(line));
            }
        }
        file.close();
        return v;
    }
    short FindUserIndex(string Username)
    {
        vector<strUserAccount> vec = FileTostrUserAccount(UFN);
        short x = 0;
        for (short i = 0; i < vec.size(); ++i)
        {
            if (Username == vec.at(i).Username)
            {
                return i;
            }
            x = i;
        }
        return -1;
    }
    void LoadUserInfo(strUserAccount& User, short index)
    {
        vector<strUserAccount> vec = FileTostrUserAccount(UFN);
        User = vec.at(index);
    }
    strUserAccount ReadUser()
    {
        strUserAccount User;
        cout << "Enter Username: ";
        cin >> User.Username;
        while (FindUserIndex(User.Username) > -1)
        {
            cout << "The Username is already exist, please enter another username: ";
            cin >> User.Username;
        }
        cout << "Enter Password: ";
        cin >> User.Password;
        User.Permissons = ReadPermissons();
        return User;
    }
    vector<strUserAccount> ReadUsers()
    {
        vector<strUserAccount> Users;
        char a = 'y';
        while ((tolower(a) == 'y'))
        {
            cout << "Enter The User Information: \n";
            strUserAccount Info = ReadUser();
            Users.push_back(Info);
            cout << "Do You Want To Add More Users(y/n): ";
            cin >> a;
            while (tolower(a) != 'n' && tolower(a) != 'y')
            {
                cout << "Incorrect Answer, Please Enter (y/n): ";
                cin >> a;
            }
            system("cls");
        }
        return Users;
    }
    string ToOneLine(strUserAccount UserAccount, string sp = "#//#")
    {
        vector<string> s = { UserAccount.Username ,UserAccount.Password,to_string(UserAccount.Permissons) };
        return MyJoin(s, sp);
    }
    vector<string> ClientsToString(vector<strUserAccount> vec)
    {
        vector<string> NewVec;
        for (strUserAccount& i : vec)
        {
            NewVec.push_back(ToOneLine(i));
        }
        return NewVec;
    }
    bool CheckLogin(string u, string p)
    {
        strUserAccount user;
        short index = FindUserIndex(u);
        if (index > -1) 
        {
            LoadUserInfo(user,index);
            return user.Password == p;
        }
        return false;
    }
    void PrintUser(strUserAccount User)
    {
        cout << "Username: " << User.Username << endl;
        cout << "Password: " << User.Password << endl;
        cout << "Permissions: " << User.Permissons << endl;
    }
    void DeleteUser(string Username)
    {
        strUserAccount c;
        short index = FindUserIndex(Username);
        LoadUserInfo(c, index);
        if (index > -1)
        {
            if (c.Permissons == -1)
            {
                cout << "Cannot delete admins\n";
                return ;
            }
            PrintUser(c);
            cout << "Are You Sure You Want To Delete This User?: ";
            char answer;
            cin >> answer;
            while (toupper(answer) != 'Y' && toupper(answer) != 'N')
            {
                cout << "Invalid Anser, Please Enter (Y,N): ";
                cin >> answer;
            }
            if (toupper(answer) == 'Y')
            {
                vector<strUserAccount> vec = FileTostrUserAccount(UFN);
                vector<string> StrVec = ClientsToString(vec);
                files::delet(UFN, StrVec.at(index));
                cout << "Account Deleted Successfully!";
            }
            else
            {
                cout << "The Account Has Not Been Deleted";
            }
        }
        else
        {
            cout << "Client With Account Number: " << Username << " Does Not Exist.\n";
        }
    }
    void UpdateUserInfo(strUserAccount& User)
    {
        cout << "Enter New Password: ";
        cin >> User.Password;
        cout << "Enter New Permissions: ";
        User.Permissons = ReadPermissons();
        cin.ignore();
    }
    void UpdateUser()
    {
        string Username;
        cout << "Enter The Username: ";
        cin >> Username;
        short index = FindUserIndex(Username);
        if (index > -1)
        {
            vector<strUserAccount> vec = FileTostrUserAccount(UFN);
            vector<string> StrVec = ClientsToString(vec);
            PrintUser(vec.at(index));
            cout << "Are You Sure You Want To Update This User?: ";
            char answer;
            cin >> answer;
            cin.ignore();
            while (toupper(answer) != 'Y' && toupper(answer) != 'N')
            {
                cout << "Invalid Anser, Please Enter (Y,N): ";
                cin >> answer;
            }
            if (toupper(answer) == 'Y')
            {
                UpdateUserInfo(vec.at(index));
                string NewClient = ToOneLine(vec.at(index));
                files::update(UFN, StrVec.at(index), NewClient);
                cout << "Account Updated Successfully!";
            }
            else
            {
                cout << "The Account Has Not Been Updated";
            }
        }
        else
        {
            cout << "Client With Account Number: " << Username << " Does Not Exist.\n";
        }
    }
    void UsersManagment()
    {
        short choice = 0;
        enUsersManagment C;
        do
        {
            system("cls");
            ShowUsersMinu();
            cout << "Choose an option: ";
            cin >> choice;
            C = enUsersManagment(choice);
            switch(C)
            {
            case enUsersManagment::Users_List:
                cout << "----------------------------------\n";
                cout << "\tShow Users Screen";
                cout << "\n----------------------------------\n";
                ShowUsers();
                LeaveCurrent();
                break;

            case enUsersManagment::Add_User:
                {
                    cout << "----------------------------------\n";
                    cout << "\tAdd Client Screen";
                    cout << "\n----------------------------------\n";
                    vector<strUserAccount> vec;
                    vector<string> StrVec;
                    vec = ReadUsers();
                    StrVec = ClientsToString(vec);
                    ClientsToFile(StrVec, UFN);
                    LeaveCurrent();
                    break;
                }
            case enUsersManagment::Delete_User:
                {
                cout << "----------------------------------\n";
                cout << "\tDelete User Screen";
                cout << "\n----------------------------------\n";
                string username;
                cout << "Enter The Username: ";
                cin >> username;
                DeleteUser(username);
                LeaveCurrent();
                break;
            }
            case enUsersManagment::Update_User:
                cout << "----------------------------------\n";
                cout << "\tUpdate User Screen";
                cout << "\n----------------------------------\n";
                UpdateUser();
                LeaveCurrent();
                break;
            case enUsersManagment::Find_User:
            {
                string username;
                cout << "Enter The Username: ";
                cin >> username;
                strUserAccount User;
                short i = FindUserIndex(username);
                if (i > -1)
                {
                    LoadUserInfo(User,i);
                    PrintUser(User);
                }
                else cout << "User Not Found\n";
                LeaveCurrent();
                break;
            }
            case enUsersManagment::Main_Minu:
                break;
            default:
                break;
            }
        } while (choice != 6);
    }
    void BankSystem()
    {
        short Choice = 0;
        enMainMiue C;
        strUserAccount User;
        cout << "Enter Your Username: ";
        cin >> User.Username;
        cout << "Enter Your Password: ";
        cin >> User.Password;
        while(true)
        {
            if (CheckLogin(User.Username, User.Password)) break;
            system("cls");
            cout << "Incorrect Username Or Password\n";
            cout << "Enter Your Username: ";
            cin >> User.Username;
            cout << "Enter Your Password: ";
            cin >> User.Password;
        } 
        LoadUserInfo(User, FindUserIndex(User.Username));
        while(Choice != 8)
        {
            system("cls");
            ShowMinu();
            Choice = TakeChoice();
            string leave = " ";
            C = enMainMiue(Choice);
            switch (C)
            {
            case enMainMiue::Clients_List:
                if ((User.Permissons & 1) != 1 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                ShowClients(FN);
                LeaveCurrent();
                break;
            case enMainMiue::Add_Clients:
            {
                if ((User.Permissons & 2) != 2 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                cout << "----------------------------------\n";
                cout << "\tAdd Client Screen";
                cout << "\n----------------------------------\n";
                vector<strBankInfo> vec;
                vector<string> StrVec;
                vec = ReadClients();
                StrVec = ClientsToString(vec);
                ClientsToFile(StrVec, FN);
                LeaveCurrent();
                break;
            }
            case enMainMiue::Delete_Clients:
            {
                if ((User.Permissons & 3) != 3 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                cout << "----------------------------------\n";
                cout << "\tDelete Client Screen";
                cout << "\n----------------------------------\n";
                string num;
                cout << "Enter The Account Number: ";
                cin >> num;
                DeleteClient(num);
                LeaveCurrent();
                break;
            }
            case enMainMiue::Update_Clients:
            {
                if ((User.Permissons & 4) != 4 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                cout << "----------------------------------\n";
                cout << "\tUpdate Client Screen";
                cout << "\n----------------------------------\n";
                string num = ReadString("Enter The Account Number: ");
                UpdateClient(num);
                LeaveCurrent();
                break;
            }
            case enMainMiue::Find_Clients:
            {
                if ((User.Permissons & 5) != 5 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                cout << "----------------------------------\n";
                cout << "\tSearch Client Screen";
                cout << "\n----------------------------------\n";
                string num = ReadString("Enter The Account Number: ");
                strBankInfo BI;
                short i = FindClientIndex(num);
                if (i == -1) cout << "Account is not exist." << endl;
                else
                {
                    LoadClientInfo(BI, i);
                    PrintBankInfo(BI);
                }
                LeaveCurrent();
                break;
            }
            case enMainMiue::Transactions:
                if ((User.Permissons & 6) != 6 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                TransSystem();
                break;
            case enMainMiue::User_Managment:
                if ((User.Permissons & 7) != 7 && User.Permissons != -1)
                {
                    cout << "-------------------------------------\n";
                    cout << "Access Dined, Please Call your admin\n";
                    cout << "-------------------------------------\n";
                    LeaveCurrent();
                    break;
                }
                UsersManagment();
                break;
            case enMainMiue::Logout:
                cout << "----------------------------------\n";
                cout << "\tProgram Ends :-)";
                cout << "\n----------------------------------\n";
                return;
            default:
                break;
            }
        }
    }
}