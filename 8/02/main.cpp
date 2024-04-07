#include <iostream>
#include <fstream>

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

void PrintGraph(int** arr, int size) {
    cout << "Текстовый вид орграфа: " << endl;

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": ";
        bool hasEdges = false;
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 1) {
                cout << j + 1 << " ";
                hasEdges = true;
            }
        }
        if (!hasEdges) {
            cout << "нет";
        }
        cout << endl;
    }
}

void DeleteGraph(int** graph, int size) {
    for (int i = 0; i < size; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

void TopologicalSortUtil(int** graph, int size, int v, bool* visited, int& currentIndex, int* result) {
    visited[v] = true;
    for (int i = 0; i < size; i++) {
        if (graph[v][i] && !visited[i]) {
            TopologicalSortUtil(graph, size, i, visited, currentIndex, result);
        }
    }
    result[currentIndex--] = v;
}

void TopologicalSort(int** graph, int size) {
    int* result = new int[size];
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }
    int currentIndex = size - 1;
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            TopologicalSortUtil(graph, size, i, visited, currentIndex, result);
        }
    }

    cout << "Топологический порядок вершин: ";
    for (int i = 0; i < size; i++) {
        cout << result[i] + 1 << " ";
    }
    cout << endl;

    delete[] visited;
    delete[] result;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    system("chcp 1251");
    system("cls");

    int size, size2;
    int** graph = ReadGraphMatrix("in.txt", size);
    int** graph2 = ReadGraphMatrix("in2.txt", size2);

    PrintMatrix(graph, size);
    //PrintGraph(graph, size);
    TopologicalSort(graph, size);
    DeleteGraph(graph, size);

    cout << "\n====================================================\n\n";

    PrintMatrix(graph2, size2);
    TopologicalSort(graph2, size2);
    DeleteGraph(graph2, size2);

    return 0;
}