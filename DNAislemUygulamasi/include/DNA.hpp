/**
* @file DNA.hpp
* @description DNA başlık dosyası
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#ifndef DNA_HPP
#define DNA_HPP

#include "ChromosomeList.hpp" // Yeni bağlı liste
#include "DoublyLinkedList.hpp"

class DNA {
public:
    DNA();
    ~DNA();
    void loadFromFile(const char* filename);         // DNA.txt dosyasını yükler
    void appendChromosome(DoublyLinkedList* chromosome); // Kromozom ekler
    void crossover(int chrom1, int chrom2);          // Çaprazlama işlemi
    void mutate(int chrom, int genePos);             // Mutasyon işlemi
    void printSpecial() const;                       // Özel bir çıktı üretir
    void processAutomaticOperations();               // Otomatik işlemleri gerçekleştirir
    DoublyLinkedList* getChromosomeNode(int chromIndex);

private:
    ChromosomeList chromosomes;                      // Kromozomları tutan bağlı liste
    int chromosomeCount;                             // Kromozom sayısı
};

#endif // DNA_HPP
