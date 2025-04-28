/**
* @file ChromosomeList.hpp
* @description ChromosomeList başlık dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#ifndef CHROMOSOMELIST_HPP
#define CHROMOSOMELIST_HPP

#include "DoublyLinkedList.hpp"

// Kromozomları tutacak düğüm yapısı
struct ChromosomeNode {
    DoublyLinkedList* chromosome; // Her düğüm bir kromozom tutar
    ChromosomeNode* next;         // Bir sonraki düğüme işaretçi
};

// Kromozomları bağlayan liste
class ChromosomeList {
public:
    ChromosomeList();
    ~ChromosomeList();

    void append(DoublyLinkedList* chromosome); // Yeni kromozom ekler
    ChromosomeNode* getNodeAt(int index) const; // Belirli pozisyondaki düğümü döndürür
    int getSize() const; // Liste büyüklüğünü döndürür
    ChromosomeNode* getHead() const; // Listenin başındaki düğümü döndürür
    ChromosomeNode* getTail() const;

private:
    ChromosomeNode* head; // Listenin ilk düğümü
    int size;             // Liste büyüklüğü
    ChromosomeNode* tail;
};

#endif // CHROMOSOMELIST_HPP
