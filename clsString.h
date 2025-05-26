#pragma once
#include <iostream>
#include "strings.h"

using namespace std;

class clsString
{

private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static void PrintFirstLetter(string text)
    {
        strings::PrintFirstLetter(text);
    }
    void PrintFirstLetter()
    {
        strings::PrintFirstLetter(_Value);
    }

    static void FirstLetterToUpper(string& text)
    {
        strings::FirstLetterToUpper(text);
    }
    void FirstLetterToUpper()
    {
        strings::FirstLetterToUpper(_Value);
    }

    static void FirstLetterToLower(string& text)
    {
        strings::FirstLetterToLower(text);
    }
    void FirstLetterToLower()
    {
        strings::FirstLetterToLower(_Value);
    }

    static string StringToUpper(string text)
    {
        strings::StringToUpper(text);
        return text;
    }
    void StringToUpper()
    {
        strings::StringToUpper(_Value);
    }

    static string StringToLower(string text)
    {
        strings::StringToLower(text);
        return text;
    }
    void StringToLower()
    {
        strings::StringToLower(_Value);
    }

    static short LowerCount(string& text)
    {
        return strings::LowerCount(text);
    }
    short LowerCount()
    {
        return strings::LowerCount(_Value);
    }

    static short UpperCount(string text)
    {
        return strings::UpperCount(text);
    }
    short UpperCount()
    {
        return strings::UpperCount(_Value);
    }

    static void Statistics(string text)
    {
        strings::Statistics(text);
    }
    void Statistics()
    {
        strings::Statistics(_Value);
    }

    static short CountChar(string text)
    {
        cout << "do you want case sensitive?(1/0) ";
        bool sen;
        cin >> sen;
        return strings::CountChar(text,strings::ReadCharacter(),sen);
    }
    short CountChar()
    {
        cout << "do you want case sensitive?(1/0) ";
        bool sen;
        cin >> sen;
        return strings::CountChar(_Value, strings::ReadCharacter(),sen);
    }

    static short CountVowels(string text)
    {
        return strings::CountVowels(text);
    }
    short CountVowels()
    {
        return strings::CountVowels(_Value);
    }

    static void StringVowels(string text)
    {
        strings::StringVowels(text);
    }
    short StringVowels()
    {
        strings::StringVowels(_Value);
    }

    static void PrintEachWord(string text)
    {
        strings::PrintEachWord(text);
    }
    short PrintEachWord()
    {
        strings::PrintEachWord(_Value);
    }

    static string TrimLeft(string text)
    {
        return strings::TrimLeft(text);
    }
    string TrimLeft()
    {
        return strings::TrimLeft(_Value);
    }

    static string TrimRight(string text)
    {
        return strings::TrimRight(text);
    }
    string TrimRight()
    {
        return strings::TrimRight(_Value);
    }

    static string TrimAll(string text)
    {
        return strings::TrimAll(text);
    }
    string TrimAll()
    {
        return strings::TrimAll(_Value);
    }

    static void ReverseWords(string& text)
    {
        strings::ReverseWords(text);
    }
    void ReverseWords()
    {
        strings::ReverseWords(_Value);
    }

    static vector<string> Split(string text,string d = "#//#")
    {
        return strings::MySplit(text,d);
    }
    vector<string> Split()
    {
        return strings::MySplit(_Value);
    }

    static string RemoveP(string text)
    {
        return strings::RemoveP(text);
    }
    string RemoveP()
    {
        return strings::RemoveP(_Value);
    }

    static short CountWords(string S1)
    {
        return strings::CountWords(S1);
    }

    short CountWords()
    {
        return strings::CountWords(_Value);
    };
    static void Reverse(string& word)
    {
        strings::Reverse(word);
    }
    void Reverse()
    {
        strings::Reverse(_Value);
    }
};
