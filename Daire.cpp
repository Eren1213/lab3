#include "Daire.h"

Daire::Daire(const Nokta& nokta1, double r) {
	setdaireNokta(nokta1);
	setdaireYaricap(r);
}

Daire::Daire(const Daire& daire1) {
	setdaireNokta(daire1.nokta);
	setdaireYaricap(daire1.yariCap);
}

Daire::Daire(const Daire& daire1, double x) {
	setdaireNokta(daire1.nokta);
	setxDegeri(x);
	setdaireYaricap(daire1.yariCap * x);
}

void Daire::setdaireNokta(const Nokta& nokta1) {
	nokta = nokta1;
}

const Nokta& Daire::getdaireNokta() {
	return nokta;
}

void Daire::setdaireYaricap(double r) {
	yariCap = r;
}

double Daire::getdaireYaricap() {
	return yariCap;
}

void Daire::setxDegeri(double x) {
	xDegeri = x;
}

double Daire::getxDegeri() {
	return xDegeri;
}

double Daire::alanHesapla() { // Dairenin alanı.
	double alan = 3.14 * yariCap * yariCap;
	return alan;
}

double Daire::cevreHesapla() { // Dairenin çevresi.
	double cevre = 2 * 3.14 * yariCap;
	return cevre;
}

int Daire::kesisimHesapla(Daire daire1) { // Dairelerin kesişip kesişmediği kontrolü.
	if (daire1.getdaireYaricap() < getdaireYaricap()) {
		return 0;
	}
	else if (daire1.getdaireYaricap() == getdaireYaricap()) {
		return 1;
	}
	else {
		return 2;
	}
}

string Daire::toString() {
	return "Merkez Nokta: " + getdaireNokta().toString() + " Yarıçap: " + std::to_string(getdaireYaricap()) + "\n";
}

void Daire::yazdir() {
	cout << toString();
}