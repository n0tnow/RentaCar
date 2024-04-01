#include "AracKiralama.h"
#include <iostream>

using namespace std;

// Constructors
AracKiralama::AracKiralama() : marka(""), model(""), yil(0), gunlukFiyat(0.0), uygun(false), motorHacmi(0.0), yakitTuru(""), kiralanan(false), kiralananGunSayisi(0) {}

AracKiralama::AracKiralama(string marka, string model, int yil, double gunlukFiyat, bool uygun, double motorHacmi, string yakitTuru)
    : marka(marka), model(model), yil(yil), gunlukFiyat(gunlukFiyat), uygun(uygun), motorHacmi(motorHacmi), yakitTuru(yakitTuru), kiralanan(false), kiralananGunSayisi(0) {}

// Getter and Setter functions
string AracKiralama::getMarka() const {
    return marka;
}

void AracKiralama::setMarka(const string& marka) {
    this->marka = marka;
}

string AracKiralama::getModel() const {
    return model;
}

void AracKiralama::setModel(const string& model) {
    this->model = model;
}

int AracKiralama::getYil() const {
    return yil;
}

void AracKiralama::setYil(int yil) {
    this->yil = yil;
}

double AracKiralama::getGunlukFiyat() const {
    return gunlukFiyat;
}

void AracKiralama::setGunlukFiyat(double gunlukFiyat) {
    if (gunlukFiyat > 0) {
        this->gunlukFiyat = gunlukFiyat;
    } else {
        cerr << "Gecersiz gunluk fiyat!" << endl;
    }
}

bool AracKiralama::uygunMu() const {
    return uygun;
}

void AracKiralama::uygunAta(bool uygun) {
    this->uygun = uygun;
}

double AracKiralama::getMotorHacmi() const {
    return motorHacmi;
}

void AracKiralama::setMotorHacmi(double motorHacmi) {
    this->motorHacmi = motorHacmi;
}

string AracKiralama::getYakitTuru() const {
    return yakitTuru;
}

void AracKiralama::setYakitTuru(const string& yakitTuru) {
    this->yakitTuru = yakitTuru;
}

bool AracKiralama::isKiralanan() const {
    return kiralanan;
}

void AracKiralama::setKiralanan(bool kiralanan) {
    this->kiralanan = kiralanan;
}

int AracKiralama::getKiralananGunSayisi() const {
    return kiralananGunSayisi;
}

void AracKiralama::setKiralananGunSayisi(int gunSayisi) {
    kiralananGunSayisi = gunSayisi;
}

// Member functions
void AracKiralama::aracKirala(int gunSayisi) {
    if (uygun) {
        uygun = false;
        kiralanan = true;
        kiralananGunSayisi = gunSayisi; // Kiralanan gün sayısını ayarla
        cout << "Arac kiralandi." << endl;
        cout << "Kiralanan gun sayisi: " << kiralananGunSayisi << endl;
        cout << "Toplam kira bedeli: " << kiraHesapla(gunSayisi) << " TL" << endl;
    } else {
        cout << "Arac kiralama icin uygun degil." << endl;
    }
}

void AracKiralama::aracGeriVer() {
    if (kiralanan) {
        kiralanan = false;
        uygun = true;
        cout << "Arac geri verildi." << endl;
    } else {
        cout << "Bu arac zaten kiralanmamis." << endl;
    }
}

double AracKiralama::kiraHesapla(int gunSayisi) {
    double toplamFiyat = gunlukFiyat * gunSayisi;
    // 3 gün ve üzeri kiralamalarda %10 indirim yap
    if (gunSayisi >= 3) {
        toplamFiyat *= 0.9; // %10 indirim
    }
    return toplamFiyat;
}

// Function to show vehicle details
void AracKiralama::aracBilgileriGoster() const {
    cout << "Marka: " << marka << endl;
    cout << "Model: " << model << endl;
    cout << "Yil: " << yil << endl;
    cout << "Gunluk Fiyat: " << gunlukFiyat << " TL" << endl;
    cout << "Motor Hacmi: " << motorHacmi << " L" << endl;
    cout << "Yakit Turu: " << yakitTuru << endl;
    if (kiralanan) {
        cout << "Kiralanan gun sayisi: " << kiralananGunSayisi << endl;
    }
}
