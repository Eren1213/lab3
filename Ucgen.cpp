#include "Ucgen.h"

Ucgen::Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3) {
    setNoktalar(nokta1, nokta2, nokta3);
    DogruParcasi dogru1(nokta1, nokta2);
    DogruParcasi dogru2(nokta1, nokta3);
    DogruParcasi dogru3(nokta2, nokta3);
    dogru1Uzunluk = dogru1.uzunluk();
    dogru2Uzunluk = dogru2.uzunluk();
    dogru3Uzunluk = dogru3.uzunluk();
}

void Ucgen::setNoktalar(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3) {
    ucgeNokta1.set(nokta1.getX(), nokta1.getY());
    ucgeNokta2.set(nokta2.getX(), nokta2.getY());
    ucgeNokta3.set(nokta3.getX(), nokta3.getY());
}

Nokta Ucgen::getNokta1() {
    return ucgeNokta1;
}

Nokta Ucgen::getNokta2() {
    return ucgeNokta2;
}

Nokta Ucgen::getNokta3() {
    return ucgeNokta3;
}

double Ucgen::alan() {
    double yarimCevre = cevre() / 2;
    double ucgenAlan = sqrt(yarimCevre * (yarimCevre - dogru1Uzunluk) * (yarimCevre - dogru2Uzunluk) * (yarimCevre - dogru3Uzunluk));
    return ucgenAlan;
}

double Ucgen::cevre() {
    return (dogru1Uzunluk + dogru2Uzunluk + dogru3Uzunluk);
}

double* Ucgen::acilar() {
    // Açıları hesaplamak için kosinüs teoremi. (a^2 = b^2 + c^2 - 2.b.c.cos(a))
    double aci1 = acos((pow(dogru1Uzunluk, 2) - pow(dogru2Uzunluk, 2.0) - pow(dogru3Uzunluk, 2)) / (2 * dogru2Uzunluk * dogru3Uzunluk));
    double aci2 = acos((pow(dogru2Uzunluk, 2) - pow(dogru1Uzunluk, 2.0) - pow(dogru3Uzunluk, 2)) / (2 * dogru1Uzunluk * dogru3Uzunluk));
    double aci3 = acos((pow(dogru3Uzunluk, 2) - pow(dogru1Uzunluk, 2.0) - pow(dogru2Uzunluk, 2)) / (2 * dogru1Uzunluk * dogru2Uzunluk));

    double* acilar = new double[3] { aci1, aci2, aci3 };
    return acilar;
}

string Ucgen::toString() {
    return "Üçgen: \n" + getNokta1().toString() + getNokta2().toString() + getNokta3().toString() + "\n";
}

void Ucgen::yazdir() {
    cout << toString();
}
