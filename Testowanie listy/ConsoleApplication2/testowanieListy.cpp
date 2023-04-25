#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include<time.h>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;


template <typename T>
class List {
public:
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(const T& data) : data(data) {}
    };
    unique_ptr<Node> head;
    int size_;

    // Konstruktor bezargumentowy
    List() : size_(0) {}

    // Konstruktor kopiujący
    List(const List& other) : size_(0) {
        Node* current = other.head.get();
        while (current) {
            PushBack(current->data);
            current = current->next.get();
        }
    }

    // Konstruktor przenoszący
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
    // funkcja sortujaca dane rosnaco
    void SortAscending() {
        vector<T> temp;
        Node* current = head.get();
        while (current) {
            temp.push_back(current->data);
            current = current->next.get();
        }
        sort(temp.begin(), temp.end());
        Clear();
        for (const auto& data : temp) {
            PushBack(data);
        }
    }

    // Funkcja sortująca dane malejaco
    void SortDescending() {
        vector<T> temp;
        Node* current = head.get();
        while (current) {
            temp.push_back(current->data);
            current = current->next.get();
        }
        sort(temp.rbegin(), temp.rend());
        Clear();
        for (const auto& data : temp) {
            PushBack(data);
        }
    }

    // Sortowanie zawartości (rosnąco)
    /*void Sort() {
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
                            previous->next = move(current->next);
                            current->next = move(previous->next->next);
                            previous->next->next = move(current);                                                   nie dziala
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

    // Sortowanie zawartości (malejąco)
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
    */
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
    // Czyszczenie zawartości
    void Clear() {
        head.reset();
        size_ = 0;
    }

    // Zwraca rozmiar kontenera
    int Size() const {
        return size_;
    }

    // Zwraca true, jeśli kontener jest pusty
    bool Empty() const {
        return size_ == 0;
    }

};
int main() {
    List<double> list;
    list.PushBack(2.5);
    list.PushBack(3.1);
    list.PushBack(1.7);
    list.PushBack(4.0);
    list.PushBack(1.2);

    cout << "Zawartosc listy przed sortowaniem: ";
    auto current = list.head.get();
    while (current) {
        cout << current->data << " ";
        current = current->next.get();
    }
    cout << endl;

    list.SortAscending();

    cout << "Zawartosc listy po sortowaniu rosnaco: ";
    current = list.head.get();
    while (current) {
        cout << current->data << " ";
        current = current->next.get();
    }
    cout << endl;

    list.SortDescending();

    cout << "Zawartosc listy po sortowaniu malejaco: ";
    current = list.head.get();
    while (current) {
        cout << current->data << " ";
        current = current->next.get();
    }
    cout << endl;

    list.Remove(3.1);

    cout << "Zawartosc listy po usunieciu: ";
    current = list.head.get();
    while (current) {
        cout << current->data << " ";
        current = current->next.get();
    }
    cout << endl;

    return 0;
}
