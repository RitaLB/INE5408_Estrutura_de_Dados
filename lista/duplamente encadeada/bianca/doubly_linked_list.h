//! Copyright [2023] Bianca Mazzuco Verzola

namespace structures {

template<typename T>
class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();

    void push_back(const T& data);  // insere no fim
    void push_front(const T& data);  // insere no início
    void insert(const T& data, std::size_t index);  // insere na posição
    void insert_sorted(const T& data);  // insere em ordem

    T pop(std::size_t index);  // retira da posição
    T pop_back();  // retira do fim
    T pop_front();  // retira do início
    void remove(const T& data);  // retira específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // contém

    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    const T& at(std::size_t index) const;  // getter constpreve a um elemento

    std::size_t find(const T& data) const;  // posição de um dado
    std::size_t size() const;  // tamanho

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        Node(const T& data, Node* prev, Node* next):
            data_{data},
            next_{next},
            prev_{prev}
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

        Node* prev() {  // getter: prev
            return prev_;
        }

        const Node* prev() const {  // getter const: prev
            return prev_;
        }

        void prev(Node* node) {  // setter: prev
            prev_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
        Node* prev_{nullptr};
    };

    Node *posicao(std::size_t index) {
        Node *p;
        if (index < size() / 2) {  // primeira metade
            p = head;
            for (std::size_t i = 0; i < index; i++) {
                p = p->next();
            }
        } else {  // segunda metade
            p = tail;
            for (std::size_t i = size()-1; i > index; i--) {
                p = p->prev();
            }
        }
        return p;
    }

    Node* head;  // primeiro da lista
    Node* tail;  // ultimo da lista
    std::size_t size_;
};

}  // namespace structures


// construtor
template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

// destrutor
template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// clear
template<typename T>
void structures::DoublyLinkedList<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

// push back
template<typename T>
void structures::DoublyLinkedList<T>::push_back(const T& data) {
    Node* novo = new Node(data, tail, nullptr);
    if (empty())
        head = novo;
    else
         tail->next(novo);
    tail = novo;
    size_++;
}

// push front
template<typename T>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
    Node* novo = new Node(data, nullptr, head);
    if (empty()) {
        tail = novo;
    } else {
        head->prev(novo);
    }
    head = novo;
    size_++;
}

// insert
template<typename T>
void structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    if (index < 0 || index > size_) {
        throw std::out_of_range("index inválido");
    } else if (index == 0) {
        return push_front(data);
    } else if (index == size_) {
        return push_back(data);
    } else {
        Node* novo = new Node(data);
        Node* p = posicao(index);
        p->prev()->next(novo);
        novo->next(p);
        novo->prev(p->prev());
        p->prev(novo);
        size_++;
    }
}

// insert sorted
template<typename T>
void structures::DoublyLinkedList<T>::insert_sorted(const T& data) {
    size_t i = 0;
    Node *p = head;
    while (i < size_ && p->data() < data) {
        p = p->next();
        i++;
    }
    return insert(data, i);
}

// pop
template<typename T>
T structures::DoublyLinkedList<T>::pop(std::size_t index) {
    if (index < 0 || index > size_ - 1) {
        throw std::out_of_range("index inválido");
    } else if (index == 0) {
        return pop_front();
    } else if (index == size_ - 1) {
        return pop_back();
    } else {
        Node *sai = posicao(index);
        sai->prev()->next(sai->next());
        sai->next()->prev(sai->prev());
        T aux = sai->data();
        delete sai;
        size_--;
        return aux;
    }
}

// pop back
template<typename T>
T structures::DoublyLinkedList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        Node *sai = tail;
        if (size_ == 1)
            head = nullptr;
        else
            sai->prev()->next(nullptr);
        tail = sai->prev();
        T aux = sai->data();
        delete sai;
        size_--;
        return aux;
    }
}

// pop front
template<typename T>
T structures::DoublyLinkedList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    } else {
        Node *sai = head;
        if (size_ == 1)
            tail = nullptr;
        else
            sai->next()->prev(nullptr);
        head = sai->next();
        T aux = sai->data();
        delete sai;
        size_--;
        return aux;
    }
}

// remove
template<typename T>
void structures::DoublyLinkedList<T>::remove(const T& data) {
    size_t i = 0;
    Node* p = head;
    while (p->data() != data && i < size_) {
        p = p->next();
        i++;
    }
    pop(i);
}

// empty
template<typename T>
bool structures::DoublyLinkedList<T>::empty() const {
    if (size_ == 0)
        return true;
    else
        return false;
}

// contains
template<typename T>
bool structures::DoublyLinkedList<T>::contains(const T& data) const {
    return find(data) < size_;
}

// at
template<typename T>
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index invalido");
    } else {
        Node *p = posicao(index);
        T& aux = p->data();
        return aux;
    }
}

// at const
template<typename T>
const T& structures::DoublyLinkedList<T>::at(std::size_t index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index invalido");
    } else {
        Node *p = posicao(index);
        const T& aux = p->data();
        return aux;
    }
}

// find
template<typename T>
size_t structures::DoublyLinkedList<T>::find(const T& data) const {
    Node *p = head;
    std::size_t i = 0;
    while (i < size_ && p->data() != data) {
        p = p->next();
        i++;
    }
    return i;
}

// size
template<typename T>
size_t structures::DoublyLinkedList<T>::size() const {
    return size_;
}
