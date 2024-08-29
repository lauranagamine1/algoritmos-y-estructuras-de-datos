#ifndef ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H
#define ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {} // Constructor for Node
};

template <typename T>
class ForwardList {
private:
    Node<T>* head;

public:
    ForwardList() : head(nullptr) {} // Default constructor

    ~ForwardList() { // Destructor
        clear();
        std::cout << "Se ha destruido ForwardList." << std::endl;
    }

    T front() { // Retorna el elemento al comienzo
        if (head == nullptr) {
            throw std::runtime_error("La lista está vacía.");
        }
        return head->data;
    }

    T back() { // Retorna el elemento al final
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T valor) { // Agrega un elemento al comienzo
        Node<T>* temp = new Node<T>(valor);
        temp->next = head;
        head = temp;
    }

    void push_back(T valor) { // Agrega un elemento al final
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

    T pop_front() { // Remueve el elemento al comienzo
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        Node<T>* temp = head;
        head = head->next;
        T return_value = temp->data;
        delete temp;
        return return_value;
    }

    T pop_back() { // Remueve el elemento al final
        if (head == nullptr) {
            throw std::runtime_error("La lista está vacía.");
        }
        if (head->next == nullptr) {
            T return_value = head->data;
            delete head;
            head = nullptr;
            return return_value;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T return_value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return return_value;
    }

    T operator[](int n) { // Retorna el elemento en la posición indicada
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Índice fuera de rango.");
        }
        Node<T>* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() { // Retorna si la lista está vacía o no
        return head == nullptr;
    }

    int size() { // Retorna el tamaño de la lista
        Node<T>* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void clear() { // Elimina todos los elementos de la lista
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse() { // Revierte la lista
        if (empty()) {
            return;
        }
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

#endif // ESTRUCTURAS_DE_DATOS_LAURA_FORWARD_LIST_H
