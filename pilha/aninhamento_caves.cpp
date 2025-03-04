// Copyright [2022] <COLOQUE SEU NOME AQUI...>
#include <string>
#include "./array_stack.h"


bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);

    for (int i = 0; i < tamanho; i++) {
        // condições de parada dor 'for' podem ser adicionadas...

        if (trecho_programa[i] == '{') {
            pilha.push('{');
        } else if (trecho_programa[i] == '}') {
            if (pilha.empty()) {
                resposta = false;
                break;
            } else {
                pilha.pop();
            }
        }
    }

    if (!(pilha.empty())) {
        resposta = false;
    }
    return resposta;
}

