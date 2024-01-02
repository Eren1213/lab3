#include "DogruParcasi.h"


DogruParcasi::DogruParcasi(const Nokta nokta1, const Nokta nokta2) { // İki uç noktayı parametre alan yapıcı.
	setilkNokta(nokta1);
	setikinciNokta(nokta2);
	setortaNokta(ortaNoktaBul());
}

DogruParcasi::DogruParcasi(const DogruParcasi& parca) { // Başka bir doğru parçası alan yapıcı.
	setilkNokta(parca.ilkNokta);
	setikinciNokta(parca.ikinciNokta);
}

DogruParcasi::DogruParcasi(const Nokta& nokta3, double uzunluk, double egim) { // Orta nokta, uzunluk ve eğim alan yapıcı.
	setortaNokta(nokta3);
	setdogruParcasiUzunluk(uzunluk);
	setdogruParcasiEgim(egim);
	// ilkNokta ve ikinciNoktayı hesaplayacak formül. (Başlangıç ve bitiş noktası.)
	double dogruParcasiAci = atan(egim);
	ilkNokta.set(nokta3.getX() - uzunluk / 2 * cos(dogruParcasiAci), nokta3.getY() - uzunluk / 2 * sin(dogruParcasiAci));
	ikinciNokta.set(nokta3.getX() + uzunluk / 2 * cos(dogruParcasiAci), nokta3.getY() + uzunluk / 2 * sin(dogruParcasiAci));
}

double DogruParcasi::uzunluk() { // Doğru parçasının uzunluğunu bulan metod.
	double uzunlukX = std::pow(std::fabs(ilkNokta.getX() - ikinciNokta.getX()), 2);
	double uzunlukY = std::pow(std::fabs(ilkNokta.getY() - ikinciNokta.getY()), 2);
	return sqrt(std::fabs(uzunlukX + uzunlukY));
}

Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta4) { // Kesişim noktalarını bulan metod.
	// Eğim (m) = y2-y1/x2-x1

	// Doğru parçasının üzerindeki iki nokta arasındaki doğru denklemi: y = mx + b

	double m = (ikinciNokta.getY() - ilkNokta.getY()) / (ikinciNokta.getX() - ilkNokta.getX());

	// Sabit sayıyı hesapla.
	double b = ilkNokta.getY() - m * ilkNokta.getX();

	// Y'yi hesapla.
	double y_kesişim = m * nokta4.getX() + b;

	Nokta kesisim_noktasi(nokta4.getX(), y_kesişim);
	return kesisim_noktasi;
}

Nokta DogruParcasi::ortaNoktaBul() { // Doğru parçasının orta noktasını bulan metod.
	Nokta orta_nokta((ilkNokta.getX() + ikinciNokta.getX()) / 2.0, (ilkNokta.getY() + ikinciNokta.getY()) / 2.0);
	return orta_nokta;
}

string DogruParcasi::toString() { // Doğru parçasının noktalarını stringe dönüştüren metod.
	return "(" + std::to_string(ilkNokta.getX()) + ", " + std::to_string(ilkNokta.getY()) + ") (" + std::to_string(ikinciNokta.getX()) + ", " + std::to_string(ikinciNokta.getY()) + ")" + "\n";
}

void DogruParcasi::yazdir() {
	cout << toString();
}

void DogruParcasi::setilkNokta(const Nokta& nokta1) {
	ilkNokta = nokta1;
}

const Nokta& DogruParcasi::getilkNokta() {
	return ilkNokta;
}

void DogruParcasi::setikinciNokta(const Nokta& nokta2) {
	ikinciNokta = nokta2;
}

const Nokta& DogruParcasi::getikinciNokta() {
	return ikinciNokta;
}

void DogruParcasi::setortaNokta(const Nokta& nokta3) {           // Set, get fonksiyonları.
	ortaNokta = nokta3;
}

const Nokta& DogruParcasi::getortaNokta() {
	return ortaNokta;
}

void DogruParcasi::setdogruParcasiUzunluk(double uzunluk) {
	if (uzunluk > 0) {
		dogruParcasiUzunluk = uzunluk;
	}
	else {
		cout << "Uzunluk 0'dan büyük olmalı.";
	}
}

double DogruParcasi::getdogruParcasiUzunluk() {
	return dogruParcasiUzunluk;
}

void DogruParcasi::setdogruParcasiEgim(double egim) {
	dogruParcasiEgim = egim;
}

double DogruParcasi::getdogruParcasiEgim() {
	return dogruParcasiEgim;
}
