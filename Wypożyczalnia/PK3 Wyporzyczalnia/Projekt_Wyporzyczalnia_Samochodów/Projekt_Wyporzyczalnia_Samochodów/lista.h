#pragma once
#include "main_header.h"

template <typename T>
class List {
private:
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(const T& data) : data(data) {}
    };
    unique_ptr<Node> head;
    int size_;

public:
    // Konstruktor bezargumentowy
    List() : size_(0) {}

    // Konstruktor kopiuj¹cy
    List(const List& other) : size_(0) {
        Node* current = other.head.get();
        while (current) {
            PushBack(current->data);
            current = current->next.get();
        }
    }

    // Konstruktor przenosz¹cy
    List(List&& other) : size_(0) {
        head = move(other.head);
        size_ = other.size_;
        other.size_ = 0;
    }

    // Destruktor
    ~List() {
        Clear();
    }

    // Operatory przypisania
    List& operator=(const List& other) {
        List temp(other);
        swap(head, temp.head);
        swap(size_, temp.size_);
        return *this;
    }

    // Operatory przeniesienia
    List& operator=(List&& other) {
        swap(head, other.head);
        swap(size_, other.size_);
        return *this;
    }

    // Dodawanie elementów do kontenera
    void PushBack(const T& data) {
        if (head) {
            Node* current = head.get();
            while (current->next) {
                current = current->next.get();
            }
            current->next = make_unique<Node>(data);
        }
        else {
            head = make_unique<Node>(data);
        }
        size_++;
    }

    // Usuwanie wybranego elementu
    void Remove(const T& data) {
        if (head) {
            if (head->data == data) {
                head = move(head->next);
                size_--;
            }
            else {
                Node* current = head.get();
                while (current->next && current->next->data != data) {
                    current = current->next.get();
                }
                if (current->next) {
                    current->next = move(current->next->next);
                    size_--;
                }
            }
        }
    }

    // Wyszukiwanie elementu
    bool Contains(const T& data) const {
        Node* current = head.get();
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    }
    // Sortowanie zawartoœci (rosn¹co)
    void Sort() {
        if (size_ > 1) {
            bool sorted = false;
            while (!sorted) {
                Node* current = head.get();
                Node* previous = nullptr;
                sorted = true;
                while (current->next) {
                    if (current->data > current->next->data) {
                        sorted = false;
                        if (previous) {
                            previous->next = move(current->next);                       //nie dziala, dzialajace sortowanie jest w programie testowanieListy
                            current->next = move(previous->next->next);
                            previous->next->next = move(current);
                            current = previous->next.get();
                        }
                        else {
                            head = move(current->next);
                            current->next = move(head->next);
                            head->next = move(current);
                            current = head.get();
                        }
                    }
                    else {
                        previous = current;
                        current = current->next.get();
                    }
                }
            }
        }
    }

    // Sortowanie zawartoœci (malej¹co)
    void SortDescending() {
        if (size_ > 1) {
            bool sorted = false;
            while (!sorted) {
                Node* current = head.get();
                Node* previous = nullptr;
                sorted = true;
                while (current->next) {
                    if (current->data < current->next->data) {
                        sorted = false;
                        if (previous) {
                            previous->next = move(current->next);
                            current->next = move(previous->next->next);
                            previous->next->next = move(current);
                            current = previous->next.get();
                        }
                        else {
                            head = move(current->next);
                            current->next = move(head->next);
                            head->next = move(current);
                            current = head.get();
                        }
                    }
                    else {
                        previous = current;
                        current = current->next.get();
                    }
                }
            }
        }
    }

    // Serializacja
    void Serialize(ofstream& out) const {
        out.write(reinterpret_cast<const char*>(&size_), sizeof(size_));
        Node* current = head.get();
        while (current) {
            out.write(reinterpret_cast<const char*>(&current->data), sizeof(current->data));
            current = current->next.get();
        }
    }

    // Deserializacja
    void Deserialize(ifstream& in) {
        Clear();
        in.read(reinterpret_cast<char*>(&size_), sizeof(size_));
        for (int i = 0; i < size_; i++) {
            T data;
            in.read(reinterpret_cast<char*>(&data), sizeof(data));
            PushBack(data);
        }
    }
    // Czyszczenie zawartoœci
    void Clear() {
        head.reset();
        size_ = 0;
    }

    // Zwraca rozmiar kontenera
    int Size() const {
        return size_;
    }

    // Zwraca true, jeœli kontener jest pusty
    bool Empty() const {
        return size_ == 0;
    }

};