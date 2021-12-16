#include "pch.h"
#include "Operation.h"
#include "Devise.h"
#include <iostream>
using namespace std;
using namespace  Banque;
int Operation::cpt = 0;
Banque::Operation::Operation(Devise* d, Compte* c, Date* date) :num(++cpt)
{
	this->montant = d;
	this->c = c;
	this->date = date;
}
void Banque::Operation::afficher_detail() const
{
	this->date->afficher();
	cout << "le numero de l'operation: " << num << endl;
}

void Banque::Operation::afficher_montant() const
{
	montant->afficher();
}

Banque::Operation::~Operation()
{
	delete montant;
}


