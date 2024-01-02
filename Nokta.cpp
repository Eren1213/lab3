#include "Nokta.h"

Nokta::Nokta() { // Parametresiz yapıcı. (Apsis 0 Ordinat 0)
	setX(0);
	setY(0);
}

Nokta::Nokta(double xy) { // Tek parametreli yapıcı. (Apsis = Ordinat)
	setX(xy);
	setY(xy);
}

Nokta::Nokta(double x, double y) { // 2 parametreli yapıcı. (Apsis = x, Ordinat = y)
	setX(x);
	setY(y);
}

Nokta::Nokta(const Nokta& nokta) { // Başka bir nokta alan yapıcı.
	setX(nokta.koordinatX);
	setY(nokta.koordinatY);
}

Nokta::Nokta(const Nokta& nokta, double ofset_x, double ofset_y) { // Başka bir nokta ve ofset alan yapıcı.
	setX(nokta.koordinatX + ofset_x);
	setY(nokta.koordinatY + ofset_y);
}



void Nokta::setX(double x) {
	koordinatX = x;
}

double Nokta::getX() const {
	return koordinatX;
}

void Nokta::setY(double y) {				// Set, get fonksiyonları.
	koordinatY = y;
}

double Nokta::getY() const {
	return koordinatY;
}

void Nokta::set(double x, double y) {
	setX(x);
	setY(y);
}

string Nokta::toString() const { // Koordinatları stringe çeviren toString metodu.
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")" + "\n";
}

void Nokta::yazdir() { // Ekrana koordinatları yazdırma metodu.
	cout << toString();
}
