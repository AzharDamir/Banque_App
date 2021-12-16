#pragma once
#include "Compte.h"
namespace Banque {
    class CompteEpargne :
        public Compte
    {
    private:
        double tauxInter;
    public:
        bool debiter(Devise* M);
        CompteEpargne(Client* c, Devise* d, double T);
        void calculInteret();
        void consulter() const override;
    };
}