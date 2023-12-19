#include <iostream>
#include <string>


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
	if (logical_size == 0) cout << " _";
	cout << endl;
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

void remove_dynamic_array_head(int* &arr, int* logical_size, int* actual_size) {
	string in;
	do {
		do {
			cout << "Удалить первый элемент? ";
			cin >> in;
			if (in == "да" || in == "Да" || in == "ДА") {
				break;
			}
			else if (in == "нет" || in == "Нет" || in == "НЕТ") {
				cout << "Спасибо! Ваш динамический массив:";
				print_dynamic_array(arr, *logical_size, *actual_size);
				return;
			}
			else cout << "Введите да или нет!\n";
		} while ((in != "да" && in != "Да" && in != "ДА") && (in != "нет" && in != "Нет" && in != "НЕТ"));

		if (*logical_size == 0) {
			cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!\n";
			return;
		}

		if ((*logical_size) - 1 > (*actual_size) / 3)
		{
			for (int i = 1; i < *logical_size; i++)
			{
				arr[i - 1] = arr[i];
			};
			arr[*logical_size - 1] = 0;
		}

		if ((*logical_size) - 1 <= (*actual_size) / 3)
		{
			*actual_size /= 3; 
			int* arr_temp = new int[*actual_size] {};

			for (int i = 1; i < *logical_size; i++)
			{
				arr_temp[i - 1] = arr[i];
			};

			arr = arr_temp; 
			arr_temp = nullptr; 
		};

		*logical_size -= 1;

		cout << "Динамический массив:";
		print_dynamic_array(arr, *logical_size, *actual_size);

	} while (true);
}

int main() {
	setlocale(LC_ALL, "Russian"); // задаём русский текст
	system("chcp 1251"); // настраиваем кодировку консоли
	system("cls");

	int actual_size, logical_size;
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
	remove_dynamic_array_head(arr, &logical_size, &actual_size);

	delete[] arr;

	return 0;
}