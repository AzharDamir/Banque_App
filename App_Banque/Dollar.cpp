#include "pch.h"
#include "Dollar.h"
#include "MAD.h"
#include "Euro.h"
#include <iostream>
using namespace std;
using namespace Banque;

double Dollar::taux_DeChange_Mad = 9.25;
double Dollar::taux_DeChange_euro = 0.89;

Banque::Dollar::Dollar(double val) :Devise(val)
{
}

void Banque::Dollar::afficher() const
{
	Devise::afficher();
	cout << "Dollar" << endl;
}

MAD& Banque::Dollar::convert_to_MAD() 
{
	MAD* res = new MAD(this->convert_to_double(taux_DeChange_Mad));
	return *res;
	// TODO: insérer une instruction return ici
}

Dollar& Banque::Dollar::convert_to_Dollar()
{
	return *this;
}

Euro& Banque::Dollar::convert_to_euro()
{
	Euro* res = new Euro(this->convert_to_double(taux_DeChange_euro));
	return *res;
}
