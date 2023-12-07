#include <iostream>

using namespace std;

long long fooFibonacci(long long arrFib[], const int size)
{
    arrFib[0] = 0;
    arrFib[1] = 1;

    for (long long i = 2; i <= size; i++)
    {
        arrFib[i] = arrFib[i - 1] + arrFib[i - 2];
    }
    return arrFib[size];
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chsp1251");
    system("cls");

    int size = 0;
    cout << "Введите индекс числа Фибоначчи: ";
    cin >> size;

    long long* arrFib = new long long[size + 1] {};

    cout << "Число Фибоначчи: " << fooFibonacci(arrFib, size) << endl;

    delete[] arrFib;
    arrFib = nullptr;

    return 0;
}

// По времени O(n), по памяти O(1);