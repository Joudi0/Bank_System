#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
namespace files
{
    // from file to vector
    vector<string> filetovector(string filename)
    {
        vector<string> v;
        fstream file;
        file.open(filename, ios::in);
        if (file.is_open()) {
            string line;
            while (getline(file, line))
            {
                v.push_back(line);
            }
        }
        file.close();
        return v;
    }
    // from vector to file

    void vectortofile(string filename, vector<string>& vec)
    {
        fstream file;
        file.open(filename, ios::out | ios::app);
        if (file.is_open())
        {
            for (string& x : vec)
            {
                if (x != "") file << x << "\n";
            }
        }
        file.close();
    }
    void NewVectorToFile(string filename, vector<string>& vec)
    {
        fstream file;
        file.open(filename, ios::out);
        if (file.is_open())
        {
            for (string& x : vec)
            {
                if (x != "") file << x << "\n";
            }
        }
        file.close();
    }
    // print file content
    void readfile(string filename)
    {
        fstream f;
        f.open(filename, ios::in);
        if (f.is_open())
        {
            string s;
            while (getline(f, s))
            {
                cout << s << endl;
            }
        }
        f.close();
    }
    // delete a string from the file
    void delet(string filename, string name)
    {
        vector<string> vec = filetovector(filename);
        for (string& x : vec)
        {
            if (x == name) x = "";
        }
        NewVectorToFile(filename, vec);
    }
    // update a string
    void update(string filename, string aname,string bname)
    {
        vector<string> vec = filetovector(filename);
        for (string& x : vec)
        {
            if (x == aname) x = bname;
        }
        NewVectorToFile(filename, vec);
    }
}
