#include <iostream>

using namespace std;

void PrintArray(int* arr, int arrSize) {
	cout << "Исходный массив: ";
	for (int i = 0; i < arrSize; i++) {
		if (i != arrSize - 1) cout << arr[i] << ", ";
		else cout << arr[i];
	}
	cout << endl;
};

int ElementsOnLevelNow(int* ElementsOnLevel, int Levels, int i)
{
    for (int j = 0; j < Levels; j++)
    {
        if (i < ElementsOnLevel[j])
        {
            return j;
        }
    };
    return 1;
};

void PrintPyramid(int* arr, int arrSize)
{
    cout << "Пирамида:\n";
    cout << "0 root " << arr[0] << endl;

    int Levels = log2(arrSize) + 1;
    int* ElementsOnLevel = new int[Levels] {};

    for (int i = 0; i < Levels; i++)
    {
        ElementsOnLevel[i] = pow(2, i);
    }

    for (int i = 0; i < arrSize; i++)
    {
        int indexLeft = 2 * i + 1;
        if (indexLeft < arrSize)
        {
            cout << ElementsOnLevelNow(ElementsOnLevel, Levels, i + 1) << " left(" << arr[i] << ")" << " " << arr[2 * i + 1] << endl;
        }

        int indexRight = 2 * i + 2;
        if (indexRight < arrSize)
        {
            cout << ElementsOnLevelNow(ElementsOnLevel, Levels, i + 1) << " right(" << arr[i] << ")" << " " << arr[2 * i + 2] << endl;
        }
    }
    cout << endl;

    delete[] ElementsOnLevel;
    ElementsOnLevel = nullptr;
};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr4[] = { 94, 67, 18, 44, 55, 12, 6, 42, 39, 38, 37, 35, 28, 18, 15, 14, 12, 10, 9 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
	
    PrintArray(arr1, size1);
    PrintPyramid(arr1, size1);
    cout << endl;
    PrintArray(arr2, size2);
    PrintPyramid(arr2, size2);
    cout << endl;
    PrintArray(arr3, size3);
    PrintPyramid(arr3, size3);
    cout << endl;
    PrintArray(arr4, size4);
    PrintPyramid(arr4, size4);
    cout << endl;

	return 0;
}