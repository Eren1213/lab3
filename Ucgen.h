#pragma once
#include "Nokta.h"
#include "DogruParcasi.h"
class Ucgen {
public:
	Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

	void setNoktalar(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3);

	Nokta getNokta1();
	Nokta getNokta2();
	Nokta getNokta3();

	double alan();
	double cevre();
	double* acilar();
	string toString();
	void yazdir();

private:
	Nokta ucgeNokta1;
	Nokta ucgeNokta2;
	Nokta ucgeNokta3;
	double dogru1Uzunluk;
	double dogru2Uzunluk;
	double dogru3Uzunluk;
};