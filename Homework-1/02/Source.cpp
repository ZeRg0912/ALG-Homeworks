#include <iostream>

using namespace std;

int countRefs(int a[], int size, int point)
{
    int count = 0;
    int left = 0;
    int right = size - 1;
    int middle;
    do {
        middle = (left + right) / 2;
        if (a[middle] > point) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
        cout << middle << endl;
    } while (right >= left);
    return size - left;
}

int enterPoint() {
    int point;
    do {
        cout << "¬ведите точку отсчета: ";
        cin >> point;
        system("cls");
        if (cin.fail()) {
            cout << "¬ведите число!\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else { break; }
    } while (!isdigit(point));

    return point;
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chsp1251");
    system("cls");
	const int size = 9;
	int arr[size]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int point = enterPoint();
    cout << countRefs(arr, size, point);


	return 0;
}