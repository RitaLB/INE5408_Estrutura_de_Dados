#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>


namespace structures {

template<typename T>
class ArrayList {
public:
    ArrayList();
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;
    // descricao do 'operator []' na FAQ da disciplina
    bool out_of_range_index()

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};

}

#endif

template<typename T>
structures::ArrayList<T>::ArrayList() {
   max_size_ = DEFAULT_SIZE;
   contents = new T[max_size_];
   size_ = 0;
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
   max_size_ = DEFAULT_SIZE;
   contents = new T[max_size];
   size_ = 0;
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
   delete [] contents;
}

// método limpar lista (voltar fim para -1)
template<typename T>
void structures::ArrayList<T>::clear() {

   size_= 0
}

//! metodo insere dado no fim da lista
template<typename T>
void structures::ArrayList<T>::push_back(const T& data){
   if (full()){
        throw std::out_of_range("Fila cheia");
   } else {
    contens[size_] = data
    size_ ++
    //não deveria incrementar end_ também? não tem end nesse modelo
    // qual a diferença de end_ para size_ ?? end_ cumpriria a msm função do size
   }
}

//! metodo insere item no início da fila
template<typename T>
void structures::ArrayList<T>::push_front(const T& data){
   if (full()) {
      throw std::out_of_range("Fila cheia");
      //mover ítens do início para uma casa depois, para vagar a posição da frente para a alocação
   } else {
      for (i = size_; i> 0; i--){
        contents[i] = contents[i-1]
      }
      //adiciona dado no início
      contens[0] = data
      size_ ++
   }
}

//! metodo insere ítem em posição escolhida (index)
template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index){
   if (full()){
    throw std::out_of_range("Fila cheia");
   } else {
    // verifica se índice dado está entre 0 e size_
    if (out_of_range_index()){
        throw std::out_of_range("index out of range");
    } else {
        // vai deslocando ítens à direita da posição escolhida para a direita
        // assim abre lugar no index escolhido para o ítem
        for (i = size_; i> index; i--){
            contents[i] = contents[i-1];
        }
        contents[index] = data;
        size_ ++;
    } 
   }
}

//! insere ítem de forma ordenada 
template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data){
   if (full()){
    throw std::out_of_range("Fila cheia");
   } else {
    // verifica qual a posição data deve ser colocado.
    // ordem baseia-se em referência anterior/posterior , >/<
    i = 0
    while (i< size_ && contents[i] < data){
        i++;
    }
    insert(data, i);
  }
}

//! retira ítem em posição escolhida e o retorna ao programador
template<typename T>
T structures::ArrayList<T>::pop(std::size_t index){
  if (empty()){
    throw std::out_of_range("Fila vazia");
  } else {
    //salva ítem na posição escolhida me variável auxiliar
    aux = contents[index];
    // desloca os ítens a direita do ítem a ser retirado 
    for (i = index +1; i< size_; i++){
        contents[i-1] = contents[i]
    }
    size_ --;
    return aux
  }
}

//! retira ítem do fim da lista
template<typename T>
T structures::ArrayList<T>::pop_back(){
  if (empty()){
    throw std::out_of_range("Fila vazia");
  } else {
    size_ --
    return contents[size_];
  }
}

//! retira ítem do início da lista
template<typename T>
T structures::ArrayList<T>::pop_front(){
  if (empty()){
    throw std::out_of_range("Fila vazia");
  } else {
    aux = contents[0];
    for (i = 1; i < size_; i++) {
    contents[i-1] = contents[i]
  }
  size_ --
  return aux
  }
}
 //! metodo verifica se vazio
template<typename T>
bool structures::ArrayList<T>::empty() {
   if (end_ == -1) {
      return true;
   } else {
      return false;
   }
}

template<typename T>
bool structures::ArrayList<T>::full() {
   if (size_ == (static_cast<int>(max_size_))) {
      return true;
   } else {
      return false;
   }
}
template<typename T>
bool structures::ArrayList<T>::out_of_range_index(){
    // verifica se o inteiro de index é menor que zero ou maior que o tamanho
    // ou seja, verifica se está fora do escopo da lista
    if ((static_cast<int>(index) < 0) || (index > size_)){
        return true
    } else {
        return false
    }
}


