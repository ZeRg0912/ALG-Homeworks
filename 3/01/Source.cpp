#include <iostream>

using namespace std;

void merge_sorted(int* arr, int* leftArr, int left, int* rightArr, int right)
{
	int iLeft = 0, iRight = 0, i = 0;

	while (left > iLeft && right > iRight)
	{
		if (leftArr[iLeft] <= rightArr[iRight])
		{
			arr[i++] = leftArr[iLeft++];
		}
		else
		{
			arr[i++] = rightArr[iRight++];
		}
	}
	while (left > iLeft)
	{
		arr[i++] = leftArr[iLeft++];
	}
	while (right > iRight)
	{
		arr[i++] = rightArr[iRight++];
	}
}

void merge_sort(int* arr, int size) {
	if (size <= 1) return;
	if (size == 2) {
		if (arr[0] > arr[1]) {
			swap(arr[0], arr[1]);
			return;
		}
	}
	int left = size / 2;
	int right = size - (size / 2);

	int* leftArr = new int[left];
	int* rightArr = new int[right];

	for (int i = 0; i < left; i++) {
		leftArr[i] = arr[i];
	}
	for (int i = 0; i < right; i++) {
		rightArr[i] = arr[i + left];
	}

	merge_sort(leftArr, left);
	merge_sort(rightArr, right);

	merge_sorted(arr, leftArr, left, rightArr, right);

	delete[] leftArr;
	delete[] rightArr;
}

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i != size - 1) cout << arr[i] << ", ";
		else cout << arr[i];
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chsp1251");
	system("cls");

	int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	
	cout << "Исходный массив 1: ";
	print_arr(arr1, size1);
	merge_sort(arr1, size1);
	cout << "Отсортированный массив 1: ";
	print_arr(arr1, size1);
	cout << endl;

	cout << "Исходный массив 2: ";
	print_arr(arr2, size2);
	merge_sort(arr2, size2);
	cout << "Отсортированный массив 2: ";
	print_arr(arr2, size2);
	cout << endl;

	cout << "Исходный массив 3: ";
	print_arr(arr3, size3);
	merge_sort(arr3, size3);
	cout << "Отсортированный массив 3: ";
	print_arr(arr3, size3);
	cout << endl;

	return 0;
}