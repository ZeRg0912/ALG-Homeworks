#include <iostream>

using namespace std;

int fib(int n){
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chsp1251");
    system("cls");

    int num = 0;
    cout << "Введите индекс числа Фибоначчи: ";
    cin >> num;
    cout << "Число Фибоначчи: " << fib(num);

	return 0;
}

// По времени O(n^2), по памяти O(1);