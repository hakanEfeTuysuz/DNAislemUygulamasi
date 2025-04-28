/**
* @file main.cpp
* @description ana dosya
* @course Birinci Öğretim B Gurubu
* @assignment 1. Ödev
* @date 22/11/2024
* @author Hakan Efe Tüysüz hakanefetuysuz@gmail.com
*/
#include <iostream>
#include <fstream>
#include <string>
#include "DNA.hpp" // DNA sınıfını dahil ediyoruz
#include <chrono>

using namespace std;
using namespace std :: chrono;

// Menü gösterim fonksiyonu
void displayMenu() {
    cout << "==== DNA Islemleri Menusu ====" << endl;
    cout << "1. Caprazlama" << endl;
    cout << "2. Mutasyon" << endl;
    cout << "3. Otomatik Islemler" << endl;
    cout << "4. Ekrana Yazdir" << endl;
    cout << "5. Cikis" << endl;
    cout << "Seciminizi yapin: ";
}

int main() {
    DNA dna; // DNA sınıfını oluşturuyoruz

    auto pretime= high_resolution_clock::now();
    // DNA dosyasını yükleme
    dna.loadFromFile("DNA.txt");
    auto aftertime= high_resolution_clock::now();

    auto duration= duration_cast<milliseconds>(aftertime-pretime);
    cout << duration.count()<<endl;

    int choice;
    int chrom1, chrom2, genePos;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Çaprazlama işlemi
                cout << "Caprazlama islemi:" << endl;
                cout << "Ilk kromozom satirini girin: ";
                cin >> chrom1;
                cout << "Ikinci kromozom satirini girin: ";
                cin >> chrom2;
                dna.crossover(chrom1, chrom2); // DNA sınıfı üzerinden çaprazlama yapıyoruz
                cout << "Caprazlama islemi tamamlandi." << endl;
                break;

            case 2: // Mutasyon işlemi
                cout << "Mutasyon islemi:" << endl;
                cout << "Kromozom satir numarasini girin: ";
                cin >> chrom1;
                cout << "Gen pozisyonunu girin: ";
                cin >> genePos;
                dna.mutate(chrom1, genePos); // DNA sınıfı üzerinden mutasyon yapıyoruz
                cout << "Mutasyon islemi tamamlandi." << endl;
                break;

            case 3: // Otomatik işlemler
                cout << "Otomatik islemler:" << endl;
                dna.processAutomaticOperations();
                break;

            case 4: // Özel DNA Yazdırma
                cout << "Ozel Ekrana Yaz:" << endl;
                dna.printSpecial();
                break;
                
            case 5: // Çıkış
                cout << "Programdan cikiliyor..." << endl;
                return 0;

            default: // Hatalı giriş
                cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
                break;
        }
    }

    return 0;
}
