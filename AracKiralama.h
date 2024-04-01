#ifndef ARACKIRALAMA_H
#define ARACKIRALAMA_H

#include <string>

using namespace std;

class AracKiralama {
private:
    string marka;
    string model;
    int yil;
    double gunlukFiyat;
    bool uygun;
    double motorHacmi;
    string yakitTuru;
    bool kiralanan;
    int kiralananGunSayisi;

public:
    // Constructors
    AracKiralama();
    AracKiralama(string marka, string model, int yil, double gunlukFiyat, bool uygun, double motorHacmi, string yakitTuru);

    // Getter and Setter functions
    string getMarka() const;
    void setMarka(const string& marka);

    string getModel() const;
    void setModel(const string& model);

    int getYil() const;
    void setYil(int yil);

    double getGunlukFiyat() const;
    void setGunlukFiyat(double gunlukFiyat);

    bool uygunMu() const;
    void uygunAta(bool uygun);

    double getMotorHacmi() const;
    void setMotorHacmi(double motorHacmi);

    string getYakitTuru() const;
    void setYakitTuru(const string& yakitTuru);

    bool isKiralanan() const;
    void setKiralanan(bool kiralanan);

    int getKiralananGunSayisi() const;
    void setKiralananGunSayisi(int gunSayisi);

    // Member functions
    void aracKirala(int gunSayisi);
    void aracGeriVer();
    double kiraHesapla(int gunSayisi = 1);

    // Function to show vehicle details
    void aracBilgileriGoster() const;
};

#endif
