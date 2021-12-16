#include "pch.h"
#include "CompteCourant.h"
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include <assert.h>
using namespace Banque;
Banque::CompteCourant::CompteCourant(Client* c, Devise* solde, Devise* decou) :Compte(c, solde)
{
	assert(*solde >= *decou);
	this->decouverte = decou;
}

bool Banque::CompteCourant::debiter(Devise* d)
{
	bool val = false;
	if (typeid(*(this->decouverte)) == typeid(MAD))
		val = this->comparerS(&d->convert_to_MAD(), CompteCourant::decouverte);
	if (typeid(*(this->decouverte)) == typeid(Euro))
		val = this->comparerS(&d->convert_to_euro(), CompteCourant::decouverte);
	if (typeid(*(this->decouverte)) == typeid(Dollar))
		val = this->comparerS(&d->convert_to_Dollar(), CompteCourant::decouverte);
	if (val == true)
	{
		this->Compte::debiter(d);
		return true;
	}
	return false;
}

void Banque::CompteCourant::consulter() const
{
	this->Compte::consulter();
}
