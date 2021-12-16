#include "pch.h"
#include "CompteEpargne.h"
#include <assert.h>
bool Banque::CompteEpargne::debiter(Devise* M)
{
	if (!this->comparer_moitier(M)) return false;
	this->Compte::debiter(M);
	return true;
}
Banque::CompteEpargne::CompteEpargne(Client* c, Devise* d, double T) :Compte(c, d)
{
	assert(T > 0 && T <= 100);
	this->tauxInter = T;
}

void Banque::CompteEpargne::calculInteret()
{
	float a = this->tauxInter / 100;
	this->crediter(this->pourcentage(a));
}

void Banque::CompteEpargne::consulter() const
{
	this->Compte::consulter();
}
