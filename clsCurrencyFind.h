#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyFindScreen : protected clsScreen
{
private:


	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "Country Name: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Currency Name: " << Currency.CurrencyName() << endl;
		cout << "Currency Rate: " << to_string(Currency.Rate()) << endl;
	}
	static void _Show_Result(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "The Currency is not exist.\n";
		}
	}
public:

	static void ShowFindScreen()
	{
		clsScreen::_DrawScreenHeader("Currency Find Screen");
		cout << "[1] By Code\n[2] By Country Name\n";
		short ch = 0;
		cin >> ch;
		while (ch != 1 && ch != 2)
		{
			cout << "Invalid Number, Enter another choice: ";
			cin >> ch;
		}
		
		if (ch == 1)
		{
			cout << "Enter the code: ";
			string code;
			code = clsInputValidate::ReadString();
			clsString::StringToUpper(code);
			clsCurrency Result = clsCurrency::FindByCode(code);
			_Show_Result(Result);
		}
		else if (ch == 2)
		{
			string country;
			cout << "Enter the county name: ";
			country = clsInputValidate::ReadString();
			clsString::StringToUpper(country);
			clsCurrency Result = clsCurrency::FindByCountry(country);
			_Show_Result(Result);
		}
	}
};
