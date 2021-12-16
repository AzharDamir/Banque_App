#include "pch.h"
#include "Client.h"
#include"Compte.h"
using namespace Banque;
using namespace std;
Banque::Client::Client(string n, string p, string a)
{
	this->nom = n;
	this->prenom = p;
	this->adresse = a;
	this->list_compts = vector<Compte*>();
}

void Banque::Client::Afficher() const
{
	cout << "nom :" << this->nom << "\n" << "prenom:" << this->prenom << "\n" << "Adresse:" << this->adresse << endl;
	cout << "les comptes :" << endl;

	for (int i = 0; i < this->list_compts.size(); i++)
	{
		this->list_compts[i]->consulter();
	}
}

void Banque::Client::addCompte(Compte* c)
{
	this->list_compts.push_back(c);
}
