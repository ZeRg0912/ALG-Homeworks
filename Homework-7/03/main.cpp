#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** ReadGraphMatrix(string filename, int& size) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Неудается открыть файл!" << endl;
		return nullptr;
	}
	else {
		file >> size;

		int** matrix = new int* [size];

		for (int i = 0; i < size; i++) {
			matrix[i] = new int[size];
			for (int j = 0; j < size; j++) {
				file >> matrix[i][j];
			}
		}

		file.close();

		return matrix;
	}
}

void PrintMatrix(int** arr, int size) {
	cout << "В графе: " << size << " вершин." << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != size - 1) cout << arr[i][j] << " ";
			else cout << arr[i][j] << endl;
		}
	}
	//cout << endl;
}

bool DFSUtil(int** graph, int v, bool* visited, int parent, int size) {
	visited[v] = true;

	for (int i = 0; i < size; i++) {
		if (graph[v][i]) {
			if (!visited[i]) {
				if (DFSUtil(graph, i, visited, v, size)) {
					return true;
				}
			}
			else if (i != parent) {
				return true;
			}
		}
	}
	return false;
}

bool doesContainCycle(int** graph, int size) {
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			if (DFSUtil(graph, i, visited, -1, size)) {
				delete[] visited;
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}

void DeleteGraph(int** graph, int size) {
	for (int i = 0; i < size; i++) {
		delete[] graph[i];
	}
	delete[] graph;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	int size, size2;
	int** graph = ReadGraphMatrix("in.txt", size);
	int** graph2 = ReadGraphMatrix("in2.txt", size2);

	PrintMatrix(graph, size);

	if (doesContainCycle(graph, size)) {
		cout << "В графе 1 есть цикл!" << endl;
	}
	else {
		cout << "В графе 1 нет циклов!" << endl;
	}

	DeleteGraph(graph, size);

	cout << "==================================\n";

	PrintMatrix(graph2, size2);

	if (doesContainCycle(graph2, size2)) {
		cout << "В графе 2 есть цикл!" << endl;
	}
	else {
		cout << "В графе 2 нет циклов!" << endl;
	}

	DeleteGraph(graph2, size2);

	return 0;
}