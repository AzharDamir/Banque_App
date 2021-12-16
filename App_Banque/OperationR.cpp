#include "pch.h"
#include "OperationR.h"

using namespace Banque;
string OperationR::libel = "-";
Banque::OperationR::OperationR(Devise* montant, Compte* c, Date* d) :Operation(montant, c, d)
{
}

void Banque::OperationR::afficher_op() const
{
	this->afficher_detail();
	cout << libel;
	this->afficher_montant();
	cout << endl;
}