#pragma once
#include"Client.h"
#include "GC.h"
#include "Devise.h"
#include "Operation.h"
class Operation;
namespace Banque {
	class Compte
	{
		//attributs
	private:
		const int numcompte;
		static int count;
		Client* titulaire;//agregation
		Devise* solde;
		static Devise* plafond;
		GC* ref;
		vector<Operation*> historique;//* pour le polymorphisme
		// Methodes
	public:
		Compte(Client*, Devise*); 
		Compte(const Compte&);
		void crediter(Devise& M);
		virtual bool debiter(Devise* M);
		bool verser(Devise* M, Compte& C);
		virtual void consulter()const;
		~Compte();
	protected:
		Devise& pourcentage(double a) const;
		bool checksup(Devise* M) const;
		bool comparerS(Devise*, Devise*);
		bool comparer_moitier(Devise* D);
	};

};