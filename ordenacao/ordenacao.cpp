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

// Algoritmo HeapSort
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
        vector<int> arrQuickSort = generateRandomArray(size);
        vector<int> arrHeapSort = arrQuickSort;

        long long swapsQuickSort = 0;
        long long swapsHeapSort = 0;

        // Medindo o tempo de execução e realizando o QuickSort
        clock_t startQuickSort = clock();
        quickSort(arrQuickSort, 0, size - 1, swapsQuickSort);
        clock_t endQuickSort = clock();

        // Medindo o tempo de execução e realizando o HeapSort
        clock_t startHeapSort = clock();
        heapSort(arrHeapSort, swapsHeapSort);
        clock_t endHeapSort = clock();

        // Imprimindo resultados
        cout << "Size: " << size << endl;

        cout << "QuickSort - Swaps: " << swapsQuickSort << ", Time: "
             << double(endQuickSort - startQuickSort) / CLOCKS_PER_SEC << " seconds" << endl;

        cout << "HeapSort  - Swaps: " << swapsHeapSort << ", Time: "
             << double(endHeapSort - startHeapSort) / CLOCKS_PER_SEC << " seconds" << endl;

        cout << endl;
    }

    return 0;
}
