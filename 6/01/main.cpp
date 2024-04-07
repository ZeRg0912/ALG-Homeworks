#include <iostream>

using namespace std;

int simple_string_hash(string str) {
	int hash_sum = 0;
	for (int i = 0; i < str.length(); i++) {
		hash_sum += static_cast<int>(str[i]);
	}
	return hash_sum;
}

void print_string_hash(string str) {
	cout << "Наивный хэш строки " << str << " = "
		<< simple_string_hash(str) << endl;
}

string enter_string() {
	string in;
	do {
		cout << "Введите строку: ";
		cin >> in;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы ввели некорректное значение! попробуйте снова\n";
		}
		else {
			break;
		}
	} while (!cin.fail());
	return in;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	string str;

	do {
		str = enter_string();
		print_string_hash(str);
	} while (str != "exit");

	return 0;
}