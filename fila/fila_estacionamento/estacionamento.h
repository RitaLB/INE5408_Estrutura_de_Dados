// Copyright [2023] <COLOQUE SEU NOME AQUI...>

#include <string>
#include "fila/Implementacão de Fila em vetor/array_queue.h"


//Remova o k-ésimo veículo de uma fila f. O primeiro veículo está na posição 1, o segundo na posição 2 e assim por diante
void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    for (int i = 0; i <  k-1; i++) {
        int carro_fica = f->dequeue();
        f->enqueue(carro_fica);
    }
    f->dequeue();
}


// Mantenha apenas o k-ésimo elemento de uma fila f, removendo todos os demais.
void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    // ### int tamanho = f.size(); porque não funciona? o que significa a seta?
    
    for (int i = 0; i < k-1; i++) {
        f->dequeue();
    }
    int carro_fica = f->dequeue();
    f->enqueue(carro_fica);

    int tamanho = f->size();
    for (int i =0; i < (tamanho-1); i++) {
        f->dequeue();
    }
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
