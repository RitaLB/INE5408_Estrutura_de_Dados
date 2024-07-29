#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função para realizar a troca de elementos ( troca ítem a do vetor por item b e vice versa )
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função de partição para o QuickSort ( dividir para conquistar )
int particao(vector<int>& arr, int baixo, int alto, long long& trocas) {
    int pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            swap(arr[i], arr[j]);
            trocas++;
        }
    }

    swap(arr[i + 1], arr[alto]);
    trocas++;
    return i + 1;
}

// Função geral do algorítmo QuickSort
void quickSort(vector<int>& arr, int baixo, int alto, long long& trocas) {
    if (baixo < alto) {
        int indicePivo = particao(arr, baixo, alto, trocas);

        quickSort(arr, baixo, indicePivo - 1, trocas);
        quickSort(arr, indicePivo + 1, alto, trocas);
    }
}

// Função para ajustar um heap máximo
void ajustarHeap(vector<int>& arr, int n, int i, long long& trocas) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    if (maior != i) {
        swap(arr[i], arr[maior]);
        trocas++;
        ajustarHeap(arr, n, maior, trocas);
    }
}

// Função geral do algorítmo HeapSort
void heapSort(vector<int>& arr, long long& trocas) {
    int n = arr.size();

    // Construindo um heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        ajustarHeap(arr, n, i, trocas);
    }

    // Extraindo elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        trocas++;
        ajustarHeap(arr, i, 0, trocas);
    }
}

// Função para gerar um conjunto de valores aleatórios
vector<int> gerarVetorAleatorio(int tamanho) {
    vector<int> arr(tamanho);
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000; 
    }
    return arr;
}

// Função principal de realização da questão
int main() {
    // apresentação da questão no terminal
    cout << "Trabalho de Estrutura de Dados"<< endl;
    cout << "Algorítmos de ordenação estudados: QuickSort e HeapSort"<< endl;
    cout << "Métricas observadas: Número de trocas (swaps) e Tempo de execução"<< endl << endl;

    srand(static_cast<unsigned>(time(0)));

    // Tamanhos definidos pela questão fornecida
    vector<int> tamanhos = {1000, 5000, 10000, 50000, 100000};

    // execução para cada tamanho de vetor:
    for (int tamanho : tamanhos) {
        //gerando os valores aleatórios
        vector<int> arrQuickSort = gerarVetorAleatorio(tamanho);
        vector<int> arrHeapSort = arrQuickSort;

        long long trocasQuickSort = 0;
        long long trocasHeapSort = 0;

        // Medindo o tempo de execução e realizando o QuickSort
        clock_t inicioQuickSort = clock();
        quickSort(arrQuickSort, 0, tamanho - 1, trocasQuickSort);
        clock_t fimQuickSort = clock();

        // Medindo o tempo de execução e realizando o HeapSort
        clock_t inicioHeapSort = clock();
        heapSort(arrHeapSort, trocasHeapSort);
        clock_t fimHeapSort = clock();

        // importante lembrar: swaps contabilizados dentro das funções, incrementando variável a cada troca feita no vetor. 

        // Apresentação dos resultados obtidos:
        cout << "Tamanho: " << tamanho << endl;

        cout << "QuickSort - Trocas: " << trocasQuickSort << ", Tempo: "
             << double(fimQuickSort - inicioQuickSort) / CLOCKS_PER_SEC << " segundos" << endl;

        cout << "HeapSort  - Trocas: " << trocasHeapSort << ", Tempo: "
             << double(fimHeapSort - inicioHeapSort) / CLOCKS_PER_SEC << " segundos" << endl;

        cout << endl;
    }

    return 0;
}