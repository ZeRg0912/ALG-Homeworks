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
    cout << "������� ������ ����� ���������: ";
    cin >> num;
    cout << "����� ���������: " << fib(num);

	return 0;
}

// �� ������� O(n^2), �� ������ O(1);