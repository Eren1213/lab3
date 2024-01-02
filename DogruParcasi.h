#pragma once
#include "Nokta.h"

class DogruParcasi {
public:
	DogruParcasi(const Nokta nokta1, const Nokta nokta2);
	DogruParcasi(const DogruParcasi& parca);
	DogruParcasi(const Nokta& nokta3, double uzunluk, double egim);

	double uzunluk();

	Nokta kesisimNoktasi(const Nokta& nokta4);
	Nokta ortaNoktaBul();
	string toString();

	void yazdir();
	void setilkNokta(const Nokta& nokta1);
	const Nokta& getilkNokta();
	void setikinciNokta(const Nokta& nokta2);
	const Nokta& getikinciNokta();
	void setortaNokta(const Nokta& nokta3);
	const Nokta& getortaNokta();
	void setdogruParcasiUzunluk(double uzunluk);
	double getdogruParcasiUzunluk();
	void setdogruParcasiEgim(double egim);
	double getdogruParcasiEgim();

private:
	Nokta ilkNokta;
	Nokta ikinciNokta;
	Nokta ortaNokta;
	double dogruParcasiUzunluk;
	double dogruParcasiEgim;

};