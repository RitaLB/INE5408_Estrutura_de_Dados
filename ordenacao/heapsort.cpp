#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função para realizar a troca de elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para ajustar um heap máximo
void heapify(vector<int>& arr, int n, int i, long long& swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;
        heapify(arr, n, largest, swaps);
    }
}

// Função principal do HeapSort
void heapSort(vector<int>& arr, long long& swaps) {
    int n = arr.size();

    // Construir um heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swaps);
    }

    // Extrair elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, i, 0, swaps);
    }
}

// Função para gerar um conjunto de valores aleatórios
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Ajuste conforme necessário
    }
    return arr;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);
        long long swaps = 0;

        // Medindo o tempo de execução
        clock_t start = clock();
        heapSort(arr, swaps);
        clock_t end = clock();

        // Imprimindo resultados
        cout << "Size: " << size << ", Swaps: " << swaps << ", Time: "
             << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    }

    return 0;
}