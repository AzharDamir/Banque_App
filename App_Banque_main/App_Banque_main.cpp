// App_Banque_main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "Devise.h"
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include "Client.h"
#include "Compte.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include "ComptePayant.h"
#include "Date.h"

using namespace Banque;

int main()
{
	Client* c = new Client("Damir", "Azhar", "Mohammedia");
	Devise* solde = new MAD(10000);
	Devise* dec = new Dollar(3000);
	Devise* s2 = new MAD(50000);
	Devise* s3 = new Euro(6000);
	Devise* s4 = new MAD(100);
	Compte* cmp = new CompteCourant(c, solde, dec);
	CompteEpargne* compE = new CompteEpargne(c, s4, 5);

	c->addCompte(cmp);
	cmp->debiter(s4);
	c->addCompte(compE);
	cmp->crediter(*s3);
	cmp->verser(s3, *compE);
	c->Afficher();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
