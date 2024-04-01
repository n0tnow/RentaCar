#include <iostream>
#include "AracKiralama.h"

using namespace std;

const int MAX_ARAC_SAYISI = 5;

void kiralananAraclariGoster(AracKiralama araclar[], int aracSayisi);

int main() {
    AracKiralama araclar[MAX_ARAC_SAYISI] = {
        AracKiralama("Toyota", "Corolla", 2020, 150.0, true, 1.6, "Benzin"),
        AracKiralama("Renault", "Clio", 2021, 120.0, true, 1.2, "Benzin"),
        AracKiralama("Ford", "Focus", 2019, 180.0, false, 1.5, "Dizel"),
        AracKiralama("Volkswagen", "Golf", 2022, 200.0, true, 1.8, "Benzin"),
        AracKiralama("Audi", "A4", 2023, 250.0, true, 2.0, "Benzin")
    };

    int secim;
    do {
        cout << "------ Arac Kiralama Menusu ------" << endl;
        cout << "1. Araclari Listele" << endl;
        cout << "2. Arac Kirala" << endl;
        cout << "3. Kiralanan Arac Bilgilerini Goster" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
            case 1:
                cout << "------ Araclar ------" << endl;
                for (int i = 0; i < MAX_ARAC_SAYISI; ++i) {
                    cout << "Arac " << i + 1 << ":" << endl;
                    araclar[i].aracBilgileriGoster();
                    cout << endl;
                }
                break;
            case 2:
                int aracIndex;
                int gunSayisi;
                cout << "Kiralamak istediginiz aracin numarasini girin (1-" << MAX_ARAC_SAYISI << "): ";
                cin >> aracIndex;
                aracIndex--; // Kullanıcıya 1'den başlayan indeks numaralarını gösterirken, diziler 0'dan başlar, bu yüzden indeksi 1 azaltıyoruz.

                if (aracIndex >= 0 && aracIndex < MAX_ARAC_SAYISI) {
                    cout << "Kac gun kiralamak istiyorsunuz: ";
                    cin >> gunSayisi;
                    if (gunSayisi <= 0) {
                        cout << "Gecersiz gun sayisi!" << endl;
                        break;
                    }
                    araclar[aracIndex].aracKirala(gunSayisi);
                } else {
                    cout << "Gecersiz arac numarasi!" << endl;
                }
                break;
            case 3:
                kiralananAraclariGoster(araclar, MAX_ARAC_SAYISI);
                break;
            case 4:
                cout << "Programdan cikiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim!" << endl;
                break;
        }
    } while (secim != 4);

    return 0;
}

void kiralananAraclariGoster(AracKiralama araclar[], int aracSayisi) {
    cout << "------ Kiralanan Arac Bilgileri ------" << endl;
    bool kiralananVarMi = false;
    for (int i = 0; i < aracSayisi; ++i) {
        if (araclar[i].isKiralanan()) {
            araclar[i].aracBilgileriGoster();
            kiralananVarMi = true;
        }
    }
    if (!kiralananVarMi) {
        cout << "Kiralanan arac bulunmamaktadir." << endl;
    }
}
