#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyUpdateRate : protected clsScreen
{
private:
	static float _ReadRate()
	{
		cout << "\nEnter the new Rate: ";
		float rate;
		rate = clsInputValidate::ReadNumber<double>();
		return rate;
	}

public:
	static void ShowUpdateScreen()
	{
		clsScreen::_DrawScreenHeader("Update Currency Screen");
		string code = "";
		do{
			code = clsInputValidate::ReadString("Enter the Code: ");
		} while (!clsCurrency::IsCurrencyExist(code));
		clsCurrency r = clsCurrency::FindByCode(code);
		clsCurrency::PrintCurrency(r);
		char answer;
		do
		{
			cout << "\nAre you sure you want to change Rate: ";
			cin >> answer;
		} while (tolower(answer) != 'y' && tolower(answer) != 'n');
		if (tolower(answer) == 'y')
		{

			r.UpdateRate(_ReadRate());
			clsCurrency::PrintCurrency(r);

			cout << "\nRate Updated Successfully.\n";

		}
		else
		{
			cout << "Update Cancelled.\n";

		}
	}

};