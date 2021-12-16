#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

namespace Banque {
	class Devise;
	class Compte;
	class Operation
	{
	private:
		const int num;
		static int cpt;
		Devise* montant;
		Date* date;
		Compte* c;
	public:
		Operation(Devise* valeur, Compte* c, Date* date);
		void afficher_detail() const;
		void afficher_montant() const;
		virtual void afficher_op() const = 0;
		~Operation();
	};
}
