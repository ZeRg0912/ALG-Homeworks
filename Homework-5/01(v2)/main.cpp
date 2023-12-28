#include <iostream>
#include <cmath>

using namespace std;

void print_pyramid(int* arr, int arrSize) {
    cout << "Пирамида: " << endl;
    for (int i = 0; i < arrSize; i++) {
        int level = static_cast<int>(log2(i + 1));
        int parent = (i - 1) / 2;
        if (i == 0) {
            cout << level << " root " << arr[i] << endl;
        }
        else if (i % 2 == 1) {
            cout << level << " left(" << arr[parent] << ") " << arr[i] << endl;
        }
        else {
            cout << level << " right(" << arr[parent] << ") " << arr[i] << endl;
        }
    }
}

void print_array(int* arr, int arrSize) {
    cout << "Исходный массив: ";
    for (int i = 0; i < arrSize; i++) {
        if (i != arrSize - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
    }
}

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

    print_array(arr1, size1);
    print_pyramid(arr1, size1);
    cout << endl;

    print_array(arr2, size2);
    print_pyramid(arr2, size2);
    cout << endl;

    print_array(arr3, size3);
    print_pyramid(arr3, size3);
    cout << endl;

    print_array(arr4, size4);
    print_pyramid(arr4, size4);
    cout << endl;

    return 0;
}
