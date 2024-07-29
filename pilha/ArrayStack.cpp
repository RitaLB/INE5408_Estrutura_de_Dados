#include "Implementacão de Pilha em vetor/array_stack.h"
#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

//### por que não implementa as constantes de pilh vazia e cheia -1 e -2 vistas na video aula?
namespace structures {

template<typename T>
//! CLASSE PILHA
class ArrayStack {
 public:
    //! construtor simples
    //structures::ArrayStack<T>::ArrayStack() {
        //###devo definir o tipo e retorno na frente?
    ArrayStack(){
        max_size_ = DEFAULT_SIZE;
        contents = new T[max_size_];
        top_ = -1;
    }
    ArrayStack(std::size_t max){
        max_size_ = max;
        contents = new T[max_size_];
        top_ = -1;
    }
    //! destrutor
    ~ArrayStack(){
        delete [] contents;
    }
    //! metodo empilha
    void push(const T& data){
        if (full()) {
            throw std::out_of_range("pilha cheia");
        } else {
            top_ = top_ +1;
            contents[top_] = data;
            return top_;
        }
    }
    
    //! metodo desempilha
    // ###pq tá retornando t (?) e não um inteiro?
    // ###aqui em c++ não tem self não?
    T pop(){
        if empty() {
            throw std::out_of_range("pilha vazia");
        } else {
            top_ = top_ -1;
            return contents[top_ + 1];
        }

    }
    //! metodo retorna o topo
    // ###pq tá retornando T& e não um inteiro?
    // ### não precisa excluir o dado do topo?
    T& top() {
        if empty(){
            throw std::out_of_range("pilha vazia");
        }else{
            return contents[top_];
        }
    }
    //! metodo limpa pilha
    void clear(){
        //###????
    }
    //! metodo retorna tamanho
    std::size_t size(){
        return size_t
    }
    //! metodo retorna capacidade maxima
    std::size_t max_size(){
        return max_size_
    }

    //! verifica se esta vazia
    bool empty(){
        if (top_ == -1){
            return True
        }else {
            return False
        }
    }
    //! verifica se esta cheia
    bool full(){
        if top_ == (max_size_-1){
            return True
        }else{
            return False
        }
    }

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures


template<typename T>
structures::ArrayStack<T>::ArrayStack() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    top_ = -1;
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete [] contents;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("pilha cheia");
    } else {
        // COLOQUE SEU CODIGO AQUI...
    }
}

template<typename T>
T structures::ArrayStack<T>::pop() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
T& structures::ArrayStack<T>::top() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
void structures::ArrayStack<T>::clear() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    // COLOQUE SEU CODIGO AQUI...
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    // COLOQUE SEU CODIGO AQUI...
}
