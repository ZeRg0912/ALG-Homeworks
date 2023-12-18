#include <iostream>

using namespace std;

void enter_dynamic_array(int* arr, int logical_size) {
	for (int i = 0; i < logical_size; i++) {
		cout << "������� arr[" << i << "]: ";
		cin >> arr[i];
		do {
			cin >> arr[i];
			if (cin.fail()) {
				cout << "������� �����! ����� ��������: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		} while (!cin.fail());
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	cout << "������������ ������: ";
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) cout << arr[i] << " ";
		else if (i != actual_size - 1) cout << "_ ";
		else cout << "_\n";
	}
}

int enter_size() {
	int size;
	do {
		cin >> size;
		if (cin.fail()) {
			cout << "������� �����! ����� ��������: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (size <= 0) cout << "�������� ����, ������ ������ ���� ������ 0! ����� ��������: ";
		else break;
	} while (!isdigit(size) || size <= 0);
	return size;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chsp1251");
	system("cls");

	int actual_size, logical_size;
	do {
		system("cls");
		cout << "������� �������c��� ������ �������: ";
		actual_size = enter_size();
		cout << "������� ���������� ������ �������: ";
		logical_size = enter_size();
		if (logical_size > actual_size) {
			cout << "������! ���������� ������ �� ����� ��������� ��� ����������� ������!\n";
		}
	} while (logical_size > actual_size);

	int* arr = new int[actual_size];
	enter_dynamic_array(arr, logical_size);
	print_dynamic_array(arr, logical_size, actual_size);
	delete[] arr;

	return 0;
}