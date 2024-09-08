//
// Created by laura on 7/09/2024.
//

#ifndef ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
#define ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
#include <iostream>
#include <stdexcept>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} // Constructor para Node
};

struct ForwardList {
    Node* head;

    ForwardList() : head(nullptr) {} // Constructor por defecto

    ~ForwardList() { // Destructor
        clear();
        std::cout << "Se ha destruido ForwardList." << std::endl;
    }

    int front() { // Retorna el elemento al comienzo
        if (head == nullptr) {
            throw std::runtime_error("La lista está vacía.");
        }
        return head->data;
    }

    int back() { // Retorna el elemento al final
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(int valor) { // Agrega un elemento al comienzo
        Node* temp = new Node(valor);
        temp->next = head;
        head = temp;
    }

    void push_back(int valor) { // Agrega un elemento al final
        if (head == nullptr) {
            push_front(valor);
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(valor);
    }

    int pop_front() { // Remueve el elemento al comienzo
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        Node* temp = head;
        head = head->next;
        int return_value = temp->data;
        delete temp;
        return return_value;
    }

    int pop_back() { // Remueve el elemento al final
        if (head == nullptr) {
            throw std::runtime_error("La lista está vacía.");
        }
        if (head->next == nullptr) {
            int return_value = head->data;
            delete head;
            head = nullptr;
            return return_value;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int return_value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return return_value;
    }

    int operator[](int n) { // Retorna el elemento en la posición indicada
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Índice fuera de rango.");
        }
        Node* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() { // Retorna si la lista está vacía o no
        return (head == nullptr);
    }

    int size() { // Retorna el tamaño de la lista
        Node* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void clear() { // Elimina todos los elementos de la lista
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse() { // Revierte la lista
        if (empty()) {
            return;
        }
        Node* temp = nullptr;
        Node* node;
        while (head != nullptr) {
            node = head;
            head = head->next;
            node->next = temp;
            temp = node;
        }
        head = temp;
    }

    friend std::ostream& operator<<(std::ostream& os, ForwardList& list) {
        Node* node = list.head;
        while (node != nullptr) {
            os << node->data << " ";
            node = node->next;
        }
        return os;
    }
};

// termina

void forward_list_test(){
    ForwardList list;

    // Prueba de inserción al frente
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    // Prueba de inserción al final
    list.push_back(40);
    list.push_back(50);

    // Mostrar la lista
    std::cout << "Lista después de push_front y push_back: " << list << std::endl;

    // Probar front() y back()
    std::cout << "Elemento al frente: " << list.front() << std::endl;
    std::cout << "Elemento al final: " << list.back() << std::endl;

    // Prueba de pop_front y pop_back
    std::cout << "Eliminando elemento al frente: " << list.pop_front() << std::endl;
    std::cout << "Eliminando elemento al final: " << list.pop_back() << std::endl;

    // Mostrar la lista después de pop_front y pop_back
    std::cout << "Lista después de pop_front y pop_back: " << list << std::endl;

    // Prueba de operador[]
    std::cout << "Elemento en la posición 0: " << list[0] << std::endl;

    // Prueba de reverse()
    list.reverse();
    std::cout << "Lista después de reverse: " << list << std::endl;

    // Prueba de clear()
    list.clear();
    std::cout << "Lista después de clear: " << list << std::endl;
}
#endif //ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
