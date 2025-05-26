#pragma once
#include <iostream>
#include "ClsUtil.h";
using namespace std;
using namespace ClsUtil;
namespace ArrayLib {
    void ReadArray(int r[100], int& l)
    {
        l = clsUtil::ReadPositiveNumber("Enter Array Length: ");
        int el = 0;
        for (int i = 0; i < l; ++i)
        {
            cout << "Enter Element " << i + 1 << ": ";
            el = clsUtil::ReadPositiveNumber("");
            r[i] = el;
        }
    }
    void PrintArray(int r[100], int l)
    {
        cout << "Original Array: \n";
        for (int i = 0; i < l; ++i)
        {
            cout << r[i] << "  ";
        }
        cout << "\n";
    }
    void CopyArray(int OrArray[100], int NewArray[100], int l)
    {
        for (int i = 0; i < l; ++i)
        {
            NewArray[i] = OrArray[i];
        }
    }
    void Shuffle(int arr[100], int l)
    {
        for (int i = 0; i < l; ++i)
        {
            swap(arr[clsUtil::RandomNumber(0, l - 1)], arr[clsUtil::RandomNumber(0, l - 1)]);
        }
    }

    void Random2dArray(int arr[3][3], short r, short c)
    {

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                arr[i][j] = clsUtil::RandomNumber(1, 10);
            }
        }
    }
    void Print2dArray(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << setw(3) << arr[i][j] << "   ";
            }
            cout << endl;
        }
    }
    int RowSum(int arr[3][3], int r, int c)
    {
        int result = 0;
        for (int i = 0; i < c; ++i)
        {
            result += arr[r][i];
        }
        return result;
    }
    int ColSum(int arr[3][3], int r, int c)
    {
        int result = 0;
        for (int i = 0; i < r; ++i)
        {
            result += arr[i][c];
        }
        return result;
    }
    void RowSumToArray(int arr1[3][3], int arr2[3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            arr2[i] = RowSum(arr1, i, c);
        }
    }
    void ColSumToArray(int arr1[3][3], int arr2[3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            arr2[i] = ColSum(arr1, r, i);
        }
    }
    void PrintRowSum(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            cout << "Row " << i + 1 << " Sum: = " << RowSum(arr, i, c);
            cout << endl;
        }
    }
    void PrintColSum(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            cout << "Colomns " << i + 1 << " Sum: = " << ColSum(arr, r, i);
            cout << endl;
        }
    }
    void PrintRowSumArray(int arr[3], int l)
    {
        for (int i = 0; i < l; ++i)
        {
            cout << "Row " << i + 1 << " Sum: = " << arr[i] << endl;
        }
    }
    void PrintColSumArray(int arr[3], int l)
    {
        for (int i = 0; i < l; ++i)
        {
            cout << "Col " << i + 1 << " Sum: = " << arr[i] << endl;
        }
    }
    void OrderedArray(int arr[3][3], int r, int c)
    {
        int x = 1;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                arr[i][j] = x;
                ++x;
            }
        }
    }
    void trans(int arr[3][3], int r, int c)
    {
        int b = 0;
        for (int i = 0; i < c; ++i)
        {
            for (int j = b++; j < r; ++j)
            {
                clsUtil::Swap(arr[i][j], arr[j][i]);
            }
        }
    }
    void Print2dArrayf(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                int x = arr[i][j];
                if (x < 10) cout << setw(3) << '0' << x << "   ";
                else cout << setw(4) << x << "   ";
            }
            cout << endl;
        }
    }
    void MultiArrays(int arr1[3][3], int arr2[3][3], int arrR[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                arrR[i][j] = arr1[i][j] * arr2[i][j];
            }
        }
    }
    void MiddleRow(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < c; ++i)
        {
            printf("%02d   ", arr[r / 2][i]);
        }
    }
    void MiddleCol(int arr[3][3], int r, int c)
    {
        for (int i = 0; i < c; ++i)
        {
            printf("%02d   ", arr[i][c / 2]);
        }
    }
    int ArraySum(int arr[3][3], int r, int c)
    {
        int result = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int k = 0; k < c; ++k)
            {
                result += arr[i][k];
            }
        }
        return result;
    }
    bool ArrayCompire(int arr1[3][3], int arr2[3][3], int r, int c)
    {
        int a1 = ArrayLib::ArraySum(arr1, r, c);
        int a2 = ArrayLib::ArraySum(arr2, r, c);
        return a1 == a2 ? true : false;
    }
    bool ArrayTypical(int arr1[3][3], int arr2[3][3], int r, int c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (arr1[i][j] != arr2[i][j]) return false;
            }
        }
        return true;
    }
    bool IsScalar(int Matrix1[3][3], short Rows, short Cols)
    {
        //check Diagonal elements are 1 and rest elements are 0
        int x = Matrix1[0][0];
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                //check for diagonals element
                if (i == j && Matrix1[i][j] != x)
                {
                    return false;
                }
                //check for rest elements
                else if (i != j && Matrix1[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int CountNumberInMatrix(int Matrix1[3][3], int num, short Rows, short Cols)
    {
        short x = 0;
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] == num) x++;
            }
        }
        return x;
    }
    bool Sparce(int arr[3][3], short r, short c)
    {
        short area = r * c;
        return CountNumberInMatrix(arr, 0, 3, 3) >= ((float)area / 2.0);
    }
    bool IsExist(int arr[3][3], int n, short r, short c)
    {
        for (short i = 0; i < r; i++)
        {
            for (short j = 0; j < c; j++)
            {
                if (arr[i][j] == n) return true;
            }
        }
        return false;
    }
    void Printintersected(int arr1[3][3], int arr2[3][3], short r, short c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (IsExist(arr2, arr1[i][j], 3, 3))
                {
                    cout << arr1[i][j] << "  ";
                }
            }
        }
    }
    bool IsPalindromeMatrix(int arr1[3][3], short r, short c)
    {
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (arr1[i][j] != arr1[i][c - 1-j]) return false;
            }
        }
        return true;
    }
}