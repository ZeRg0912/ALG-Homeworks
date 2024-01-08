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
	cout << "Кол - во вершин: " << size << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j != size - 1) cout << arr[i][j] << " ";
			else cout << arr[i][j] << endl;
		}
	}
	//cout << endl;
}

void DFSUtil(int** graph, int size, int v, bool* visited) {
	visited[v] = true;
	cout << v + 1 << " ";

	for (int i = 0; i < size; i++) {
		if (graph[v][i] && !visited[i]) {
			DFSUtil(graph, size, i, visited);
		}
	}
}

void DFS(int** graph, int size) {
	cout << "Порядок обхода вершин: ";
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			DFSUtil(graph, size, i, visited);
		}
	}

	delete[] visited;
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

	int size;
	int** graph = ReadGraphMatrix("in.txt", size);

	PrintMatrix(graph, size);

	DFS(graph, size);

	DeleteGraph(graph, size);

	return 0;
}