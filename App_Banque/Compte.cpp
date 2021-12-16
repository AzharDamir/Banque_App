#include "pch.h"
#include "Compte.h"
#include "OperationA.h"
#include "OperationR.h"
#include <vector>
#include "MAD.h"
#include "Euro.h"
#include "Dollar.h"
#include<iostream>
using namespace std;
using namespace Banque;

Devise* Compte::plafond = new MAD(2000);
int Compte::count = 0;

Banque::Compte::Compte(Client* titu, Devise* sol) :numcompte(++count)
{
	this->titulaire = titu;
	this->solde = sol;
	this->historique = vector<Operation*>();
}

void Banque::Compte::crediter(Devise& M)
{
	if(typeid(*(this->solde))==typeid(MAD))
		this->solde->operator+(M.convert_to_MAD());
	if (typeid(*(this->solde)) == typeid(Dollar))
		this->solde->operator+(M.convert_to_Dollar());
	if (typeid(*(this->solde)) == typeid(Euro))
		this->solde->operator+(M.convert_to_euro());
	Date* d = new Date();
	Operation* op = new OperationA(&M,this,d );
	this->historique.push_back(op);
}

bool Banque::Compte::debiter(Devise* M)
{
	if ( M->convert_to_MAD() <= *(Compte::plafond))
	{
		if (typeid(*(this->solde)) == typeid(MAD))
		{
			if(*(this->solde) >= M->convert_to_MAD())
				this->solde->operator-(M->convert_to_MAD());
		}
		if (typeid(*(this->solde)) == typeid(Dollar))
		{
			if (*(this->solde) >= M->convert_to_Dollar())
				this->solde->operator-(M->convert_to_Dollar());
		}
		if (typeid(*(this->solde)) == typeid(Euro))
		{
			if (*(this->solde) >= M->convert_to_euro())
				this->solde->operator-(M->convert_to_euro());
		}
		
		Date* d = new Date();
		Operation* op = new OperationR(M,this, d);
		this->historique.push_back(op);
		return true;
	}
	return false;
}

Banque::Compte::Compte(const Compte& c) :numcompte(c.numcompte)
{
	this->ref = c.ref;
	this->ref->incre();
	this->titulaire = c.titulaire;

}

bool Banque::Compte::verser(Devise* M, Compte& C)
{
	this->solde->afficher();
	if (this->debiter(M) == true) {
		this->solde->afficher();
		C.crediter(*M);
		C.solde->afficher();
		return true;
	}
	return false;
}

bool Banque::Compte::comparerS(Devise* M, Devise* N)
{
	return this->solde->check_solde(M, N);
}

bool Banque::Compte::comparer_moitier(Devise* D)
{
	if (typeid(*(this->solde)) == typeid(MAD))
		return this->solde->check_moitier(&D->convert_to_MAD());
	else
		if (typeid(*(this->solde)) == typeid(Euro))
			return this->solde->check_moitier(&D->convert_to_euro());
		else
			if (typeid(*(this->solde)) == typeid(Dollar))
				return this->solde->check_moitier(&D->convert_to_Dollar());
}

void Banque::Compte::consulter() const
{
	cout << "num compte=" << this->numcompte << endl;
	this->solde->afficher();
	//cout << "titulaire " << endl;
	//this->titulaire->Afficher();
	cout << "historique des operations" << endl;
	for (int i = 0; i < this->historique.size(); i++)
	{
		this->historique[i]->afficher_op();
	}
}

Compte::~Compte() {

	if (this->titulaire != nullptr && this->ref->decr() == 0)
	{
		delete this->titulaire;
		this->titulaire = nullptr;
	}
}

Devise& Banque::Compte::pourcentage(double a) const
{
	 return (*this->solde) * a;
}

bool Banque::Compte::checksup(Devise* M) const
{
	return *(this->solde) >= *M;
}

