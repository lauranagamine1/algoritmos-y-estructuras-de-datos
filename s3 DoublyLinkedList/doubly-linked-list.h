//
// Created by laura on 5/09/2024.
//

#ifndef ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_DOUBLY_LINKED_LIST_H
#define ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

// Nodo para la lista doblemente enlazada
template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T data) : data(data), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int listSize;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Retorna el elemento al comienzo
    T front() {
        if (empty()) throw out_of_range("List is empty");
        return head->data;
    }

    // Retorna el elemento al final
    T back() {
        if (empty()) throw out_of_range("List is empty");
        return tail->data;
    }

    // Agrega un elemento al comienzo
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    // Agrega un elemento al final
    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    // Remueve el elemento al comienzo
    T pop_front() {
        if (empty()) throw out_of_range("List is empty");
        Node<T>* temp = head;
        T data = head->data;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        listSize--;
        return data;
    }

    // Remueve el elemento al final
    T pop_back() {
        if (empty()) throw out_of_range("List is empty");
        Node<T>* temp = tail;
        T data = tail->data;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        listSize--;
        return data;
    }

    // Inserta en cualquier posición
    void insert(T value, int position) {
        if (position < 0 || position > listSize) throw out_of_range("Position out of range");

        if (position == 0) {
            push_front(value);
        } else if (position == listSize) {
            push_back(value);
        } else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            listSize++;
        }
    }

    // Remueve en cualquier posición
    void remove(int position) {
        if (position < 0 || position >= listSize) throw out_of_range("Position out of range");

        if (position == 0) {
            pop_front();
        } else if (position == listSize - 1) {
            pop_back();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            listSize--;
        }
    }

    // Retorna el elemento en la posición indicada
    T operator[](int position) {
        if (position < 0 || position >= listSize) throw out_of_range("Position out of range");
        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Retorna si la lista está vacía o no
    bool empty() {
        return listSize == 0;
    }

    // Retorna el tamaño de la lista
    int size() {
        return listSize;
    }

    // Elimina todos los elementos de la lista
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Revierte la lista
    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        tail = head;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) head = temp->prev;
    }

    // Función para imprimir la lista (solo para depuración)
    void print() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void doubly_linked_list_test(){
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(4, 4);
    list.remove(1);
    list.reverse();

    list.print(); // Imprime la lista en orden reverso

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.size() << endl;
}
#endif //ALGORITMOS_Y_ESTRUCTRUAS_DE_DATOS_GIT_DOUBLY_LINKED_LIST_H
