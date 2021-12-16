#include "pch.h"
#include "Euro.h"
#include "Dollar.h"
#include "Devise.h"
#include "MAD.h"
#include <iostream>
using namespace std;
using namespace Banque;
double Euro::taux_DeChange_Mad = 10.43;
double Euro::taux_DeChange_dollar = 1.13;

Banque::Euro::Euro(double val) :Devise(val)
{
}

void Banque::Euro::afficher() const
{
	this->Devise::afficher();
	cout << "Euro" << endl;
}

MAD& Banque::Euro::convert_to_MAD()
{
	MAD* res = new MAD(this->convert_to_double(taux_DeChange_Mad));
	return *res;
}

Dollar& Banque::Euro::convert_to_Dollar()
{
	Dollar* res = new Dollar(this->convert_to_double(taux_DeChange_dollar));
	return *res;
}

Euro& Banque::Euro::convert_to_euro()
{
	return *this;
}
