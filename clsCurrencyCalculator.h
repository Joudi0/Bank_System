#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h" 
#include "clsCurrency.h"
#include "clsString.h"
#include <iostream>
class clsCurrencyCalculator : protected clsScreen
{
private:
	static float _ReadAmount(string m = "")
	{
		float amount = -1;
		while (amount < 0)
		{
			amount = clsInputValidate::ReadNumber<double>(m);
		}
		return amount;
	}
	static clsCurrency _ReadCode(string m = "")
	{
		string code = "";
		do 
		{
			code = clsInputValidate::ReadString(m);
		} while (!clsCurrency::IsCurrencyExist(code));
		clsCurrency C = clsCurrency::FindByCode(code);
		return C;
	}

	static float exchange(clsCurrency C1, clsCurrency C2)
	{

		if (clsString::StringToUpper(C1.CurrencyCode()) == clsString::StringToUpper(C2.CurrencyCode()))
		{
			cout << "Can not Convert to the same currency\n";
		}
		float amount = _ReadAmount("Enter amount: ");
		if (clsString::StringToUpper(C1.CurrencyCode()) == "USD" || clsString::StringToUpper(C2.CurrencyCode()) == "USD")
		{
			return amount * C2.Rate() / C1.Rate();
		}
		else
		{
			float r = C1.ConvertToUSD(amount);
			cout << "Convert from: ";
			clsCurrency::PrintCurrency(C1);
			cout << amount << " " << C1.CurrencyCode() << " = " << r << endl;
			cout << "Convert from usd to:\n";
			clsCurrency::PrintCurrency(C2);
			cout << amount << " " << C2.CurrencyCode() << " = " << C1.ConvertToOtherCurrency(amount, C2) << endl;
			return C1.ConvertToOtherCurrency(amount, C2);
		}
		return 0;
	}

public:

	static void ShowCalculatorScreen()
	{
		char c = 'y';
		while (c == 'y')
		{
			clsScreen::_DrawScreenHeader("Exchange Screen");
			cin.ignore();
			clsCurrency C1 = _ReadCode("Enter code number 1: ");
			clsCurrency C2 = _ReadCode("Enter code number 2: ");
			cout << "Result: " << exchange(C1, C2) << endl;

			cout << "Do You want to do another exchange?: ";
			cin >> c;

			while (c != 'y' && c != 'n')
			{
				cout << "invalid answer, try again: ";
				cin >> c;
			}
		}

	}
};