#include <iostream>
#include <fstream>

using namespace std;

int** ReadGraphMatrix(string filename, int& size) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "��������� ������� ����!" << endl;
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
    cout << "� �����: " << size << " ������." << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j != size - 1) cout << arr[i][j] << " ";
            else cout << arr[i][j] << endl;
        }
    }
    //cout << endl;
}

void DFS(int v, int componentNumber, int N, bool* visited, int** graph, int* components) {
    visited[v] = true;
    components[v] = componentNumber;
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i, componentNumber, N, visited, graph, components);
        }
    }
}

void FindConnectedComponents(int** graph, int size) {
    bool* visited = new bool[size];
    int* components = new int[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
        components[i] = -1;
    }

    int numComponents = 0;
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            numComponents++;
            DFS(i, numComponents, size, visited, graph, components);
        }
    }

    // ������� ���������
    cout << "�������������� ������ ����������� ���������: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " - " << components[i] << endl;
    }
    cout << "���������� ����������� ��������� � �����: " << numComponents << endl;

    // ������� ���������� ������
    delete[] visited;
    delete[] components;
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

    FindConnectedComponents(graph, size);

    DeleteGraph(graph, size);

    return 0;
}