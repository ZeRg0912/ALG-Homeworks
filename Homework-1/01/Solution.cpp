#include <iostream>
#include <algorithm>

using namespace std;

int calc(int* arr, int size)
{
	int ans = 0;
	for (int i = 1; i < size; i++)
	{
		ans += arr[i] - arr[i - 1];
	}
	return ans;
}

int main() {
	const int size = 5;
	int arr[size]{ 1,3,9,5,7 };
	cout << "Calc: " << calc(arr, size);
	return 0;
}

// ������� �������� �� ����� ������� � ���������� ��������, 
// ������ ����� ��������� ����� ���������� ������� � �� ����������� ����������. 

// ����� - O(n), ������ - O(1)
// ��������� ��������� ������� ������ � ����������� ������� ������, �.�.
// �������� ������� ������� ������ ������ � ����� ����������� ��� ���������� ���������;

// ��� ��������� ������� ������ ������ �� ��������, ������� O(1).