#include "pch.h"
#include "Devise.h"
#include <iostream>
using namespace std;
using namespace Banque;

Banque::Devise::Devise(double val)
{
	this->valeur = val;
}

Devise& Banque::Devise::operator+(const Devise& M)
{
	this->valeur = this->valeur + M.valeur;
	return *this;
}

Devise& Banque::Devise::operator-(const Devise& M) 
{
	this->valeur = this->valeur - M.valeur;
	return *this;
}

Devise& Banque::Devise::operator*(const Devise& M)
{
	this->valeur = this->valeur * M.valeur;
	return *this;
}

Devise& Banque::Devise::operator*(double const M)
{
	this->valeur = this->valeur * M;
	return *this;
}

Devise& Banque::Devise::operator/(double const val)
{
	this->valeur = this->valeur / val;
	return *this;
}

bool Banque::Devise::operator<=(const Devise& M) const
{
	return this->valeur <= M.valeur;
}

bool Banque::Devise::operator>=(const Devise& M) const
{
	return this->valeur >= M.valeur;
}

void Banque::Devise::afficher() const
{
	cout << "le solde est : " << this->valeur << endl;
}

double Banque::Devise::convert_to_double(double taux) const
{
	return valeur * taux;
}

bool Banque::Devise::check_moitier(Devise* D) const
{
	if (this->valeur / 2 >= D->valeur)
		return true;
	return false;
}

bool Banque::Devise::check_solde(Devise* M, Devise* N)
{
	if (this->valeur >= (M->valeur + N->valeur))
		return true;
	return false;
}