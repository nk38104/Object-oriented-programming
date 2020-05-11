#include "Money.h"


Money::Money(int kn, int lp) {
	kuna = kn;
	lipa = lp;
}

void Money::setKuna(const int kn) {
	kuna = kn;
}

int Money::getKuna() const {
	return kuna;
}

void Money::setLipa(const int lp) {
	lipa = lp;
}

int Money::getLipa() const {
	return lipa;
}

Money Money::operator+(const Money& obj2) {
	Money sum;
	sum.kuna = this->kuna + obj2.kuna;
	sum.lipa = this->lipa + obj2.lipa;
	if (sum.lipa > 100) { sum.kuna += 1; sum.lipa -= 100; }
	return sum;
}

Money Money::operator-(const Money& obj2) {
	Money sub;
	sub.kuna = this->kuna - obj2.kuna;
	sub.lipa = this->lipa - obj2.lipa;
	if (sub.lipa < 0) { sub.kuna -= 1; sub.lipa = 100 - sub.lipa; }	
	return sub;
}

Money& Money::operator+=(const Money& obj2) {
	this->kuna += obj2.kuna;
	this->lipa += obj2.lipa;
	if (this->lipa > 100) { this->kuna += 1; this->lipa -= 100; }
	return *this;
}

Money& Money::operator-=(const Money& obj2) {
	this->kuna -= obj2.kuna;
	this->lipa -= obj2.lipa;
	if (this->lipa < 0) { this->kuna -= 1; this->lipa = 100 - this->lipa; }
	return *this;
}

ostream& operator<<(ostream& os, const Money& obj)
{
	os << obj.getKuna() << '.' << obj.getLipa();
	return os;
}

Money& Money::operator++() {
	++(this->kuna);
	return *this;
}

Money Money::operator++(int) {
	Money temp = *this;
	++(*this);
	return temp;
}

Money& Money::operator--() {
	--(this->kuna);
	return *this;
}

Money Money::operator--(int) {
	Money temp = *this;
	--(*this);
	return temp;
}
