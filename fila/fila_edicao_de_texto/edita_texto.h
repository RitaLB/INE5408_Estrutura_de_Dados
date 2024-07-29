// Copyright [2022] <COLOQUE SEU NOME AQUI...>
#include <string>
#include "fila/Implementacão de Fila em vetor/array_queue.h"

/* Escreva uma função para, dado um texto de entrada (na forma de string),
adicione a uma fila caracter por caracter, exceto se for um '<' ou '>'.
    Ao ler o caracter '<' na entrada, a ação é a de remover um elemento (caracter) da fila.
    Em sendo o caracter '>', a ação é a de reinserir o último elemento (caracter) da fila. 

    O retorno da função é a fila resultante, contendo o texto editado.*/

structures::ArrayQueue<char> editaTexto(std::string texto) {
    int  tamanho  = texto.length();
    structures::ArrayQueue<char> fila(500);

    for ( int i= 0; i < tamanho; i++){

        if (texto[i] ==  '<'){
            fila.dequeue();
        } else if (texto[i] == '>'){
            char back = fila.back();
            fila.enqueue(back);
        } else {
            fila.enqueue(texto[i]);
        }
        
    }

    return fila;
}
