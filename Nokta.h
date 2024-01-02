#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::string;

class Nokta {
public:

	Nokta();
	Nokta(double xy);
	Nokta(double x, double y);
	Nokta(const Nokta& nokta);
	Nokta(const Nokta& nokta, double ofset_x, double ofset_y);

	void setX(double x);
	double getX() const;
	void setY(double y);
	double getY() const;
	void set(double x, double y);
	string toString() const;
	void yazdir();

private:
	double koordinatX;
	double koordinatY;
};


