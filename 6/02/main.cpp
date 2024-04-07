#include <iostream>

using namespace std;

long long real_string_hash(string str, int p, int n) {
	long long hash_sum = 0;
	long long temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp = static_cast<int>(str[i]);
		hash_sum += static_cast<int>(pow(p, i)) * temp;
	}
	return hash_sum % n;
}

void enter_string(string& str) {
	do {
		cout << "������� ������: ";
		cin >> str;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ����� ������������ ��������! ���������� �����\n";
		}
		else {
			break;
		}
	} while (!cin.fail());
}

void enter_p_n(int& p, int& n) {
	do {
		cout << "������� p: ";
		cin >> p;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ����� ������������ �������� p! ���������� �����\n";
		}
		else {
			break;
		}
	} while (!cin.fail());
	do {
		cout << "������� n: ";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� ����� ������������ �������� n! ���������� �����\n";
		}
		else {
			break;
		}
	} while (!cin.fail());
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	string str;
	int p, n;

	enter_p_n(p, n);
	do {		
		enter_string(str);
		cout << "��� ������ " << str << " = " << real_string_hash(str, p, n) << endl;
	} while (str != "exit");

	return 0;
}