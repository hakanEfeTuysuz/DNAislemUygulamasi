/**
* @file DNA.cpp
* @description DNA kaynak dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#include "DNA.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Constructor: Kromozom sayısını sıfırlar
DNA::DNA() {
    chromosomeCount = 0;
}

// Destructor: Bağlı liste (ChromosomeList) otomatik temizlenir
DNA::~DNA() {
}

// DNA.txt dosyasından kromozomları yükler
void DNA::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "HATA: Dosya açilamadi!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        // Her satır bir kromozom
        DoublyLinkedList* newChromosome = new DoublyLinkedList();
        for (char gene : line) {
            if (gene != ' ') { // Boşlukları atla
                newChromosome->append(gene);
            }
        }
        chromosomes.append(newChromosome); // Yeni kromozomu bağlı listeye ekle
        chromosomeCount++;
    }

    file.close();
    cout << "DNA dosyasi basariyla yuklendi. Kromozom sayisi: " << chromosomeCount << endl;
}

// Yeni bir kromozom ekler
void DNA::appendChromosome(DoublyLinkedList* chromosome) {
    chromosomes.append(chromosome);
    chromosomeCount++;
}

// Belirli bir kromozomu döndürür
DoublyLinkedList* DNA::getChromosomeNode(int chromIndex) {
    ChromosomeNode* node = chromosomes.getNodeAt(chromIndex);
    if (node == nullptr) {
        cout << "HATA: Geçersiz kromozom indeksi!" << endl;
        return nullptr;
    }
    return node->chromosome;
}

// Çaprazlama işlemi
void DNA::crossover(int chrom1, int chrom2) {
    // Kromozomları al
    DoublyLinkedList* c1 = getChromosomeNode(chrom1);
    DoublyLinkedList* c2 = getChromosomeNode(chrom2);

    if (c1 == nullptr || c2 == nullptr) {
        cout << "Geçersiz kromozom indeksleri!" << endl;
        return;
    }

    int size1 = c1->getSize();
    int size2 = c2->getSize();

    int mid1 = size1 / 2;
    int mid2 = size2 / 2;

    // Eğer gen sayısı tek ise ortadaki gen dahil edilmez
    Node* c1LeftEnd = c1->getNodeAt(mid1 - 1);       // İlk kromozomun sol kısmı
    Node* c1RightStart = c1->getNodeAt(size1 % 2 == 0 ? mid1 : mid1 + 1); // Sağ kısmı

    Node* c2LeftEnd = c2->getNodeAt(mid2 - 1);       // İkinci kromozomun sol kısmı
    Node* c2RightStart = c2->getNodeAt(size2 % 2 == 0 ? mid2 : mid2 + 1); // Sağ kısmı

    DoublyLinkedList* newC1 = new DoublyLinkedList();
    DoublyLinkedList* newC2 = new DoublyLinkedList();

    // İlk kromozomun sol kısmı + İkinci kromozomun sağ kısmı
    newC1->appendFromTo(c1->getNodeAt(0), c1LeftEnd);
    newC1->appendFromTo(c2RightStart, nullptr);

    // İkinci kromozomun sol kısmı + İlk kromozomun sağ kısmı
    newC2->appendFromTo(c2->getNodeAt(0), c2LeftEnd);
    newC2->appendFromTo(c1RightStart, nullptr);

    // Yeni kromozomları bağlı listeye ekle
    appendChromosome(newC1);
    appendChromosome(newC2);

    cout << "Caprazlama tamamlandi ve yeni kromozomlar eklendi!" << endl;       
}


// Mutasyon işlemi
void DNA::mutate(int chrom, int genePos) {
    DoublyLinkedList* targetChromosome = getChromosomeNode(chrom);
    if (targetChromosome == nullptr) {
        cout << "Geçersiz kromozom indeksi!" << endl;
        return;
    }

    targetChromosome->mutate(genePos); // Hedef kromozomda mutasyon uygula
    cout << "Mutasyon islemi basariyla tamamlandi!" << endl;
}


// Özel yazdırma işlemi
void DNA::printSpecial() const {
    ChromosomeNode* current = chromosomes.getHead();
    while (current != nullptr) {
        DoublyLinkedList* chromosome = current->chromosome;
        char firstGene = chromosome->getNodeAt(0)->gene;
        char smallestGene = firstGene;
        Node* tail = chromosome->getTail();

        // Sağdan sola gezinerek en küçük geni bul
        while (tail != nullptr) {
            if (tail->gene < smallestGene) {
                smallestGene = tail->gene;
                break;
            }
            else tail = tail->prev;
        }

        cout << smallestGene << " ";
        current = current->next;
    }
    cout << endl;
}

// Otomatik işlemleri işler
void DNA::processAutomaticOperations() {
    ifstream file("islemler.txt");
    if (!file.is_open()) {
        cerr << "islemler.txt dosyası açılamadı!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        char operation;
        int index1, index2;

        ss >> operation >> index1 >> index2;
        if (operation == 'C') {
            crossover(index1, index2);
        } else if (operation == 'M') {
            mutate(index1, index2);
        } else {
            cerr << "Geçersiz işlem: " << operation << endl;
        }
    }

    file.close();
    cout << "Tum islemler basariyla tamamlandi!" << endl;
}
