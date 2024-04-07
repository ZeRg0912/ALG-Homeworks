#include <iostream>

using namespace std;

void quick_sort(int* arr, int left, int right)
{
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > left)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (i != size - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chsp1251");
	system("cls");
    
	int arr1 [] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	int arr2 [] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	int arr3 [] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив 1: ";
    print_array(arr1, size1);
    quick_sort(arr1, 0, size1 - 1);
    cout << "Отсортированный массив 1: ";
    print_array(arr1, size1);
    cout << endl;

    cout << "Исходный массив 2: ";
    print_array(arr2, size2);
    quick_sort(arr2, 0, size2 - 1);
    cout << "Отсортированный массив 2: ";
    print_array(arr2, size2);
    cout << endl;

    cout << "Исходный массив 3: ";
    print_array(arr3, size3);
    quick_sort(arr3, 0, size3 - 1);
    cout << "Отсортированный массив 3: ";
    print_array(arr3, size3);
    cout << endl;

	return 0;
}