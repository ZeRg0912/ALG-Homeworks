#include <iostream>

using namespace std;

enum class MovementsOnThePyramid
{
    Exit = 0, Up, Left, Right,
};

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

void print_array(int* arr, int arrSize) {
    cout << "Исходный массив: ";
    for (int i = 0; i < arrSize; i++) {
        if (i != arrSize - 1) cout << arr[i] << ", ";
        else cout << arr[i] << endl;
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
                    cout << level << " " << " left(" << arr[parent] << ") " << arr[i] << " <-- Текущий" << endl;
                }
                else {
                    cout << level << " " << " right(" << arr[parent] << ") " << arr[i] << " <-- Текущий" << endl;
                }
            }
            else {
                cout << level << " " << " root " << arr[i] << " <-- Текущий" << endl;
            }
        }
        else if (i == 0) {
            cout << level << " " << " root" << arr[i] << endl;
        }
        else if (i % 2 == 1) {
            cout << level << " " << " left(" << arr[parent] << ")" << arr[i] << endl;
        }
        else {
            cout << level << " " << " right(" << arr[parent] << ")" << arr[i] << endl;
        }
    }
}

void print_current_position(int* arr, int arrSize, int current_index) {
    int level = static_cast<int>(log2(current_index + 1));
    int parent = (current_index - 1) / 2;
    cout << "\nВы находитесь здесь: " << level;
    if (current_index != 0) {
        if (current_index % 2) {
            cout << " left(" << arr[parent] << ") ";
        }
        else {
            cout << " right(" << arr[parent] << ") ";
        }
    }
    else {
        cout << " root ";
    }
    cout << arr[current_index] << endl;
}

void MoveOnPyramid(int* arr, int arrSize) {
    bool Exit = false;
    int current_index = 0;
    int move_choice;
    print_array(arr, arrSize);
    print_pyramid(arr, arrSize, current_index);
    do {
        print_current_position(arr, arrSize, current_index);
        cout << "\nВведите верную команду (1.Вверх, 2.Влево, 3.Вправо, 0.Выход): ";
        do {
            cin >> move_choice;
            if (cin.fail() || move_choice < 0 || move_choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nВы ввели неверную команду.";
            }
            else {
                system("cls"); 
                break; 
            }
        } while (isdigit(move_choice) && move_choice > 0 && move_choice < 3);

        if (move_choice == static_cast<int> (MovementsOnThePyramid::Up)) {
            if (current_index == 0) {
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОшибка! Отсутствует родитель.";
            }
            else {
                current_index = (current_index - 1) / 2;
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОК!";
            }
        }
        else if (move_choice == static_cast<int> (MovementsOnThePyramid::Left)) {
            int left_child = 2 * current_index + 1;
            if (left_child < arrSize) {
                current_index = left_child;
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОК!";
            }
            else {
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОшибка! Отсутствует левый потомок.";
            }
        }
        else if (move_choice == static_cast<int> (MovementsOnThePyramid::Right)) {
            int right_child = 2 * current_index + 2;
            if (right_child < arrSize) {
                current_index = right_child;
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОК!";

            }
            else {
                print_array(arr, arrSize);
                print_pyramid(arr, arrSize, current_index);
                cout << "\nОшибка! Отсутствует правый потомок.";
            }
        }
        else if (move_choice == static_cast<int> (MovementsOnThePyramid::Exit)) {
            print_array(arr, arrSize);
            print_pyramid(arr, arrSize, current_index);
            print_current_position(arr, arrSize, current_index);
            cout << "До свидания!";
            Exit = true;
        }
    } while (!Exit);
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");

    /*int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr4[] = { 94, 67, 18, 44, 55, 12, 6, 42, 39, 38, 37, 35, 28, 18, 15, 14, 12, 10, 9 };*/

    /*int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);*/


    int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MoveOnPyramid(arr, size);   
    
    return 0;
}
