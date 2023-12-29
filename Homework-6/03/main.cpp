#include <iostream>

using namespace std;

void enter_string(string& str) {
	do {
		cin >> str;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы ввели некорректное значение! попробуйте снова\n";
		}
		else {
			break;
		}
	} while (!cin.fail());
}

long long real_string_hash(string str, int length) {
	int p = 29;
	int n = 1000;
	long long hash_sum = 0;
	for (int i = 0; i < length; i++) {
		hash_sum += static_cast<long long>(pow(p, i) * str[i]);
	}
	return hash_sum % n;
}

int simple_string_hash(string str, int length) {
	int hash_sum = 0;
	for (int i = 0; i < length; i++) {
		hash_sum += static_cast<int>(str[i]);
	}
	return hash_sum;
}

int find_substring_light_rabin_karp(string str, string find) {
	long long find_hash = simple_string_hash(find, find.length());
	long long str_hash = simple_string_hash(str.substr(0, find.length()), find.length());
	for (int i = 0; i <= str.length() - find.length(); i++) {
		if (i == 0) {
			str_hash = simple_string_hash(str, find.length());
		}
		else {
			str_hash -= static_cast<long long>(str[i - 1]);
			str_hash += static_cast<long long>(str[i + find.length() - 1]);
		}
		if (str_hash != find_hash) {
			continue;
		}
		else {
			for (int j = 0; j < find.length(); j++) {
				if (str[i + j] != find[j]) {
					break;
				}
				if (j == find.length() - 1) {
					return i;
				}
			}
		}
	}
	return -1;
}

int find_simple(string str, string find) {
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < find.length(); j++) {
			if (str[i + j] != find[j]) {
				break;
			}
			if (j == find.length() - 1) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	string full_str;
	string find_str;
	int index;

	cout << "Введите строку, в которой будет осуществляться поиск: ";
	enter_string(full_str);
	do {
		cout << "Введите подстроку, которую нужно найти: ";
		enter_string(find_str);
		index = find_substring_light_rabin_karp(full_str, find_str);
		switch (index) {
		case -1:
			cout << "Подстрока " << find_str << " не найдена" << endl;
			break;
		default:
			cout << "Подстрока " << find_str << " найдена по индексу " << index << endl;
			break;
		}
	} while (find_str != "exit");

	return 0;
}