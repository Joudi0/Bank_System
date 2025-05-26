#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrencyList.h"
#include "clsCurrencyFind.h"
#include "clsCurrencyUpdateRate.h"
#include "clsCurrencyCalculator.h"

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:
	enum enCurrencyMenueOptions {
		eList = 1, eFind = 2,
		eUpdate_Rate = 3,
		eCalculator = 4
	};
	static void _List_Currency()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _Find_Currency()
	{
		clsCurrencyFindScreen::ShowFindScreen();
	}	
	static void _Update_Rate()
	{
		clsCurrencyUpdateRate::ShowUpdateScreen();
	}	
	static void _Currency_Calculator()
	{
		clsCurrencyCalculator::ShowCalculatorScreen();
	}

	static void _Menu()
	{
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
	}
	static short _Read_Choice()
	{
		cout << "Choose your option: ";
		short c;
		cin >> c;
		while (c < 1 || c > 5)
		{
			cout << "Inalid Choice, enter another choice: ";
			cin >> c;
		}
		return c;
	}
	static void _GoBackToCurrencyMenu()
	{
		cout << "\n\nPress any key to go back to Currency Menue...";
		system("pause>0");
		cout << endl;
		ShowCurrencyScreen();

	}
	static void _PerformCurrencyMenuOption(enCurrencyMenueOptions CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{
		case enCurrencyMenueOptions::eList:
		{
			system("cls");
			_List_Currency();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOptions::eFind:
		{
			system("cls");
			_Find_Currency();
			_GoBackToCurrencyMenu();
			break;
		}

		case enCurrencyMenueOptions::eUpdate_Rate:
		{
			system("cls");
			_Update_Rate();
			_GoBackToCurrencyMenu();
			break;
		}
		case enCurrencyMenueOptions::eCalculator:
		{
			system("cls");
			_Currency_Calculator();
			_GoBackToCurrencyMenu();
			break;
		}
		default :
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:

	static void ShowCurrencyScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("Currency Exchange Menue");
		_Menu();
		_PerformCurrencyMenuOption((enCurrencyMenueOptions)_Read_Choice());
	}
}; 