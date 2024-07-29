#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função de partição para o QuickSort
int partition(vector<int>& arr, int low, int high, long long& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

// Algoritmo QuickSort
void quickSort(vector<int>& arr, int low, int high, long long& swaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, swaps);

        quickSort(arr, low, pivotIndex - 1, swaps);
        quickSort(arr, pivotIndex + 1, high, swaps);
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
        quickSort(arr, 0, size - 1, swaps);
        clock_t end = clock();

        // Imprimindo resultados
        cout << "Size: " << size << ", Swaps: " << swaps << ", Time: "
             << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    }

    return 0;
}