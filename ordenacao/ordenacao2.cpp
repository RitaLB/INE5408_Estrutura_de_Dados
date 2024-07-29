#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função para trocar dois elementos em um vetor
void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Implementação do Quicksort
int particionar(vector<int> &arr, int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(arr[i], arr[j]);
        }
    }
    trocar(arr[i + 1], arr[alto]);
    return (i + 1);
}

void quicksort(vector<int> &arr, int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

// Implementação do Heapsort
void heapify(vector<int> &arr, int tamanho, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < tamanho && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        trocar(arr[i], arr[maior]);
        heapify(arr, tamanho, maior);
    }
}

void heapsort(vector<int> &arr) {
    int tamanho = arr.size();

    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(arr, tamanho, i);

    for (int i = tamanho - 1; i >= 0; i--) {
        trocar(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0)); // Seed para a geração de números aleatórios

    vector<int> tamanhos = {1000, 5000, 10000, 50000, 100000};

    for (int tamanho : tamanhos) {
        vector<int> conjunto;

        // Preencher o vetor com valores aleatórios
        for (int i = 0; i < tamanho; i++) {
            conjunto.push_back(rand() % 1000000);
        }

        // Copiar o vetor para ser usado pelos dois algoritmos
        vector<int> copia_conjunto = conjunto;

        // Medir o tempo para o Quicksort
        clock_t inicio_quicksort = clock();
        quicksort(copia_conjunto, 0, tamanho - 1);
        clock_t fim_quicksort = clock();
        double tempo_quicksort = (double)(fim_quicksort - inicio_quicksort) / CLOCKS_PER_SEC;

        // Medir o número de trocas para o Quicksort
        int trocas_quicksort = copia_conjunto.size() - 1;

        // Copiar o vetor original novamente
        copia_conjunto = conjunto;

        // Medir o tempo para o Heapsort
        clock_t inicio_heapsort = clock();
        heapsort(copia_conjunto);
        clock_t fim_heapsort = clock();
        double tempo_heapsort = (double)(fim_heapsort - inicio_heapsort) / CLOCKS_PER_SEC;

        // Medir o número de trocas para o Heapsort
        int trocas_heapsort = copia_conjunto.size() - 1;

        // Imprimir os resultados
        cout << "Tamanho do vetor: " << tamanho << endl;
        cout << "Quicksort: Tempo = " << tempo_quicksort << " segundos, Trocas = " << trocas_quicksort << endl;
        cout << "Heapsort: Tempo = " << tempo_heapsort << " segundos, Trocas = " << trocas_heapsort << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}