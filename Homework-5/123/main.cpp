#include <iostream>

using namespace std;

void heapify(int* arr, int arrSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < arrSize && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < arrSize && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, arrSize, smallest);
    }
}

void build_heap(int* arr, int arrSize) {
    for (int i = arrSize / 2 - 1; i >= 0; i--) {
        heapify(arr, arrSize, i);
    }
}

void print_pyramid(int* arr, int arrSize, int current_index) {
    cout << "Пирамида: " << endl;
    for (int i = 0; i < arrSize; i++) {
        int level = static_cast<int>(log2(i + 1));
        int parent = (i - 1) / 2;
        if (i == current_index) {
            if (i != 0) {
                if (i % 2 == 1) {
                    cout << level <<  " left(" << arr[parent] << ") " << arr[i] << " <-- Current" << endl;
                }
                else {
                    cout << level << " right(" << arr[parent] << ") " << arr[i] << " <-- Current" << endl;
                }
            }
            else {
                cout << level << " root" << arr[i] << " <-- Current" << endl;
            }
        }
        else if (i == 0) {
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
    /*int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr4[] = { 94, 67, 18, 44, 55, 12, 6, 42, 39, 38, 37, 35, 28, 18, 15, 14, 12, 10, 9 };*/

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    /*int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);*/

    print_array(arr1, size1);
    //build_heap(arr1, size1);
    //print_pyramid(arr1, size1);
    cout << endl;

    /*print_array(arr2, size2);
    //build_heap(arr2, size2);
    print_pyramid(arr2, size2);
    cout << endl;

    print_array(arr3, size3);
    //build_heap(arr3, size3);
    print_pyramid(arr3, size3);
    cout << endl;

    print_array(arr4, size4);
    //build_heap(arr4, size4);
    print_pyramid(arr4, size4);
    cout << endl;*/

    int current_index = 0; // Исходный индекс элемента

    char move_choice;
    while (true) {
        cout << "Current Level: " << current_index << endl;
        print_pyramid(arr1, size1, current_index);

        cout << "Move (U)p, (L)eft, (R)ight, or (Q)uit: ";
        cin >> move_choice;

        if (move_choice == 'U' || move_choice == 'u') {
            if (current_index == 0) {
                system("cls");
                cout << "Error: No element above the root" << endl;
            }
            else {
                system("cls");
                current_index = (current_index - 1) / 2;
            }
        }
        else if (move_choice == 'L' || move_choice == 'l') {
            int left_child = 2 * current_index + 1;
            if (left_child < size1) {
                system("cls");
                current_index = left_child;
            }
            else {
                system("cls");
                cout << "Error: No left child for the current element" << endl;
            }
        }
        else if (move_choice == 'R' || move_choice == 'r') {
            int right_child = 2 * current_index + 2;
            if (right_child < size1) {
                system("cls");
                current_index = right_child;
            }
            else {
                system("cls");
                cout << "Error: No right child for the current element" << endl;
            }
        }
        else if (move_choice == 'Q' || move_choice == 'q') {
            cout << "bb!" << endl;
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
