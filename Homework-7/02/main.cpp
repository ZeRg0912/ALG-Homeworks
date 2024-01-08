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

/*void enqueue(int* queue, int& rear, int item, int capacity) {
	if (rear == capacity - 1) {
		cout << "Очередь полная" << endl;
	}
	else {
		rear++;
		queue[rear] = item;
	}
}

int dequeue(int* queue, int& front, int rear) {
	if (front > rear) {
		cout << "Очередь пустая" << endl;
		return -1;
	}
	else {
		return queue[front++];
	}
}

void WFS(int** graph, int size, int start) {
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	int* queue = new int[size];
	int front = 0, rear = -1;

	visited[start] = true;
	enqueue(queue, rear, start, size);

	while (front <= rear) {
		int v = dequeue(queue, front, rear);
		cout << v + 1 << " ";

		for (int i = 0; i < size; i++) {
			if (graph[v][i] && !visited[i]) {
				visited[i] = true;
				enqueue(queue, rear, i, size);
			}
		}
	}

	delete[] visited;
	delete[] queue;
}*/

void WFS(int** graph, int size, int start) {
	cout << "Порядок обхода вершин: ";
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	int* queue = new int[size];
	int front = 0, rear = -1;

	visited[start] = true;
	queue[++rear] = start;

	while (front <= rear) {
		int v = queue[front++];
		cout << v + 1 << " ";

		for (int i = 0; i < size; i++) {
			if (graph[v][i] && !visited[i]) {
				visited[i] = true;
				queue[++rear] = i;
			}
		}
	}

	delete[] visited;
	delete[] queue;
}

void DeleteGraph(int** graph, int size) {
	for (int i = 0; i < size; i++) {
		delete[] graph[i];
	}
	delete[] graph;
}

void EnterStart(int& start) {
	do {
		cout << "Введите номер вершины, с которой начнется обход: ";
		cin >> start;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\size');
			cout << "Вы ввели некорректное значение! попробуйте снова\size";
		}
		else {
			break;
		}
	} while (!isdigit(start));
	start -= 1;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	system("chcp 1251");
	system("cls");

	int size, start;
	int** graph = ReadGraphMatrix("in.txt", size);

	PrintMatrix(graph, size);

	EnterStart(start);

	WFS(graph, size, start);

	DeleteGraph(graph, size);

	return 0;
}