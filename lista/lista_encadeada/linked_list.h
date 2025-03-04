//! Copyright [year] <Copyright Owner>
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>


namespace structures {

//! ...
template<typename T>
class LinkedList {
 public:
    //! ...
    LinkedList();  // construtor padrão
    //! ...
    ~LinkedList();  // destrutor
    //! ...
    void clear();  // limpar lista
    //! ...
    void push_back(const T& data);  // inserir no fim
    //! ...
    void push_front(const T& data);  // inserir no início
    //! ...
    void insert(const T& data, std::size_t index);  // inserir na posição
    //! ...
    void insert_sorted(const T& data);  // inserir em ordem
    //! ...
    T& at(std::size_t index);  // acessar um elemento na posição index
    //! ...
    T pop(std::size_t index);  // retirar da posição
    //! ...
    T pop_back();  // retirar do fim
    //! ...
    T pop_front();  // retirar do início
    //! ...
    void remove(const T& data);  // remover específico
    //! ...
    bool empty() const;  // lista vazia
    //! ...
    bool contains(const T& data) const;  // contém
    //! ...
    std::size_t find(const T& data) const;  // posição do dado
    //! ...
    std::size_t size() const;  // tamanho da lista

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}
        //explicit Node(const t& data){
            //data_ = data
        //}
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            // como it é um ponteiro, estou acessando a função do objeto apontado por it
            // então usi -> metodo()
            it = it->next();
        }
        return it;
    }
    // head = nullptr
    Node* head{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures

#endif

// construtor
template<typename T>
structures::LinkedList<T>::LinkedList() {
   Node* head = nullptr;
   size_ = 0u;
}

// destrutor
template<typename T>
structures::LinkedList<T>::~LinkedList() {
   clear();
}

// limpar lista
template<typename T>
void structures::LinkedList<T>::clear() {
   while (!empty())
   {
    pop_front()
   }
}

// inserir no fim
template<typename T>
void structures::LinkedList<T>::push_back(const T& data){  
    Node *p, *novo;
    p = head;
    if (empty()){
        push_front(data);
        return // ???
            }
    novo = new Node (data, nullptr);
    // da onde tirou essa forma de lidar com exessão?
    if (novo == nullptr) {
        throw stc::out_of_range("Memória cheia")
    } else {
        while (p -> next() != nullptr) {
            p = p -> next(); //?? onde determina qual vai ser o next? não entendi
        }
        p -> next(novo);
        size_++;
    }
}

// inserir no início
template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
    Node * novo;
    novo = new Node(data);
    if (noovo == nullptr) {
        throw std::out_of_range("Memória cheia");
    } else {
        novo -> next(head);
        // pq as vezes coloca coisa de parâmetro e as vezes não?
        head = novo;
        size_++;
    }
}

// inserir na posição
template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
    if((0 <= static_cast<int>(index)) && (index <= size())){
        if (static_cast<int>(index) == 0) {
            push_front(data); // se i índice for 0, insere na frente
            return;
        } else if (index == size()) {
            push_back(data); // se o índice for o último + 1, insere atrás
            return
        } else {
            Node *novo, *p;
            p = head;
            novo = new Node(data);
            if (novo == nullptr) {
                throw std::out_of_range("Memória cheia");
            } else {
                for (int i = 1; i< static_cast<int>(idex); i++){
                    p = p -> next();
                }
                novo -> next(p -> next());
                p -> next(novo);
                size_ ++;
            }
        }
    } else {
        throw std::out_of_range("Posição fora da lista");
    }
}

// inserir em ordem
template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data) {
    Node *p;
    temp = head;
    int i = 0;
    while (i < static_cast<int>(size_) && p->data() < data) {
        p = p->next();
        i++;
    }
    insert(data, i);
}

// acessar um elemento na posição index
template<typename T>
T& structures::LinkedList<T>::at(std::size_t index) {
    if (static_cast<int>(index) >= 0 && index < size_) {
        Node *p = head;
        for (int i = 0; i < static_cast<int>(index); i++) {
            p = p->next();
        }
        T& aux = p->data();
        return aux;
    } else {
        throw std::out_of_range("Elemento fora da lista");
    }
}

// retirar da posição
template<typename T>
T structures::LinkedList<T>::pop(std::size_t index) {
    if (empty() || !(0 <= static_cast<int>(index) && index < size_)) {
        throw std::out_of_range("Lista vazia");
    } else {
        Node *p = head;
        for (int i = 0; i < static_cast<int>(index) - 1; i++) {
            p = p->next();
        }
        Node *q = p->next();
        p->next(q->next());
        T aux = q->data();
        delete q;
        size_--;
        return aux;
    }
}

// retirar do fim
template<typename T>
T structures::LinkedList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (size_ == 1) {
        return pop_front();
    } else {
        Node *p = head;
        for (int i = 0; i < static_cast<int>(size_) - 2; i++) {
            p = p->next();
        }
        Node *q = p->next();
        p->next(nullptr);
        T aux = q->data();
        delete q;
        size_--;
        return aux;
    }
}

 // retirar do início
template<typename T>
T structures::LinkedList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        Node *p = head;
        head = p->next();
        T aux = p->data();
        delete p;
        size_--;
        return aux;
    }
}

// lista vazia
template<typename T>
bool structures::LinkedList<T>::empty() const {
    return (size_ == 0);
}


// contém
template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
    Node *temp = head;
    for (int i = 0; i < static_cast<int>(size_); i++) {
        if (temp->data() == data) {
            return true;
        }
        temp = temp->next();
    }
    return false;
}

// posição do dado
template<typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const {
    int i = 0;
    Node *temp = head;
    while (i < static_cast<int>(size_) && temp->data() != data) {
        temp = temp->next();
        i++;
    }
    return i;
}

// remover específico
template<typename T>
void structures::LinkedList<T>::remove(const T& data) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        if (contains(data)) {
            std::size_t i = find(data);
            pop(i);
        }
    }
}

// tamanho da lista
template<typename T>
std::size_t structures::LinkedList<T>::size() const {
    return size_;
}