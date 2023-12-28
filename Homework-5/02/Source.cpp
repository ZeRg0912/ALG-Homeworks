#include <iostream>

using namespace std;

enum class MovementsOnThePyramid
{
	Up = 1, Left = 2, Right = 3, Exit = 0
};

int root(int* arr, const int arrSize)
{
	return arr[0];
}

int fromIndex(int* arr, const int arrSize, const int index)
{
	return arr[index];
}

int leftIndex(const int parentIndex)
{
	return (2 * parentIndex + 1);
}

int rightIndex(const int parentIndex)
{
	return (2 * parentIndex + 2);
}

int parentIndex(int childIndex)
{
	return ((childIndex - 1) / 2);
}

void PrintArray(int* arr, int arrSize) {
    cout << "Исходный массив: ";
    for (int i = 0; i < arrSize; i++) {
        if (i != arrSize - 1) cout << arr[i] << ", ";
        else cout << arr[i];
    }
    cout << endl;
};

int Level(int* ElementsOnLevel, int Levels, int i)
{
	for (int j = 0; j < Levels; j++)
	{
		if (i < ElementsOnLevel[j])
		{
			return j;
		}
	};
	return EXIT_FAILURE;
};

void PrintPyramid(int* arr, int arrSize, int* ElementsOnLevel, int Levels)
{
	cout << "Пирамида:\n";
	cout << "0 root " << arr[0] << endl;

	for (int i = 0; i < Levels; i++)
	{
		ElementsOnLevel[i] = pow(2, i);
	}

	for (int i = 0; i < arrSize; i++)
	{
		int indexLeft = 2 * i + 1;
		if (indexLeft < arrSize)
		{
			cout << Level(ElementsOnLevel, Levels, i + 1) << " left(" << arr[i] << ")" << " " << arr[2 * i + 1] << endl;
		}

		int indexRight = 2 * i + 2;
		if (indexRight < arrSize)
		{
			cout << Level(ElementsOnLevel, Levels, i + 1) << " right(" << arr[i] << ")" << " " << arr[2 * i + 2] << endl;
		}
	}
	cout << endl;
};

void WhereAmI(int* arr, const int arrSize, int* arrStopIndex, int* ElementsOnLevel, int Levels, int chooseOfUser)
{
	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Up))
	{
		if (*arrStopIndex == 0)
		{
			std::cout << "Ошибка! У корневого элемента отсутствует родитель.\n";
			std::cout << "Вы находитесь здесь: 0 root " << fromIndex(arr, arrSize, *arrStopIndex) << std::endl << std::endl;
			return;
		}
		else if (*arrStopIndex == 1)
		{
			*arrStopIndex -= 1;
			std::cout << "Вы находитесь здесь: 0 root " << fromIndex(arr, arrSize, *arrStopIndex) << std::endl << std::endl;
			return;
		}
		else if (*arrStopIndex == 2)
		{
			*arrStopIndex -= 2;
			std::cout << "Вы находитесь здесь: 0 root " << fromIndex(arr, arrSize, *arrStopIndex) << std::endl << std::endl;
			return;
		}
		else if (*arrStopIndex % 2 != 0)
		{
			int thisLevelOfpyramid = Level(ElementsOnLevel, Levels, *arrStopIndex);

			*arrStopIndex = parentIndex(*arrStopIndex);

			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid - 1
				<< " left(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		}
		else
		{
			int thisLevelOfpyramid = Level(ElementsOnLevel, Levels, *arrStopIndex);

			*arrStopIndex = parentIndex(*arrStopIndex);

			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid - 1
				<< " right(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		};
	};

	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Left))
	{
		int thisLevelOfpyramid = Level(ElementsOnLevel, Levels, *arrStopIndex);

		if (leftIndex(*arrStopIndex) > arrSize - 1)
		{
			std::cout << "Ошибка! Отсутствует левый потомок.\n";
			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid
				<< " left(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		}
		else
		{
			int thisLevelOfpyramid = Level(ElementsOnLevel, Levels, *arrStopIndex);

			*arrStopIndex = leftIndex(*arrStopIndex);

			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid + 1
				<< " left(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		};
	};

	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Right))
	{
		int thisLevelOfpyramid = Level(ElementsOnLevel, Levels, *arrStopIndex);

		if (rightIndex(*arrStopIndex) > arrSize - 1)
		{
			std::cout << "Ошибка! Отсутствует правый потомок.\n";
			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid
				<< " right(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		}
		else
		{
			*arrStopIndex = rightIndex(*arrStopIndex);

			std::cout << "Вы находитесь здесь: " << thisLevelOfpyramid + 1
				<< " right(" << arr[parentIndex(*arrStopIndex)] << ") "
				<< arr[*arrStopIndex] << std::endl << std::endl;
			return;
		}
	};
};

void journeyThroughThePyramid(int* arr, const int arrSize, int* ElementsOnLevel, int Levels)
{
	int arrStopIndex = 0;
	std::cout << "Давайте путешествовать по пирамиде:\n";


	std::cout << "Вы находитесь здесь: 0 root" << fromIndex(arr, arrSize, arrStopIndex) << std::endl << std::endl;

	bool exitFromTheJourney = false;
	int chooseOfUser = 0;

	do
	{
		std::cout << "Введите команду (1.Вверх, 2.Влево, 3.Вправо, 0.Выход):>";
		std::cin >> chooseOfUser;
		while (!std::cin.good() || chooseOfUser < 0 || chooseOfUser > 3)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы ввели неверную команду.\n";
			std::cout << "Введите верную команду (1.Вверх, 2.Влево, 3.Вправо, 0.Выход):>";
			std::cin >> chooseOfUser;
		}

		if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Up))
		{
			WhereAmI(arr, arrSize, &arrStopIndex, ElementsOnLevel, Levels, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Left))
		{
			WhereAmI(arr, arrSize, &arrStopIndex, ElementsOnLevel, Levels, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Right))
		{
			WhereAmI(arr, arrSize, &arrStopIndex, ElementsOnLevel, Levels, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Exit))
		{
			std::cout << "\nДо новых встреч!\n";
			exitFromTheJourney = true;
		}

		else
		{
			std::cout << "Выход за пределы IF-ELSE в void journeyThroughThePyramid(int* arr, const int arrSize)\n";
		}

	} while (!exitFromTheJourney);
}

void MovesInPyramid(int* arr, int arrSize) {
	int Levels = log2(arrSize) + 1;
    int* ElementsOnLevel = new int[Levels] {};

    PrintPyramid(arr, arrSize, ElementsOnLevel, Levels);
	journeyThroughThePyramid(arr, arrSize, ElementsOnLevel, Levels);

    delete[] ElementsOnLevel;
    ElementsOnLevel = nullptr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    //int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    //int arr4[] = { 94, 67, 18, 44, 55, 12, 6, 42, 39, 38, 37, 35, 28, 18, 15, 14, 12, 10, 9 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    //int size2 = sizeof(arr2) / sizeof(arr2[0]);
    //int size3 = sizeof(arr3) / sizeof(arr3[0]);
    //int size4 = sizeof(arr4) / sizeof(arr4[0]);

    PrintArray(arr1, size1);
    MovesInPyramid(arr1, size1);
    cout << endl;
    /*PrintArray(arr2, size2);
    PrintPyramid(arr2, size2);
    cout << endl;
    PrintArray(arr3, size3);
    PrintPyramid(arr3, size3);
    cout << endl;
    PrintArray(arr4, size4);
    PrintPyramid(arr4, size4);
    cout << endl;*/

    return 0;
}