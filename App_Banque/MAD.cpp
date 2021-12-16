#include "pch.h"
#include "MAD.h"
#include "Devise.h"
#include "Euro.h"
#include "Dollar.h"
#include  <iostream>

using namespace std;
using namespace Banque;
double MAD::taux_dechange_dollar = 0.11;
double MAD::taux_dechange_euro = 0.096;
MAD::MAD(double val) :Devise(val)
{
}

void MAD::afficher() const
{
	this->Devise::afficher();
	cout << "MAD" << endl;
}

Dollar& Banque::MAD::convert_to_Dollar()
{
	Dollar* res = new Dollar(this->convert_to_double(taux_dechange_dollar));
	return *res;
}

Euro& Banque::MAD::convert_to_euro()
{
	Euro* res = new Euro(this->convert_to_double(taux_dechange_euro));
	return *res;
}

MAD& Banque::MAD::convert_to_MAD()
{
	return *this;
}

