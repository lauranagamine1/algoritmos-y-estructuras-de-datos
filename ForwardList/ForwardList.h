//
// Created by laura on 27/08/2024.
//

#ifndef ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H
#define ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class ForwardList {
private:
    Node<T>* head;

public:
    ForwardList(){ // constructor default
        head = nullptr;
    }
    ~ForwardList(){ // destructor
        std::cout<<"Se ha destruido ForwardList."<<endl;
    }

    T front(){ // Retorna el elemento al comienzo
        if (head->data){
            return head->data;
        } else{
            throw std::runtime_error("Está vacío.");
        }
    }

    T back(){ // Retorna el elemento al final
        if (empty()) {
            throw std::runtime_error("La lista esta vacia.");
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void push_front(T){ // Agrega un elemento al comienzo
        auto* temp = new Node<T>(valor);
        temp->next = head;
        head = temp;
    }
    void push_back(T){ // Agrega un elemento al final
        if (head == nullptr) {
            push_front(valor);
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node<T>(valor);
    }
    T pop_front(){ // Remueve el elemento al comienzo
        if (empty()) {
            throw std::runtime_error("Lista vacia.");
        }
        // Remueve el elemento al comienzo
        Node<T>* temp = head;
        head = head->next;
        T return_value = temp->data;
        delete temp;
        return return_value;
    }
    T pop_back(){ // Remueve el elemento al final
        if (head == nullptr) {
            throw std::runtime_error("Lista vacia.");
        }
        // Remueve el elemento al final
        Node<T>* temp = head;
        if (temp->next == nullptr) {
            T return_value = temp->data;
            delete temp;
            return return_value;
        }
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T return_value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return return_value;
    }
    T operator[ ](int){ // Retorna el elemento en la posición indicada
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Indice fuera de rango.");
        }
        // Retorna el elemento en la posición indicada
        Node<T>* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    bool empty(){ // Retorna si la lista está vacía o no
        if (head == nullptr){
            return true;
        } else{
            return false;
        }
    }
    int size(){ // Retorna el tamaño de la lista
        Node<T>* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }
    void clear(){ // Elimina todos los elementos de la lista
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void reverse(){ // Revierte la lista
        if (empty()) {
            return;
        }
        // Revierte la lista
        Node<T>* temp = nullptr;
        Node<T>* node;
        while (head != nullptr) {
            node = head;
            head = head->next;
            node->next = temp;
            temp = node;
        }
        head = temp;
    }
    friend std::ostream& operator<<(std::ostream& os, ForwardList<T>& list) {
        Node<T>* node = list.head;
        while (node != nullptr) {
            os << node->data << " ";
            node = node->next;
        }
        return os;
    }
};


#endif //ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H
