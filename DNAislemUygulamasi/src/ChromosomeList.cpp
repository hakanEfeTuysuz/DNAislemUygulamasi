/**
* @file ChromosomeList.cpp
* @description ChromosomeList kaynak dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#include "ChromosomeList.hpp"
#include <iostream>
using namespace std;

ChromosomeList::ChromosomeList() {
    head = nullptr;
    size = 0;
}

ChromosomeList::~ChromosomeList() {
    ChromosomeNode* current = head;
    while (current != nullptr) {
        ChromosomeNode* nextNode = current->next;
        delete current->chromosome; // Kromozom nesnesini temizle
        delete current;             // Düğümü temizle
        current = nextNode;
    }
}

void ChromosomeList::append(DoublyLinkedList* chromosome) {
    ChromosomeNode* newNode = new ChromosomeNode;
    newNode->chromosome = chromosome;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail=head;
    } else {
        tail->next= newNode;
        tail=newNode;
    }
    size++;
}

ChromosomeNode* ChromosomeList::getNodeAt(int index) const {
    if (index < 0 || index >= size) return nullptr;

    ChromosomeNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

int ChromosomeList::getSize() const {
    return size;
}


ChromosomeNode* ChromosomeList::getHead() const {
    return head;
}

ChromosomeNode* ChromosomeList::getTail() const {
    return tail;
}