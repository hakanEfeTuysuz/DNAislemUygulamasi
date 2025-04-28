/**
* @file doublylinkedlist.cpp
* @description doublylinkedlist kaynak dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

// Constructor
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Listeye yeni gen ekler
void DoublyLinkedList::append(char gene) {
    Node* newNode = new Node;
    newNode->gene = gene;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // Liste boşsa, yeni düğüm baş olur
    }

    tail = newNode; // Yeni düğüm kuyruğa eklenir
    listSize++;
}

// Listeyi baştan sona doğru yazdırır
void DoublyLinkedList::printForward() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->gene << " ";
        current = current->next;
    }
    cout << endl;
}

// Listeyi sondan başa doğru yazdırır
void DoublyLinkedList::printBackward() const {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->gene << " ";
        current = current->prev;
    }
    cout << endl;
}

// Mutasyon işlemi
void DoublyLinkedList::mutate(int genePos) {
    if (genePos < 0 || genePos >= listSize) {
        cout << "Geçersiz gen pozisyonu!" << endl;
        return;
    }

    Node* current = getNodeAt(genePos);
    if (current) {
        current->gene = 'X'; // Gen mutasyona uğradı
        cout << "Mutasyon tamamlandi!" << endl;
    }
}

// Belirli pozisyondaki düğümü döndürür
Node* DoublyLinkedList::getNodeAt(int position) const {
    if (position < 0 || position >= listSize) return nullptr;

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current;
}

// Liste boyutunu döndürür
int DoublyLinkedList::getSize() const {
    return listSize;
}

Node* DoublyLinkedList::getTail() const {
    return tail;
}

// Belirli bir aralıktan düğümleri ekler
void DoublyLinkedList::appendFromTo(Node* from, Node* to) {
    Node* current = from;
    while (current != to) {
        append(current->gene);
        current = current->next;
    }

    if (to != nullptr) {
        append(to->gene); // 'to' düğümünü de ekle
    }
}
