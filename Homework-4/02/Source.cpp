#include <iostream>

using namespace std;

void enter_dynamic_array(int* arr, int logical_size) {
	for (int i = 0; i < logical_size; i++) {
		cout << "Введите arr[" << i << "]: ";
		do {
			cin >> arr[i];
			if (cin.fail()) {
				cout << "Введите число! Новое значение: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		} while (!cin.fail());
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < logical_size; i++) {
		cout << " " << arr[i];
	}
	for (int i = logical_size; i < actual_size; i++) {
		cout << " _";
	}
	cout << endl;
}

int enter_data() {
	int data;
	do {
		cin >> data;
		if (cin.fail()) {
			cout << "Введите число! Новое значение: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	} while (!isdigit(data));
	return data;
}

int enter_size() {
	int size;
	do {
		cin >> size;
		if (cin.fail()) {
			cout << "Введите число! Новое значение: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (size <= 0) cout << "Неверный ввод, размер должен быть больше 0! Новое значение: ";
		else break;
	} while (!isdigit(size) || size <= 0);
	return size;
}

void append_to_dynamic_array(int* &arr, int* logical_size, int* actual_size) {
	int data;
	do {
		cout << "Введите элемент для добавления (0 - для выхода из программы): ";
		do {
			cin >> data;
			if (cin.fail()) {
				cout << "Введите число! Новое значение: ";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		} while (!isdigit(data));

		if (data == 0) {
			cout << "Cпасибо! Ваш массив:";
			print_dynamic_array(arr, *logical_size, *actual_size);
			return;
		}

		if (*actual_size == *logical_size)
		{
			*actual_size *= 2;
			int* arr_temp = new int[*actual_size] {};

			for (int i = 0; i < *logical_size; i++)
			{
				arr_temp[i] = arr[i];
			};

			arr = arr_temp;
			arr_temp = nullptr;
		}

		arr[*logical_size] = data;
		*logical_size += 1;

		cout << "Динамический массив:";
		print_dynamic_array(arr, *logical_size, *actual_size);

	} while (true);
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chsp1251");
	system("cls");

	int actual_size, logical_size;
	int append_data;
	do {
		cout << "Введите фактичеcкий размер массива: ";
		actual_size = enter_size();
		cout << "Введите логический размер массива: ";
		logical_size = enter_size();
		if (logical_size > actual_size) {
			cout << "Ошибка! Логический размер не может превышать его фактический размер!\n";
		}
	} while (logical_size > actual_size);

	int* arr = new int[actual_size];
	enter_dynamic_array(arr, logical_size);
	cout << "Динамический массив:";
	print_dynamic_array(arr, logical_size, actual_size);
	append_to_dynamic_array(arr, &logical_size, &actual_size);

	delete[] arr;

	return 0;
}