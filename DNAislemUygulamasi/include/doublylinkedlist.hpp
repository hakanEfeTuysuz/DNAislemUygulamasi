/**
* @file doublylinkedlist.hpp
* @description doublylinkedlist başlık dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

// Node yapısı, her bir genin depolanacağı düğüm için
struct Node {
    char gene;      // Kromozomun genini tutan karakter
    Node* next;     // Bir sonraki düğüme işaretçi
    Node* prev;     // Bir önceki düğüme işaretçi
};

// DoublyLinkedList sınıfı, bağlı listeyi temsil eder
class DoublyLinkedList {
public:
    // Constructor
    DoublyLinkedList();
    // Destructor
    ~DoublyLinkedList();

    // Listeye yeni gen ekler
    void append(char gene);

    // Listeyi baştan sona yazdırır
    void printForward() const;

    // Listeyi sondan başa yazdırır
    void printBackward() const;

    // Mutasyon işlemi
    void mutate(int genePos);

    // Belirli pozisyondaki düğümü döndürür
    Node* getNodeAt(int position) const;

    // Liste boyutunu döndürür
    int getSize() const;

    // Tail düğümüne erişim için bir getter
    Node* getTail() const;

    // Belirli bir aralıktan düğümleri ekler
    void appendFromTo(Node* from, Node* to);

private:
    Node* head;      // Listenin ilk düğümü
    Node* tail;      // Listenin son düğümü
    int listSize;    // Liste büyüklüğü
};

#endif // DOUBLYLINKEDLIST_HPP
