#pragma once
#include "Nokta.h"

class Daire {
public:
	Daire(const Nokta& nokta1, double r);
	Daire(const Daire& daire1);
	Daire(const Daire& daire1, double x);

	void setdaireNokta(const Nokta& nokta1);
	const Nokta& getdaireNokta();
	void setdaireYaricap(double r);
	double getdaireYaricap();
	void setxDegeri(double x);
	double getxDegeri();
	double alanHesapla();
	double cevreHesapla();
	int kesisimHesapla(Daire daire1);

	string toString();
	void yazdir();

private:
	Nokta nokta;
	double yariCap;
	double xDegeri;
};