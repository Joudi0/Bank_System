#pragma once
#include <iostream>
#include <string>
#include <limits>
class clsInputValidate
{
public:
	template <typename T>
	static bool IsNumberBetween(T n, T start, T end)
	{
		return n <= end && n >= start;
	}
	static bool IsDateBetween(clsDate d, clsDate d1, clsDate d2)
	{
		if (clsDate::IsDate1AfterDate2(d1, d2)) clsDate::SwapDates(d1, d2);
		return clsDate::IsDate1BeforeDate2(d, d2) && clsDate::IsDate1AfterDate2(d, d1);
	}
	template<typename R>

	static R ReadNumber(string m = "")
	{
		cout << m;
		R n = 0;
		cin >> n;
		while (true)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "InValid Number, Try Again: ";
				cin >> n;
			}
			else break;
		}
		return n;
	}
	template<typename L>
	static L ReadNumberBetween(string m, L s, L e)
	{
		L n = ReadNumber<L>(m);
		while (!IsNumberBetween(n, s, e))
		{
			n = ReadNumber<L>("InValid Number, Try Again: ");
		}
		return n;
	}
  	static string ReadString(string mm = "")
	{
		string m;

		do
		{
			
			cout << mm << endl;
			getline(cin, m);
		} while (m.empty());
		return m;
	}
	static bool IsValidDate(clsDate D)
	{
		return clsDate::IsValidDate(D);
	}

};
