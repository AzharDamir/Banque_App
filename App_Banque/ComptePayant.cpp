#include "pch.h"
#include "ComptePayant.h"
double Banque::ComptePayant::coutop = 0.05;

Banque::ComptePayant::ComptePayant(Client* c, Devise* m, Devise* M) : CompteCourant(c,m,M)
{
}

bool Banque::ComptePayant::debiter(Devise* M)
{
	return Compte::debiter(& ((*M) * (1 - this->coutop)));
}

void Banque::ComptePayant::crediter(Devise& M)
{
	Compte::crediter(M * (1 + this->coutop));
}

void Banque::ComptePayant::consulter() const
{
	this->Compte::consulter();

}