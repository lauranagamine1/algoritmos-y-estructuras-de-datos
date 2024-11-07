//
// Created by laura on 7/09/2024.
//

#ifndef ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
#define ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
#include <iostream>
#include <stdexcept>

struct ListNode {
    int val;
    ListNode* next;

    // Constructor por defecto
    ListNode() : val(0), next(nullptr) {}

    // Constructor con valor
    ListNode(int x) : val(x), next(nullptr) {}

    // Destructor
    ~ListNode() {
        clear();
        std::cout << "Se ha destruido ListNode." << std::endl;
    }
    // Elimina todos los elementos de la lista
    void clear() {
        ListNode* temp = this;
        while (next != nullptr) {
            ListNode* to_delete = next;
            next = next->next;
            delete to_delete;
        }
        val = 0;
        next = nullptr;
    }

    // Sobrecarga del operador de salida para imprimir la lista
    friend std::ostream& operator<<(std::ostream& os, const ListNode& node) {
        const ListNode* current = &node;
        current = current->next;
        while (current) {
            os << current->val;
            if (current->next) {
                os << " -> ";
            }
            current = current->next;
        }
        return os;
    }

    // Retorna el elemento al comienzo
    int front() {
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        return val;
    }

    // Agrega un elemento al comienzo
    void push_front(int valor) {
        ListNode* temp = new ListNode(val);
        temp->next = next;
        val = valor;
        next = temp;
    }

    // Agrega un elemento al final
    void push_back(int valor) {
        ListNode* temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(valor);
    }

    // Retorna el elemento al final
    int back() {
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        ListNode* temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->val;
    }

    // Remueve el elemento al comienzo
    int pop_front() {
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        int return_value = val;
        if (next != nullptr) {
            ListNode* temp = next;
            val = next->val;
            next = next->next;
            delete temp;
        } else {
            clear();
        }
        return return_value;
    }

    // Remueve el elemento al final
    int pop_back() {
        if (empty()) {
            throw std::runtime_error("La lista está vacía.");
        }
        if (next == nullptr) {
            int return_value = val;
            clear();
            return return_value;
        }
        ListNode* temp = this;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int return_value = temp->next->val;
        delete temp->next;
        temp->next = nullptr;
        return return_value;
    }

    // Retorna el elemento en la posición indicada
    int operator[](int n) {
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Índice fuera de rango.");
        }
        ListNode* temp = this;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    // Retorna si la lista está vacía o no
    bool empty() {
        return (next == nullptr && val == 0);
    }

    // Retorna el tamaño de la lista
    int size() {
        ListNode* temp = this;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size-1;
    }

};

// Prueba de la funcionalidad
void listnode_test() {
    // Crear una lista vacía
    ListNode list;

    // Comprobando que la lista esté vacía
    std::cout << "Lista vacía: " << std::boolalpha << list.empty() << std::endl;

    // Insertando elementos en la lista
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    // Imprimiendo la lista después de las inserciones
    std::cout << "Lista después de push_front y push_back: " << list << std::endl;

    // Comprobando el tamaño de la lista
    std::cout << "Tamaño de la lista: " << list.size() << std::endl;

    // Comprobando los elementos al frente y atrás
    std::cout << "Primer elemento (front): " << list.front() << std::endl;
    std::cout << "Último elemento (back): " << list.back() << std::endl;

    // Accediendo a elementos por índice
    std::cout << "Elemento en índice 2: " << list[2] << std::endl;

    // Remover el primer y último elemento
    int pop_f = list.pop_front();
    std::cout << "Se eliminó del frente: " << pop_f << std::endl;
    std::cout << "Lista tras pop_front: " << list << std::endl;

    int pop_b = list.pop_back();
    std::cout << "Se eliminó del final: " << pop_b << std::endl;
    std::cout << "Lista tras pop_back: " << list << std::endl;

    // Limpiando la lista
    list.clear();
    std::cout << "Lista después de clear: " << list << std::endl;
    std::cout << "Lista vacía: " << std::boolalpha << list.empty() << std::endl;
}

#endif //ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_FORWARDLIST_STRUCT_H
