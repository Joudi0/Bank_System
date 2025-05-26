#pragma once
#include <string>
#include <iostream>
#include "ClsDateLib.h"

using namespace std;
namespace ClsUtil
{
    class clsUtil
    {
    public:
        static enum enType { smallL = 1, capitalL, spicial, number };
        static void Srand()
        {
            srand((unsigned)time(NULL));
        }
        static int ReadPositiveNumber(string m)
        {
            int num;
            do
            {
                cout << m;
                cin >> num;
            } while (num <= 0);
            return num;
        }
    
        static void Swap(int& n1, int& n2)
        {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }
        static void Swap(double& n1, double& n2)
        {
            double temp = n1;
            n1 = n2;
            n2 = temp;
        }
        static void Swap(bool& n1, bool& n2)
        {
            bool temp = n1;
            n1 = n2;
            n2 = temp;
        }
        static void Swap(string& n1, string& n2)
        {
            string temp = n1;
            n1 = n2;
            n2 = temp;
        }
        static void Swap(char& n1, char& n2)
        {
            char temp = n1;
            n1 = n2;
            n2 = temp;
        }
        static int RandomNumber(int From, int To)
        {
            return rand() % (1 + To - From) + From;
        }

        static void Shuffle(int arr[100], int l)
        {
            for (int i = 0; i < l; ++i)
            {
                Swap(arr[RandomNumber(1, l)], arr[RandomNumber(1, l)]);
            }
        }
        static void Shuffle(string arr[100], int l)
        {
            for (int i = 0; i < l; ++i)
            {
                Swap(arr[RandomNumber(1, l)], arr[RandomNumber(1, l)]);
            }
        }
        static char RandomChar(enType ch)
        {
            char c;
            switch (ch)
            {
            case enType::smallL:
                c = RandomNumber(97, 122);
                return c;
                break;
            case enType::capitalL:
                c = RandomNumber(65, 90);
                return c;
                break;
            case enType::spicial:
                c = RandomNumber(33, 47);
                return c;
                break;
            case enType::number:
                c = RandomNumber(48, 57);
                return c;
                break;
            default:
                return char(RandomNumber(65, 90));
                break;
            }
        }
        static string RandomWord(enType Type, int l)
        {
            string word = "";
            for (int i = 0; i < l; ++i)
            {
                word += RandomChar(Type);
            }
            return word;
        }
        static string RandomKey(enType type)
        {
            string w;
            string key = "";
            for (int i = 0; i < 4; ++i)
            {
                w = RandomWord(type, 4);
                key += w;
                if (i != 3) key += "-";
            }
            return key;
        }
        static void PrintKeys(int count, enType Type)
        {
            for (int i = 1; i <= count; ++i)
            {
                cout << "\n";
                cout << "Key[" << i << "] : " << RandomKey(Type) << endl;
            }
        }
        static void  SwapDates(clsDate& Date1, clsDate& Date2)
        {
            clsDate TempDate;
            TempDate = Date1;
            Date1 = Date2;
            Date2 = TempDate;
        }
        static void FillArrayWithRandNums(int arr[], short l, short from, short to)
        {

            for (int i = 0; i < l; ++i)
            {
                arr[i] = clsUtil::RandomNumber(from, to);
            }
        }
        static void FillArrayWithRandWords(string arr[], short l, enType Type, short WL = 8)
        {
            for (int i = 0; i < l; ++i)
            {
                arr[i] = clsUtil::RandomWord(Type,WL);
            }
        }
        static void FillArrayWithRandKeys(string arr[], short l, enType Type)
        {
            for (int i = 0; i < l; ++i)
            {
                arr[i] = clsUtil::RandomKey(Type);
            }
        }
        static void Tabs(short t)
        {
            for (short i = 0; i < t; ++i)
            {
                cout << "\t";
            }
        }
        static string enCryption(string text, short key = 2)
        {
            string result = "";
            for (int i = 0; i < text.length(); ++i)
                result += (text[i] ^ key) + i % 3;
            return result;
        }
        static string deCryption(string text, short key = 2)
        {
            string result = "";
            for (int i = 0; i < text.length(); ++i)
                result += (text[i] - i % 3) ^ key;
            return result;
        }
        static string NumberToText(int Number)
        {

            if (Number == 0)
            {
                return "";
            }

            if (Number >= 1 && Number <= 19)
            {
                string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
              "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

                return  arr[Number] + " ";

            }

            if (Number >= 20 && Number <= 99)
            {
                string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
                return  arr[Number / 10] + " " + NumberToText(Number % 10);
            }

            if (Number >= 100 && Number <= 199)
            {
                return  "One Hundred " + NumberToText(Number % 100);
            }

            if (Number >= 200 && Number <= 999)
            {
                return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
            }

            if (Number >= 1000 && Number <= 1999)
            {
                return  "One Thousand " + NumberToText(Number % 1000);
            }

            if (Number >= 2000 && Number <= 999999)
            {
                return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
            }

            if (Number >= 1000000 && Number <= 1999999)
            {
                return  "One Million " + NumberToText(Number % 1000000);
            }

            if (Number >= 2000000 && Number <= 999999999)
            {
                return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
            }

            if (Number >= 1000000000 && Number <= 1999999999)
            {
                return  "One Billion " + NumberToText(Number % 1000000000);
            }
            else
            {
                return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
            }


        }
    };
}
