#include "pch.h"
#include "OperationA.h"

using namespace Banque;
string OperationA::libel = "+";
Banque::OperationA::OperationA( Devise* montant, Compte* c,Date* d):Operation(montant,c,d)
{
}

void Banque::OperationA::afficher_op() const
{
	this->afficher_detail();
	cout << libel;
	this->afficher_montant();
	cout << endl;
}
